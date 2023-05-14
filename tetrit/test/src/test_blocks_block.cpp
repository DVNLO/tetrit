#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/block.hpp"

using block_t = tetrit::blocks::block_t<4>;

TEST_CASE("test_tetrit_blocks_block_default")
{
    block_t b;
    REQUIRE(b.points.cols() == 2);
    REQUIRE(b.points.rows() == 4);
}

TEST_CASE("test_tetrit_blocks_block_points_assign")
{
    block_t b;
    b.points = block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } };
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_cw")
{
    block_t b;
    b.points = block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } };
    b.rotate_cw();
    REQUIRE(b.points
            == block_t::points_t{ { 2, 0 }, { 0, -2 }, { -2, 0 }, { 0, 2 } });
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_ccw")
{
    block_t b;
    b.points = block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } };
    b.rotate_ccw();
    REQUIRE(b.points
            == block_t::points_t{ { -2, 0 }, { 0, 2 }, { 2, 0 }, { 0, -2 } });
}

TEST_CASE("test_tetrit_blocks_block_points_center_of_mass")
{
    block_t b;
    b.points = block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } };
    REQUIRE(b.center_of_mass() == block_t::point_t{ 0, 0 });
}