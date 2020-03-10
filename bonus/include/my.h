/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes
*/

#include "my_printf.h"
#include "minishell_1.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup (int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char * my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase (char *str);
char *my_strlowcase (char *str);
char *my_strcapitalize (char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const * str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_strlen2(char *str);
int fs_open_file(char const *filepath);
void my_print_char(va_list ap, int, char, int *);
void my_print_nbr(va_list ap, int, char, int *);
void my_print_str(va_list ap, int, char, int *);
void my_print_unsigned(va_list ap, int, char, int *);
void my_print_octal(va_list ap, int, char, int *);
void my_print_hexa(va_list ap, int, char, int *);
void my_print_hexa_capitalize(va_list ap, int, char, int *);
void my_print_pointer_adress(va_list ap, int, char, int *);
void my_print_binary(va_list ap, int test, char thing, int *n);
void my_print_show_char(va_list ap, int test, char thing, int *n);
void my_print_len(va_list ap, int test, char thing, int *n);
void my_print_nb_error(va_list ap, int test, char thing, int *n);
void my_print_error(va_list ap, int test, char thing, int *n);
int my_printf(char const *format, ...);
char **my_str_to_word_array(char const *str, char separator);
char *my_super_str_cat(char *s1, char *s2);
char *get_next_line(int fd);
int check_str(char *str);
list_t *get_env(list_t *env, char *base);
char *check_cmd(char *str);
int is_path(char *str);
int is_built_in(char *str);
void add_node(list_t *list, char *data);
list_t *create_list(char *data);
void remplace_node(list_t *list, char *s1, char *s2);
int my_built_in(char *command, char **params, list_t *env, char *str);
int my_set_env(list_t *env, char **params, char *command, int *);
int print_error(int quotes, char **params, char *command);
int manage_env(list_t *list, char **params, int *);
int my_cd(char **params, list_t *list, int *, int);
void delete_node(list_t *list);
void handle_sig(int i);
char *parser(char **tempo, char *command, list_t *tab, char *filepath);
char *parse(char *str, list_t *env);
int cd_vanilla(list_t *list, int j);
char *parse(char *str, list_t *env);
char **update_env(list_t *list, char **env);
void error_management(int test);
void exec_error(char *path);
int execute(char *path, char *str, list_t *list, char **env);