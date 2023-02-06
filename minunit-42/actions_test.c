#include "minunit.h"
#include "../srcs/push_swap.h"
#include <stdio.h>

MU_TEST(try_swap_stack_a)
{
    // ARRANGE
    int     i = 0;
    char    **numbers = ft_split("3 2 67 10 45", ' ');
    int     expected_result[] = {2, 3, 67, 10, 45};
    t_stack *stack = create_stack(numbers);

    // ACT
    swap_a(stack);

    // ASSERT
    while (stack)
    {
        mu_assert_int_eq(expected_result[i], stack->num);
        i++;
        stack = stack->next;
    }
}

MU_TEST_SUITE(test_suite) {	
	MU_RUN_TEST(try_swap_stack_a);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

