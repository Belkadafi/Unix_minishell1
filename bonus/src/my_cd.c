/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** my_cd
*/

#include "minishell_1.h"

int cd_vanilla(list_t *list, int j)
{
    static char home_name[4096];
    list_t *node = NULL;

    if (j == 0)
        return (1);
    if (chdir("/home") == -1)
        my_printf("%s: No such file or directory.\n", home_name);
    node = get_env(list, "PWD=");
    if (node) {
        node->variable = my_super_str_cat("PWD=", home_name);
        node->values = my_str_to_word_array(&node->variable[4], ':');
    }
    return (1);
}

void handle_sig(int i)
{
    i += 1;
    my_printf("\n$> ");
}

void manage_error(char **params)
{
    struct stat st;

    if (stat(params[1], &st) == -1)
        my_printf("%s: No such file or directory.\n", params[1]);
    else
        my_printf("%s: %s.\n", params[1], strerror(errno));
}

int my_cd_2(char **params, char last_name[4096], list_t *current, char *name)
{
    if (my_strcmp(params[1], "-") == 0) {
        if (chdir(last_name) == -1)
            my_printf("%s: No such file or directory.\n", last_name);
    }
    else if (params[1] != NULL)
        if (chdir(params[1]) == -1) {
            manage_error(params);
            return (0);
        }
    for (int i = 0; i < 4096; i += 1)
        last_name[i] = 0;
    for (int i = 0; name[i]; i += 1)
        last_name[i] = name[i];
    getcwd(name, 4096);
    current->variable = my_super_str_cat("PWD=", name);
    current->values = my_str_to_word_array(&current->variable[4], ':');
    return (1);
}

int my_cd(char **params, list_t *list, int *k, int j)
{
    static char last_name[4096];
    list_t *current = get_env(list, "PWD=");
    char *name = malloc(sizeof(char) * 4096);

    *k = 1;
    getcwd(name, 4096);
    if (j == 0) {
        for (int i = 7; name[i]; i += 1)
            last_name[i] = name[i];
        return (1);
    }
    if (!params[1]) {
        for (int i = 0; i < 4096; last_name[i] = name[i], i += 1);
        return (cd_vanilla(list, 1));
    }
    return (my_cd_2(params, last_name, current, name));
}