/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include "minishell_1.h"

int quotes(char *command, int *simple, int *doubl)
{
    for (int i = 0; command[i]; i += 1) {
        if (command[i] == 39)
            *simple += 1;
        if (command[i] == '"')
            *doubl += 1;
    }
    return (*simple % 2 == 1 || *doubl % 2 == 1);
}

char *get_command(void)
{
    char *last = "";
    char *command = NULL;
    int simple = 0;
    int doubl = 0;

    do {
        if (simple % 2 != 0)
            my_printf("<s-quotes  $>");
        if (simple % 2 != 0 && doubl % 2 != 0)
            my_printf("  and  ");
        if (doubl % 2 != 0)
            my_printf("<d-quotes  $>");
        simple = 0;
        doubl = 0;
        command = get_next_line(0);
        if (!command)
            return NULL;
        last = my_super_str_cat(last, my_super_str_cat(" ", command));
    } while (quotes(last, &simple, &doubl));
    return (last);
}

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
        com = get_command();
    } while ((path = parse(com, list)) && (execute(path, com, list, env) != 0)
    && (env = update_env(list, env)));
    if (isatty(0))
        my_printf("exit\n");
}