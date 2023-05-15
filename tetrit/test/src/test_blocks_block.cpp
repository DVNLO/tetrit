#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/block.hpp"

using block_t = tetrit::blocks::block_t<4>;

TEST_CASE("test_tetrit_blocks_block_construct")
{
    block_t b(block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } });
    REQUIRE(b.points().cols() == 2);
    REQUIRE(b.points().rows() == 4);
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_cw")
{
    block_t b(block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } });
    b.rotate_cw();
    REQUIRE(b.render()
            == block_t::points_t{ { 2, 0 }, { 0, -2 }, { -2, 0 }, { 0, 2 } });
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_ccw")
{
    block_t b(block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } });
    b.rotate_ccw();
    REQUIRE(b.render()
            == block_t::points_t{ { -2, 0 }, { 0, 2 }, { 2, 0 }, { 0, -2 } });
}

TEST_CASE("test_tetrit_blocks_block_points_center_of_mass")
{
    block_t b(block_t::points_t{ { 0, 2 }, { 2, 0 }, { 0, -2 }, { -2, 0 } });
    REQUIRE(b.centroid() == block_t::point_t{ 0, 0 });
}