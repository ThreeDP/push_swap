#include "minunit.h"
#include "../srcs/push_swap.h"

MU_TEST(try_find_the_position_of_max_binary_place_of_10_should_be_4)
{
    // ARRANGE
    int     max_num             = 10;
    int     max_place           = 4;
    int     result_place;

    // ACT
    result_place = find_max_binary_position(max_num);

    // ASSERT
    mu_assert_int_eq(max_place, result_place);
}

MU_TEST(try_find_the_position_of_max_binary_place_of_9999_should_be_14)
{
    // ARRANGE
    int     max_num             = 9999;
    int     max_place           = 14;
    int     result_place;

    // ACT
    result_place = find_max_binary_position(max_num);

    // ASSERT
    mu_assert_int_eq(max_place, result_place);
}

MU_TEST(try_find_the_position_of_max_binary_place_of_0_should_be_0)
{
    // ARRANGE
    int     max_num             = 0;
    int     max_place           = 0;
    int     result_place;

    // ACT
    result_place = find_max_binary_position(max_num);

    // ASSERT
    mu_assert_int_eq(max_place, result_place);
}

MU_TEST(try_find_the_position_of_max_binary_place_of_minus_10_should_be_0)
{
    // ARRANGE
    int     max_num             = -10;
    int     max_place           = 0;
    int     result_place;

    // ACT
    result_place = find_max_binary_position(max_num);

    // ASSERT
    mu_assert_int_eq(max_place, result_place);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(try_find_the_position_of_max_binary_place_of_10_should_be_4);
    MU_RUN_TEST(try_find_the_position_of_max_binary_place_of_9999_should_be_14);
    MU_RUN_TEST(try_find_the_position_of_max_binary_place_of_0_should_be_0);
    MU_RUN_TEST(try_find_the_position_of_max_binary_place_of_minus_10_should_be_0);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}