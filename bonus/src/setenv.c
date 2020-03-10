/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** setenv
*/

#include "minishell_1.h"

int manage_env(list_t *list, char **params, int *k)
{
    list_t *node;

    *k = 1;
    if (!(node = get_env(list, my_super_str_cat(params[1], "=\n"))))
        add_node(list, my_super_str_cat(params[1], "=\0"));
    else
        remplace_node(node, params[1], NULL);
    return (1);
}

char *get_name(char *command)
{
    command[my_strlen(command) - 1] = 0;
    return (command);
}

void manage_quotes(list_t *env, char **params, char *command)
{
    char *name = NULL;

    name = get_name(&command[my_strlen(params[0])
    + my_strlen(params[1]) + 3]);
    add_node(env, my_super_str_cat
    (my_super_str_cat(params[1], "=\0"), name));
}

int new_node(list_t *env, char **params, char *command, int quotes)
{
    if (quotes == 0)
        add_node(env, my_super_str_cat
        (my_super_str_cat(params[1], "=\0"), params[2]));
    if (quotes == 2) {
        if (params[2][0] != '"' || command[my_strlen(command) - 1] != '"')
            return (0);
        else
            manage_quotes(env, params, command);
    }
    return 1;
}

int my_set_env(list_t *env, char **params, char *command, int *k)
{
    int quotes = 0;
    list_t *node;

    *k = 1;
    for (int i = 0; command[i]; i += 1)
        if (command[i] == '"')
            quotes += 1;
    if (print_error(quotes, params, command))
        return 0;
    if (!(node = get_env(env, my_super_str_cat(params[1], "=\n"))))
        return (new_node(env, params, command, quotes));
    else {
        if (quotes == 0)
            remplace_node(node, params[1], params[2]);
        if (quotes == 2)
            remplace_node(node, params[1], get_name(
            &command[my_strlen(params[0]) + my_strlen(params[1]) + 3]));
    }
    return (1);
}