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
    int i;

    i = 0;
    while (s && s->stack == 'a')
    {
        printf("\na: %i\n", s->num);
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
    while (s && s->stack == 'b')
    {
        printf("\nb: %i\n", s->num);
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
    int     i = 0;
    char    **numbers = ft_split("3 2 67 10 45", ' ');
    char    expected_stack[] = "aaaaa";
    int     expected_result[] = {2, 3, 67, 10, 45};
    t_stack *stack = create_stack(numbers);
    t_stack *back = NULL;

    // ACT
    swap_a(stack);

    // ASSERT
    while (stack)
    {
        mu_assert(back == stack->back, "pointer erro in the back");
        mu_assert_int_eq(expected_stack[i], stack->stack);
        mu_assert_int_eq(expected_result[i], stack->num);
        i++;
        back = stack;
        if (!stack->next)
            break ;
        stack = stack->next;
    }
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
    swap_b(stack->back);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack->back, stack_b_flag);
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
    swap_b(stack->back);
    push_a(&stack);
    push_a(&stack);

    // ASSERT
    loop_stack_next(expected_stack_a, stack, stack_a_flag);
    loop_stack_back(expected_stack_b, stack->back, stack_b_flag);
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
    loop_stack_back(expected_stack_b, stack->back, stack_b_flag);
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

MU_TEST_SUITE(test_suite) {	
	MU_RUN_TEST(try_swap_stack_a);
    MU_RUN_TEST(try_push_two_numbers_for_stack_b_and_swap_b);
    MU_RUN_TEST(try_push_two_numbers_for_stack_b_and_swap_b_than_push_again_for_a);
    MU_RUN_TEST(try_passing_all_elements_and_one_more_for_stack_b_and_than_push_all_and_one_more_again_for_a);
    MU_RUN_TEST(try_passing_all_elements_and_the_stack_b_than_print_a_and_b);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

