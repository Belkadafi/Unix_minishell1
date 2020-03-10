/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** error_management
*/

#include "minishell_1.h"

int is_good(char *str)
{
    if (str[0] < 'a' && str[0] > 'z' &&
    str[0] < 'A' && str[0] > 'Z' && str[0] != '_' ) {
        my_printf("%s", "setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int i = 1; str[i];) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' &&
        str[i] <= '9') || str[i] == '_')
            i += 1;
        else {
            my_printf("%s", "setenv: Variable name must"
            " contain alphanumeric characters.\n");
            return 0;
        }
    }
    return (1);
}

int check_params(char *command)
{
    int test = 0;
    int count = 0;

    for (int i = 0; command[i]; i += 1) {
        if (command[i] == '"')
            test += 1;
        if (test % 2 == 0 && command[i] == ' ')
            count += 1;
    }
    if (count > 2) {
        my_printf("%s", "setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}

int print_error(int quotes, char **params, char *command)
{
    char c = '"';

    if (!is_good(params[1]))
        return (1);
    if (quotes % 2 != 0) {
        my_printf("%s", "Unmatched ");
        write (1, "'", 1);
        write (1, &c, 1);
        write (1, "'", 1);
        my_printf("%s", ".\n");
        return (1);
    }
    return (check_params(command));
}