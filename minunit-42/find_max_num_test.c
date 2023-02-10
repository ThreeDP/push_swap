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

MU_TEST(try_find_max_num_in_list_65_should_be_65)
{
    // ARRANGE
    char    **numbers = ft_split("65", ' ');
    t_stack *stack = create_stack(numbers);
    int     expected_max_num    = 65;
    int     result_max_num;

    // ACT
    result_max_num = find_max_num(stack);

    // ASSERT
    mu_assert_int_eq(expected_max_num, result_max_num);
    unset(numbers, stack);
}

MU_TEST(try_find_max_num_in_list_65_10_should_be_65)
{
    // ARRANGE
    char    **numbers = ft_split("65 10", ' ');
    t_stack *stack = create_stack(numbers);
    int     expected_max_num    = 65;
    int     result_max_num;

    // ACT
    result_max_num = find_max_num(stack);

    // ASSERT
    mu_assert_int_eq(expected_max_num, result_max_num);
    unset(numbers, stack);
}

MU_TEST(try_find_max_num_in_list_65_10_75_should_be_75)
{
    // ARRANGE
    char    **numbers = ft_split("65 10 75", ' ');
    t_stack *stack = create_stack(numbers);
    int     expected_max_num    = 75;
    int     result_max_num;

    // ACT
    result_max_num = find_max_num(stack);

    // ASSERT
    mu_assert_int_eq(expected_max_num, result_max_num);
    unset(numbers, stack);
}

MU_TEST(try_find_max_num_in_list_65_10_75_1_100_minus_1000_9999_27_32_47_should_be_9999)
{
    // ARRANGE
    char    **numbers = ft_split("65 10 75 1 100 -1000 9999 27 32 47", ' ');
    t_stack *stack = create_stack(numbers);
    int     expected_max_num    = 9999;
    int     result_max_num;

    // ACT
    result_max_num = find_max_num(stack);

    // ASSERT
    mu_assert_int_eq(expected_max_num, result_max_num);
    unset(numbers, stack);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(try_find_max_num_in_list_65_should_be_65);
    MU_RUN_TEST(try_find_max_num_in_list_65_10_should_be_65);
    MU_RUN_TEST(try_find_max_num_in_list_65_10_75_should_be_75);
    MU_RUN_TEST(try_find_max_num_in_list_65_10_75_1_100_minus_1000_9999_27_32_47_should_be_9999);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

