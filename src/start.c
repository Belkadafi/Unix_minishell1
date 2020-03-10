    /*
** EPITECH PROJECT, 2020
** minishell_1
** File description:
** main
*/

#include "minishell_1.h"

void error_management(int test)
{
    int sig = WTERMSIG(test);

    wait(&test);
    sig = WTERMSIG(test);
    if (sig == 8) {
        strsignal(sig);
        my_printf("%s", "Floating exception");
        if (__WCOREDUMP(test))
            my_printf(" (core dumped)");
        my_printf("\n");
    }
    else if (sig != 0) {
        my_printf("%s", strsignal(sig));
        if (__WCOREDUMP(test))
            my_printf(" (core dumped)");
        my_printf("\n");
    }
}

void exec_error(char *path)
{
    if (errno == ENOEXEC)
        my_printf("%s%s", path, ": Exec format error. Wrong Architecture.\n");
    else if (access(path, X_OK) != 0)
        my_printf("%s%s", path, ": Command not found.\n");
    else
        my_printf("%s: %s.\n", path, strerror(errno));
    exit(84);
}

int execute(char *path, char *str, list_t *list, char **env)
{
    int test = 0;
    int nb = 0;
    char **flags = my_str_to_word_array(str, ' ');

    if (!env) {
        my_printf("%s%s", str, ": Command not found.\n");
        return (1);
    }
    if (my_strlen(path) == 0)
        return (1);
    if (!is_path(path))
        return (my_built_in(path, flags, list, str));
    for (; flags[nb]; nb += 1);
    if (fork() == 0) {
        execve(path, flags, env);
        exec_error(path);
    }
    error_management(test);
    return (1);
}

char **update_env(list_t *list, char **env)
{
    list_t *tmp = list;
    int len = 0;
    int index = 0;

    while (tmp) {
        len += 1;
        tmp = tmp->next;
    }
    tmp = list;
    env = malloc(sizeof(char *) * (len + 1));
    for (; index < len; index += 1) {
        env[index] = malloc(sizeof(char) * (my_strlen(tmp->variable) + 1));
        my_strcpy(env[index], tmp->variable);
        tmp = tmp->next;
    }
    env[index] = NULL;
    return (env);
}