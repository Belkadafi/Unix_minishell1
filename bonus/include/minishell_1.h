/*
** EPITECH PROJECT, 2020
** minishell_1
** File description:
** minishell_1
*/

#ifndef MINISHELL_1_H_
#define MINISHELL_1_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct list_s
{
    char *variable;
    char **values;
    struct list_s *next;
    struct list_s *previous;
    struct list_s *last;
} list_t;

#include "my.h"

#endif /* !MINISHELL_1_H_ */