/*
** EPITECH PROJECT, 2020
** mini_shell_1
** File description:
** env_management
*/

#include "minishell_1.h"

list_t *get_env(list_t *env, char *base)
{
    list_t *tempo = env;
    int i = 0;

    while (tempo) {
        if (my_strncmp(tempo->variable,
        my_super_str_cat(base, "="), my_strlen(base)
        - ((my_strlen(base) == 1) ? 0 : 1)) == 0)
            return (tempo);
        tempo = tempo->next;
        i += 1;
    }
    return (NULL);
}
