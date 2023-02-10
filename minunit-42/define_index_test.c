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

void    loop_stack_next(int *indexs, int *nums, t_stack *s)
{
    int     i;

    i = 0;
    if (!s)
        return ;
    while (s)
    {
        //printf("\na: %i\t%c\n", s->num, s->stack);
        mu_assert_int_eq(indexs[i], s->index);
        mu_assert_int_eq(nums[i], s->num);
        i++;
        if (!s->next)
            break ;
        s = s->next;
    }
}

MU_TEST(try_pass_one_number_65_should_be_index_0)
{
    // ARRANGE
    char    **numbers = ft_split("65", ' ');
    int     expected_stack_num[] = {65};
    int     expected_stack_index[] = {0};
    t_stack *stack = create_stack(numbers);

    // ACT
    define_index(stack);

    // ASSERT
    loop_stack_next(expected_stack_index, expected_stack_num, stack);
    unset(numbers, stack);
}

MU_TEST(try_pass_one_number_65_10_should_be_index_1_0)
{
    // ARRANGE
    char    **numbers = ft_split("65 10", ' ');
    int     expected_stack_num[] = {65, 10};
    int     expected_stack_index[] = {1, 0};
    t_stack *stack = create_stack(numbers);

    // ACT
    define_index(stack);

    // ASSERT
    loop_stack_next(expected_stack_index, expected_stack_num, stack);
    unset(numbers, stack);
}

MU_TEST(try_pass_one_number_65_25_67_10_45_1_7_19_6_100_should_be_index_7_5_8_3_6_0_2_4_1_10)
{
    // ARRANGE
    char    **numbers = ft_split("65 25 67 10 45 1 7 19 6 100", ' ');
    int     expected_stack_num[] = {65, 25, 67, 10, 45, 1, 7, 19, 6, 100};
    int     expected_stack_index[] = {7, 5, 8, 3, 6, 0, 2, 4, 1, 9};
    t_stack *stack = create_stack(numbers);

    // ACT
    define_index(stack);

    // ASSERT
    loop_stack_next(expected_stack_index, expected_stack_num, stack);
    unset(numbers, stack);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(try_pass_one_number_65_should_be_index_0);
    MU_RUN_TEST(try_pass_one_number_65_10_should_be_index_1_0);
    MU_RUN_TEST(try_pass_one_number_65_25_67_10_45_1_7_19_6_100_should_be_index_7_5_8_3_6_0_2_4_1_10);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

