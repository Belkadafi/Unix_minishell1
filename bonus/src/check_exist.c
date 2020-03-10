/*
** EPITECH PROJECT, 2020
** minishell_1
** File description:
** check_exist
*/

#include "minishell_1.h"

int is_path(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == '/')
            return (1);
    return (0);
}

int is_built_in(char *str)
{
    char *tab[] = {"/env", "/setenv", "/unsetenv", "/cd", NULL};

    for (int i = 0; tab[i]; i += 1) {
        if (my_strcmp(tab[i], str) == 0)
            return 1;
    }
    return 0;
}

char *check_cmd(char *str)
{
    if (my_strcmp(str, "exit") == 0) {
        if (isatty(0))
            my_printf("exit\n");
        exit(0);
    }
    return (str);
}

int check_str(char *str)
{
    if (str[0] == '.' || str[0] == '/')
        return (1);
    return (0);
}