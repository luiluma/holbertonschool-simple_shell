#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*      Main       */

int main(int ac, char **av, char **env);
void prompt(void);
void control_c(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);

/*        Execution        */

void execution(char **command, char *name, char **env);
char **_getPATH(char **env);
void msgerror(char **command);

/*          Tokenizer and Make child       */

char **tokenizer(char *buffer, const char *s);
void make_child(char **command, char *name, char **env);


/*      Free Memory       */


void free_commands(char **command);
void free_exit(char **command);


/*     Auxiliar_Functions      */


int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

/*       END      */

#endif
