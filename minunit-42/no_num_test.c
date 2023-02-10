#include "minunit.h"
#include "../srcs/push_swap.h"

MU_TEST(try_pass_A_should_be_0)
{
    // ARRANGE
    char        *arg = "A";
    int         expected_result = 0;
    int         result;

    // ACT
    result = no_num(arg);

    // ASSERT
    mu_assert_int_eq(expected_result, result);
}

MU_TEST(try_pass_MIN_INT_should_be_10)
{
    // ARRANGE
    char        *arg = "-2147483648";
    int         expected_result = 10;
    int         result;

    // ACT
    result = no_num(arg);

    // ASSERT
    mu_assert_int_eq(expected_result, result);
}

MU_TEST(try_pass_MAX_INT_should_be_10)
{
    // ARRANGE
    char        *arg = "2147483647";
    int         expected_result = 10;
    int         result;

    // ACT
    result = no_num(arg);

    // ASSERT
    mu_assert_int_eq(expected_result, result);
}

MU_TEST(try_pass_0_should_be_1)
{
    // ARRANGE
    char        *arg = "0";
    int         expected_result = 1;
    int         result;

    // ACT
    result = no_num(arg);

    // ASSERT
    mu_assert_int_eq(expected_result, result);
}

MU_TEST(try_pass_NULL_should_be_0)
{
    // ARRANGE
    char        *arg = NULL;
    int         expected_result = 0;
    int         result;

    // ACT
    result = no_num(arg);

    // ASSERT
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(try_pass_A_should_be_0);
    MU_RUN_TEST(try_pass_MIN_INT_should_be_10);
    MU_RUN_TEST(try_pass_MAX_INT_should_be_10);
    MU_RUN_TEST(try_pass_0_should_be_1);
    MU_RUN_TEST(try_pass_NULL_should_be_0);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}