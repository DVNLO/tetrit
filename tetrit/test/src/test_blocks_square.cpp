#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/square.hpp"

TEST_CASE("test_tetrit_blocks_square_default")
{
    tetrit::blocks::square_t sqr;
    REQUIRE(sqr.points.cols() == 2);
    REQUIRE(sqr.points.rows() == 9);
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_cw")
{
    tetrit::blocks::square_t sqr;
    sqr.rotate_cw();
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_ccw")
{
    tetrit::blocks::square_t sqr;
    sqr.rotate_ccw();
}