/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** linked_list
*/

#include "minishell_1.h"

list_t *create_list(char *data)
{
    int i = 0;
    list_t *list;

    list = malloc(sizeof(list_t) * 1);
    list->variable = data;
    for (; data[i] != '='; i += 1);
    list->values = my_str_to_word_array(&data[i - 1], ':');
    list->next = NULL;
    list->previous = NULL;
    return (list);
}

void list_free(list_t *node)
{
    free(node->variable);
    for (int i = 0; node->values[i]; i += 1)
        free(node->values[i]);
    free(node->values);
    free(node);
}

void remplace_node(list_t *list, char *s1, char *s2)
{
    if (s2) {
        list->variable = my_super_str_cat
            (my_super_str_cat(s1, "=\0"), s2);
        list->values = my_str_to_word_array(list->variable, ':');
    }
    else
        list->variable = my_super_str_cat(s1, "=\0");
}

void delete_node(list_t *list)
{
    list_t *next = list->next;
    list_t *previous = list->previous;

    if (previous)
        previous->next = list->next;
    if (next)
        next->previous = list->previous;
}

void add_node(list_t *list, char *data)
{
    list_t *tempo = list;
    list_t *fill = list;
    int i = 0;

    while (tempo->next != NULL)
        tempo = tempo->next;
    tempo->next = malloc(sizeof(list_t) * 1);
    tempo->next->variable = data;
    for (; data[i] != '=' && data[i]; i += 1);
    if (data[i]) {
        tempo->next->values = my_str_to_word_array(&data[i - 1], ':');
        tempo->next->next = NULL;
        tempo->next->previous = tempo;
    }
    while (fill) {
        fill->last = tempo->next;
        fill = fill->next;
    }
}