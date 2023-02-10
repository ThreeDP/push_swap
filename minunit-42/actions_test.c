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

void    loop_stack_back(int *exp, t_stack *s, char *stack)
{
    int i;

    i = 0;
    if (!(!s->next && s->stack == 'b'))
        s = s->back;
    while (s && s->stack == 'b')
    {
        //printf("\nb: %i\t%c\n", s->num, s->stack);
        mu_assert_int_eq(stack[i], s->stack);
        mu_assert_int_eq(exp[i], s->num);
        i++;
        if (!s->back)
            break ;
        s = s->back;
    }
}

MU_TEST(try_swap_stack_a)
{
    // ARRANGE
    char    **numbers = ft_split("3 2 67 10 45", ' ');
    int     expected_stack_a[] = {2, 3, 67, 10, 45};
    int     *expected_stack_b = NULL;
    char    stack_a_flag[] = "aaaaa";
    char    stack_b_flag[] = "";
    t_stack *stack = create_stack(numbers);

    // ACT
    swap_a(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_two_numbers_for_stack_b_and_swap_b)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("3 2 67 10 45", ' ');
    int     expected_stack_a[] = {67, 10, 45};
    char    stack_a_flag[] = "aaa";
    int     expected_stack_b[] = {3, 2};
    char    stack_b_flag[] = "bb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    swap_b(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_two_numbers_for_stack_b_and_swap_b_than_push_again_for_a)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {25, 65, 67, 10, 45};
    int     *expected_stack_b = NULL;
    char    stack_a_flag[] = "aaaaa";
    char    stack_b_flag[] = "";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    swap_b(stack);
    push_a(&stack);
    push_a(&stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_passing_all_elements_and_one_more_for_stack_b_and_than_push_all_and_one_more_again_for_a)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {65, 25, 67, 10, 45};
    int     *expected_stack_b = NULL;
    char    stack_a_flag[] = "aaaaa";
    char    stack_b_flag[] = "";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_a(&stack);
    push_a(&stack);
    push_a(&stack);
    push_a(&stack);
    push_a(&stack);
    push_a(&stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_passing_all_elements_and_the_stack_b_than_print_a_and_b)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     *expected_stack_a = NULL;
    int     expected_stack_b[] = {45, 10, 67, 25, 65};
    char    stack_a_flag[] = "";
    char    stack_b_flag[] = "bbbbb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_passing_one_num_for_b_rotate_a)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {67, 10, 45, 25};
    int     expected_stack_b[] = {65};
    char    stack_a_flag[] = "aaaa";
    char    stack_b_flag[] = "b";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    rotate_a(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_b_twice_and_swap_b)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {67, 10, 45};
    int     expected_stack_b[] = {65, 25};
    char    stack_a_flag[] = "aaa";
    char    stack_b_flag[] = "bb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    swap_b(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_b_5_times_and_swap_b)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     *expected_stack_a = NULL;
    int     expected_stack_b[] = {10, 45, 67, 25, 65};
    char    stack_a_flag[] = "";
    char    stack_b_flag[] = "bbbbb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    swap_b(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_swap_ab)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {45, 10};
    int     expected_stack_b[] = {25, 67, 65};
    char    stack_a_flag[] = "aa";
    char    stack_b_flag[] = "bbb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    swap_ab(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_rotate_a_two_times)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {67, 10, 45, 65, 25};
    int     *expected_stack_b = NULL;
    char    stack_a_flag[] = "aaaaa";
    char    stack_b_flag[] = "";
    t_stack *stack = create_stack(numbers);

    // ACT
    rotate_a(stack);
    rotate_a(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_rotate_b_two_times)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     *expected_stack_a = NULL;
    int     expected_stack_b[] = {67, 25, 65, 45, 10};
    char    stack_a_flag[] = "";
    char    stack_b_flag[] = "bbbbb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    rotate_b(stack);
    rotate_b(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_b_twice_and_rotate_ab)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {10, 45, 67};
    int     expected_stack_b[] = {65, 25};
    char    stack_a_flag[] = "aaa";
    char    stack_b_flag[] = "bb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    rotate_ab(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_reverse_rotate_a_two_times)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {10, 45, 65, 25, 67};
    int     *expected_stack_b = NULL;
    char    stack_a_flag[] = "aaaaa";
    char    stack_b_flag[] = "";
    t_stack *stack = create_stack(numbers);

    // ACT
    reverse_rotate_a(stack);
    reverse_rotate_a(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_reverse_rotate_b_two_times)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     *expected_stack_a = NULL;
    int     expected_stack_b[] = {25, 65, 45, 10, 67};
    char    stack_a_flag[] = "";
    char    stack_b_flag[] = "bbbbb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    push_b(&stack);
    reverse_rotate_b(stack);
    reverse_rotate_b(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST(try_push_b_twice_and_reverse_rotate_ab)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("65 25 67 10 45", ' ');
    int     expected_stack_a[] = {45, 67, 10};
    int     expected_stack_b[] = {65, 25};
    char    stack_a_flag[] = "aaa";
    char    stack_b_flag[] = "bb";
    t_stack *stack = create_stack(numbers);

    // ACT
    push_b(&stack);
    push_b(&stack);
    reverse_rotate_ab(stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack, stack_b_flag);
    unset(numbers, stack);
}

MU_TEST_SUITE(test_suite) {	
	MU_RUN_TEST(try_swap_stack_a);
    MU_RUN_TEST(try_push_two_numbers_for_stack_b_and_swap_b);
    MU_RUN_TEST(try_push_two_numbers_for_stack_b_and_swap_b_than_push_again_for_a);
    MU_RUN_TEST(try_passing_all_elements_and_one_more_for_stack_b_and_than_push_all_and_one_more_again_for_a);
    MU_RUN_TEST(try_passing_all_elements_and_the_stack_b_than_print_a_and_b);
    MU_RUN_TEST(try_passing_one_num_for_b_rotate_a);
    MU_RUN_TEST(try_push_b_twice_and_swap_b);
    MU_RUN_TEST(try_push_b_5_times_and_swap_b);
    MU_RUN_TEST(try_swap_ab);
    MU_RUN_TEST(try_rotate_a_two_times);
    MU_RUN_TEST(try_rotate_b_two_times);
    MU_RUN_TEST(try_push_b_twice_and_rotate_ab);
    MU_RUN_TEST(try_reverse_rotate_a_two_times);
    MU_RUN_TEST(try_reverse_rotate_b_two_times);
    MU_RUN_TEST(try_push_b_twice_and_reverse_rotate_ab);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

