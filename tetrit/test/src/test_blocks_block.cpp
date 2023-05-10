#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/block.hpp"

TEST_CASE("test_tetrit_blocks_block_default")
{
    tetrit::blocks::block_t b;
    REQUIRE(b.points.cols() == 2);
    REQUIRE(b.points.rows() == 0);
}

TEST_CASE("test_tetrit_blocks_block_points_assign")
{
    tetrit::blocks::block_t b;
    b.points = tetrit::blocks::block_t::points_t{ { 0, 2 },
                                                  { 2, 0 },
                                                  { 0, -2 },
                                                  { -2, 0 } };
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_cw")
{
    tetrit::blocks::block_t b;
    b.points = tetrit::blocks::block_t::points_t{ { 0, 2 },
                                                  { 2, 0 },
                                                  { 0, -2 },
                                                  { -2, 0 } };
    b.rotate_cw();
    REQUIRE(b.points
            == tetrit::blocks::block_t::points_t{ { 2, 0 },
                                                  { 0, -2 },
                                                  { -2, 0 },
                                                  { 0, 2 } });
}

TEST_CASE("test_tetrit_blocks_block_points_rotate_ccw")
{
    tetrit::blocks::block_t b;
    b.points = tetrit::blocks::block_t::points_t{ { 0, 2 },
                                                  { 2, 0 },
                                                  { 0, -2 },
                                                  { -2, 0 } };
    b.rotate_ccw();
    REQUIRE(b.points
            == tetrit::blocks::block_t::points_t{ { -2, 0 },
                                                  { 0, 2 },
                                                  { 2, 0 },
                                                  { 0, -2 } });
}