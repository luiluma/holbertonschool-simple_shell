#include "shell.h"

/**
 *
 */
char **tokenizer(char *buffer, const char *s)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);
	bufsize = _strlen(buffer);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_commands(commands);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, s);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_commands(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}


/**
 *
 */
void make_child(char **command, char *name, char **env)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execution(command, name, env);
		free_commands(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(command);
		}
		free_commands(command);
	}
}
