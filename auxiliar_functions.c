#include "shell.h"

/**
 *
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 *
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;
	return (len);
}


/**
 *
 */
char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}


/**
 *
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;
	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}


/**
 *
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s + '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (null_flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
