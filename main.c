#include "shell.h"

/**
 *
 */
int main(int __attribute__((unused))ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;

	while (1)
	{
		prompt();
		signal(SIGINT, control_c);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenizer(buffer, " ");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else
				make_child(command, av[0], env);
		}
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 *
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Luisa_Shell>> ", 13);
}

/**
 *
 */
void control_c(int __attribute__((unused))signals)
{
	write(STDOUT_FILENO, "\nLuisa_Shell>> ", 14);
}

/**
 *
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * 
 */
void shell_exit(char **command)
{
	int count = 0;

	if (command[1] == NULL)
	{
		free_commands(command);
		exit(EXIT_SUCCESS);
	}
	count = _atoi(command[1]);
	free_commands(command);
	exit(count);
}
