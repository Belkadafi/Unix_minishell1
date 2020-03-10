/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** test_parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell_1.h"

Test(parse, should_return_nothing)
{
    char *com = "\n";
    cr_assert_not_null(parse(com, NULL));
}

Test(error_management, I_do_not_know)
{
    error_management(139);
    cr_redirect_stdout();
    cr_assert_stdout_eq_str("Segmentation Fault");
}

Test(execute, should_do_smthng)
{
    char *com = "/bin/ls";
    cr_assert_not_null(execute(com, NULL, NULL, NULL));
}

Test(my_cd, yes)
{
    cr_assert_eq(my_cd(NULL, NULL, NULL, 0), 1);
}