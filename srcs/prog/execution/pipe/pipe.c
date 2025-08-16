#include "minishell.h"

// Close all pipe file descriptors safely
static void close_all_pipes(int pipes[][2], int pipe_count)
{
    for (int i = 0; i < pipe_count; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
}

// Kill previously forked children in case of error to avoid zombies
static void kill_children(pid_t *pids, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (pids[i] > 0)
            kill(pids[i], SIGKILL);
    }
}

// Wait for all children and update exit status from last command
static void wait_for_children(t_minishell *ms, pid_t *pids, int cmd_count)
{
    int status;
    pid_t pid;

    for (int i = 0; i < cmd_count; i++)
    {
        pid = waitpid(pids[i], &status, 0);
        if (pid == pids[cmd_count - 1])
        {
            if (WIFEXITED(status))
                ms->exit_code = WEXITSTATUS(status);
            else if (WIFSIGNALED(status))
                ms->exit_code = 128 + WTERMSIG(status);
        }
    }
}

// --- Child process: set up pipes, redirection, execute command ---
static void run_child(t_minishell *ms, t_command *cmd, int pipes[][2], int idx, int cmd_count)
{
	char **argv;
    setup_signals_child();
    if (idx > 0 && dup2(pipes[idx - 1][0], STDIN_FILENO) < 0)
    {
        perror("dup2 stdin");
        close_all_pipes(pipes, cmd_count - 1);
        ft_exit(ms, "dup2 stdin failed", 1);
    }
    if (idx < cmd_count - 1 && dup2(pipes[idx][1], STDOUT_FILENO) < 0)
    {
        perror("dup2 stdout");
        close_all_pipes(pipes, cmd_count - 1);
        ft_exit(ms, "dup2 stdout failed", 1);
    }
    close_all_pipes(pipes, cmd_count - 1);
    if (main_redirection(ms) != 0)
        ft_exit(ms, "main_redirection failed", 1);
    if (is_command_empty(cmd))
        ft_exit(ms, "Command is empty", 0);
    if (is_builtin(cmd))
    {
        compare_commands(ms);
        ft_exit(ms, "Built-in command executed", ms->exit_code);
    }
    else
    {
		argv = cmd->argv;
		cmd->argv = NULL;
		if (ms->cmd)
			free_commands(ms);
        execute_external_command(ms, argv);
        ft_exit(ms, "execve failed", 1);
    }
}

// --- Create all pipes for N commands: N-1 pipes ---
static int create_all_pipes(int pipes[][2], int pipe_count)
{
    int i;

    i = 0;
    while (i < pipe_count)
    {
        if (pipe(pipes[i]) < 0)
        {
            perror("pipe");
            close_all_pipes(pipes, i);
            return -1;
        }
        i++;
    }
    return 0;
}

// --- Fork each child process for each command ---
static int fork_children(t_minishell *ms, int pipes[][2], pid_t *pids, int cmd_count)
{
    t_command *cmd = ms->cmd;

    for (int i = 0; i < cmd_count && cmd; i++, cmd = cmd->next)
    {
        pids[i] = fork();
        if (pids[i] < 0)
            return (i);
        if (pids[i] == 0)
            run_child(ms, cmd, pipes, i, cmd_count);
    }
    return (cmd_count);
}

// --- Parent closes pipes and waits for children ---
static void handle_parent_process(t_minishell *ms, int pipes[][2], pid_t *pids, int cmd_count)
{
    signal(SIGQUIT, handlequit);
    signal(SIGINT, handle_c);
    close_all_pipes(pipes, cmd_count - 1);
    wait_for_children(ms, pids, cmd_count);
    free_simple_resources(ms);
    setup_signals_parent();
}

// --- Allocate pipes and pids arrays ---
static int allocate_resources(int cmd_count, int (**pipes)[2], pid_t **pids)
{
    *pipes = malloc(sizeof(int[2]) * (cmd_count - 1));
    *pids = malloc(sizeof(pid_t) * cmd_count);
    if (!*pipes || !*pids)
    {
        perror("malloc");
        free(*pipes);
        free(*pids);
        return (-1);
    }
    return (0);
}

// --- Cleanup on fork failure ---
static void cleanup_on_fork_failure(t_minishell *ms, pid_t *pids, int forked, int pipes[][2], int pipe_count)
{
    ms->exit_code = EXIT_FAILURE;
    kill_children(pids, forked);
    for (int j = 0; j < forked; j++)
        waitpid(pids[j], NULL, 0);
    close_all_pipes(pipes, pipe_count);
    free(pids);
    free(pipes);
}

// --- Setup pipes, fork children ---
static int setup_and_fork(t_minishell *ms, int cmd_count, int (**pipes)[2], pid_t **pids)
{
    if (allocate_resources(cmd_count, pipes, pids) < 0)
        return (-1);
    if (create_all_pipes(*pipes, cmd_count - 1) < 0)
    {
        free(*pipes);
        free(*pids);
        return (-1);
    }
    int forked = fork_children(ms, *pipes, *pids, cmd_count);
    if (forked < cmd_count)
    {
        cleanup_on_fork_failure(ms, *pids, forked, *pipes, cmd_count - 1);
        return (-1);
    }
    return (0);
}

// --- Main function to execute piped commands ---
void execute_piped_commands(t_minishell *ms, int cmd_count)
{
    if (cmd_count < 2)
        return;
    if (setup_and_fork(ms, cmd_count, &ms->pipes, &ms->pids) < 0)
    {
        ms->exit_code = EXIT_FAILURE;
        ft_exit(ms, "Failed to set up pipes or fork children", EXIT_FAILURE);
    }
    handle_parent_process(ms, ms->pipes, ms->pids, cmd_count);
}
