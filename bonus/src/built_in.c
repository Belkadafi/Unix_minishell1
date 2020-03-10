/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** built_in
*/

#include "minishell_1.h"

int my_unsetenv(char **params, list_t *env, int *k)
{
    list_t *node;

    *k = 1;
    if (!params[1]) {
        my_printf("%s", "unsetenv: Too few arguments.\n");
        return (1);
    }
    node = get_env(env, params[1]);
    if (node)
        delete_node(node);
    return (1);
}

int my_built_in(char *command, char **params, list_t *list, char *str)
{
    list_t *env = list;
    int exists = 0;

    if (my_strcmp(command, "env") == 0 ||
    (my_strcmp(command, "setenv") == 0 && !params[1]))
        while (env) {
            my_printf("%s\n", env->variable);
            env = env->next;
            exists = 1;
        }
    else if (my_strcmp(command, "setenv") == 0)
        (params[2]) ? my_set_env(env, params, str, &exists)
        : manage_env(env, params, &exists);
    if (my_strcmp(command, "cd") == 0)
        my_cd(params, env, &exists, 1);
    if (my_strcmp(command, "unsetenv") == 0)
        my_unsetenv(params, env, &exists);
    if (exists == 0)
        my_printf("%s%s", params[0], ": Command not found.\n");
    return (1);
}