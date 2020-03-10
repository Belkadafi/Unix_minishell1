/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** parsing
*/

#include "minishell_1.h"

char *parser(char **tempo, char *command, list_t *env, char *filepath)
{
    list_t *tab;

    if (check_str(tempo[0]))
        return (tempo[0]);
    command = my_super_str_cat("/\0", tempo[0]);
    tab = get_env(env, "PATH=");
    if (!tab)
        return (check_cmd(tempo[0]));
    tab->values = my_str_to_word_array(&tab->variable[5], ':');
    for (int i = 0; tab->values[i]; i += 1)
        if (access(my_super_str_cat(tab->values[i], command), X_OK) == 0 &&
        !(is_built_in(command))) {
            filepath = my_super_str_cat(tab->values[i], command);
            return (filepath);
        }
    return (check_cmd(tempo[0]));
}

char *parse(char *str, list_t *env)
{
    char **tempo = NULL;
    char *command = NULL;
    char *filepath = NULL;

    if ((!str || my_strlen(str) == 0) || !env)
        return (str);
    for (int i = 0; str[i]; i += 1)
        if (str[i] == '\t')
            str[i] = ' ';
    tempo = my_str_to_word_array(str, ' ');
    return (parser(tempo, command, env, filepath));
}