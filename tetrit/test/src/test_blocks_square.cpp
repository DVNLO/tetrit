#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/square.hpp"

TEST_CASE("test_tetrit_blocks_square_default")
{
    tetrit::blocks::square_t sqr;
    REQUIRE(sqr.points.NumDimensions == 2);
    REQUIRE(sqr.points.cols() == 2);
    REQUIRE(sqr.points.rows() == 9);
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_cw")
{
    tetrit::blocks::square_t sqr;
    sqr.rotate_cw();
    REQUIRE(sqr.points
            == tetrit::blocks::square_t::points_t{ { -1, 1 },
                                                  { 0, 1 },
                                                  { 1, 1 },
                                                  { -1, 0 },
                                                  { 0, 0 },
                                                  { 1, 0 },
                                                  { -1, -1 },
                                                  { 0, -1 },
                                                  { 1, -1 } });
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_ccw")
{
    tetrit::blocks::square_t sqr;
    sqr.rotate_ccw();
    REQUIRE(sqr.points
            == tetrit::blocks::square_t::points_t{ { 1, -1 },
                                                  { 0, -1 },
                                                  { -1, -1 },
                                                  { 1, 0 },
                                                  { 0, 0 },
                                                  { -1, 0 },
                                                  { 1, 1 },
                                                  { 0, 1 },
                                                  { -1, 1 } });
}

TEST_CASE("test_tetrit_blocks_square_points_center_of_mass")
{
    tetrit::blocks::square_t sqr;
    REQUIRE(sqr.center_of_mass() == tetrit::blocks::square_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_cw_perf")
{
    tetrit::blocks::square_t sqr;
    BENCHMARK("test_tetrit_blocks_square_points_rotate_cw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            sqr.rotate_cw();
        }
        return sqr;
    };
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_ccw_perf")
{
    tetrit::blocks::square_t sqr;
    BENCHMARK("test_tetrit_blocks_square_points_rotate_ccw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            sqr.rotate_ccw();
        }
        return sqr;
    };
}
