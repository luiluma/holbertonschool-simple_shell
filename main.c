#include "shell.h"

/**
 *
 */
int main(int __attribute__((unused))ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;

	while (1)
	{
		prompt();
		signal(SIGINT, control_c);
		chars_read = getline(&buffer, &buf_size, stdin);
		if (chars_read == EOF)
			_EOF();
		if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenizer(buffer, " ");
			if (_strcmp(command[0], "exit") != 0)
				shell_exit();
			else
				make_child(command, av[0], env);
		}
		buffer = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 *
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Luisa_Shell_$ ", 14);
}

/**
 *
 */
void control_c(int __attribute__((unused))signals)
{
	write(STDOUT_FILENO, "\nLuisa_Shell_$ ", 15);
}

/**
 *
 */
void _EOF(void)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}

/**
 * 
 */
void shell_exit(void)
{
	exit(EXIT_SUCCESS);/*revisar exit_success*/
}