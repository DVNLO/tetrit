#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/tee.hpp"

TEST_CASE("test_tetrit_blocks_tee_default")
{
    tetrit::blocks::tee_t tee;
    REQUIRE(tee.points.NumDimensions == 2);
    REQUIRE(tee.points.cols() == 2);
    REQUIRE(tee.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_cw")
{
    tetrit::blocks::tee_t tee;
    tee.rotate_cw();
    REQUIRE(tee.points
            == tetrit::blocks::tee_t::points_t{ { -1, 0 },
                                                { -1, -1 },
                                                { 0, 1 },
                                                { 0, 0 },
                                                { 0, -1 },
                                                { 0, -2 },
                                                { 1, 1 },
                                                { 1, 0 },
                                                { 1, -1 },
                                                { 1, -2 } });
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_ccw")
{
    tetrit::blocks::tee_t tee;
    tee.rotate_ccw();
    REQUIRE(tee.points
            == tetrit::blocks::tee_t::points_t{ { 1, 0 },
                                                { 1, 1 },
                                                { 0, -1 },
                                                { 0, 0 },
                                                { 0, 1 },
                                                { 0, 2 },
                                                { -1, -1 },
                                                { -1, 0 },
                                                { -1, 1 },
                                                { -1, 2 } });
}

TEST_CASE("test_tetrit_blocks_tee_points_center_of_mass")
{
    tetrit::blocks::tee_t tee;
    REQUIRE(tee.center_of_mass() == tetrit::blocks::tee_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_cw_perf")
{
    tetrit::blocks::tee_t tee;
    BENCHMARK("test_tetrit_blocks_tee_points_rotate_cw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            tee.rotate_cw();
        }
        return tee;
    };
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_ccw_perf")
{
    tetrit::blocks::tee_t tee;
    BENCHMARK("test_tetrit_blocks_tee_points_rotate_ccw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            tee.rotate_ccw();
        }
        return tee;
    };
}
