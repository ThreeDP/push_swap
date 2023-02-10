#include "minunit.h"
#include "../srcs/push_swap.h"
#include <stdio.h>

void    unset(char **numbers, t_stack *stack)
{
    int     i;

    i = 0;
    while (numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
    clear_stack(&stack, free);
}

void    loop_stack_next(int *exp, t_stack *s, char *stack)
{
    int     i;

    i = 0;
    if (!s)
        return ;
    while (s && s->stack == 'a')
    {
        //printf("\na: %i\t%c\n", s->num, s->stack);
        mu_assert_int_eq(stack[i], s->stack);
        mu_assert_int_eq(exp[i], s->num);
        i++;
        if (!s->next)
            break ;
        s = s->next;
    }
}

MU_TEST(try_pass_one_number_65_for_radix_should_be_65)
{
    // ARRANGE
    char    **numbers = ft_split("65", ' ');
    int     expected_stack_a[] = {65};
    int     items = 1;
    char    stack_a_flag[] = "a";
    t_stack *stack = create_stack(numbers);

    // ACT
    radix_sort(stack, items);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    unset(numbers, stack);
}

MU_TEST(try_pass_65_10_for_radix_should_be_10_65)
{
    // ARRANGE
    char    **numbers = ft_split("65 10", ' ');
    int     expected_stack_a[] = {10, 65};
    int     items = 2;
    char    stack_a_flag[] = "aa";
    t_stack *stack = create_stack(numbers);

    // ACT
    radix_sort(stack, items);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    unset(numbers, stack);
}

MU_TEST(try_pass_65_25_67_10_45_1_7_19_6_100_should_be_1_6_7_10_19_25_45_65_67_100)
{
    // ARRANGE
    char    **numbers = ft_split("65 25 67 10 45 1 7 19 6 100", ' ');
    int     expected_stack_a[] = {1, 6, 7, 10, 19, 25, 45, 65, 67, 100};
    int     items = 10;
    char    stack_a_flag[] = "aaaaaaaaaa";
    t_stack *stack = create_stack(numbers);

    // ACT
    radix_sort(stack, items);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    unset(numbers, stack);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(try_pass_one_number_65_for_radix_should_be_65);
    MU_RUN_TEST(try_pass_65_10_for_radix_should_be_10_65);
    MU_RUN_TEST(try_pass_65_25_67_10_45_1_7_19_6_100_should_be_1_6_7_10_19_25_45_65_67_100);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

