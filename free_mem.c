#include "shell.h"

/**
 *
 */
void free_dp(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (command[i] == NULL)
		free(command[i]);
	free(command);
}


/**
 *
 */
void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}