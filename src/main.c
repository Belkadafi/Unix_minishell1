/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include "minishell_1.h"

int main(int ac, char **av, char **env)
{
    char *com = malloc(2);
    char *path;
    list_t *list = create_list(env[0]);

    av[ac] = NULL;
    if (env)
        for (int i = 1; env[i]; i += 1)
            add_node(list, env[i]);
    cd_vanilla(list, 0);
    my_cd(NULL, list, &ac, 0);
    do {
        free(com);
        if (isatty(0))
            my_printf("$> ");
        signal(SIGINT, handle_sig);
        com = get_next_line(0);
    } while ((path = parse(com, list)) && (execute(path, com, list, env) != 0)
    && (env = update_env(list, env)));
    if (isatty(0))
        my_printf("exit\n");
}