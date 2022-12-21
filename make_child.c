#include "shell.h"

/**
 *
 */
void make_child(char **command, char *name, char **env)
{
	int pid = 0;
	int status = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
	}
	else if (pid == 0)
	{
		execution(command, name, env);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}