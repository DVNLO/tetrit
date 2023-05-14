#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/snake_right.hpp"

TEST_CASE("test_tetrit_blocks_snake_right_default")
{
    tetrit::blocks::snake_right_t sright;
    REQUIRE(sright.points.NumDimensions == 2);
    REQUIRE(sright.points.cols() == 2);
    REQUIRE(sright.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_snake_right_points_rotate_cw")
{
    tetrit::blocks::snake_right_t sright;
    sright.rotate_cw();
    REQUIRE(sright.points
            == tetrit::blocks::snake_right_t::points_t{ { -1, 0 },
                                                        { -1, -1 },
                                                        { -1, -2 },
                                                        { 0, 1 },
                                                        { 0, 0 },
                                                        { 0, -1 },
                                                        { 0, -2 },
                                                        { 1, 1 },
                                                        { 1, 0 },
                                                        { 1, -1 } });
}

TEST_CASE("test_tetrit_blocks_snake_right_points_rotate_ccw")
{
    tetrit::blocks::snake_right_t sright;
    sright.rotate_ccw();
    REQUIRE(sright.points
            == tetrit::blocks::snake_right_t::points_t{ { 1, 0 },
                                                        { 1, 1 },
                                                        { 1, 2 },
                                                        { 0, -1 },
                                                        { 0, 0 },
                                                        { 0, 1 },
                                                        { 0, 2 },
                                                        { -1, -1 },
                                                        { -1, 0 },
                                                        { -1, 1 } });
}

TEST_CASE("test_tetrit_blocks_snake_right_points_center_of_mass")
{
    tetrit::blocks::snake_right_t sright;
    REQUIRE(sright.center_of_mass()
            == tetrit::blocks::snake_right_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_snake_right_points_rotate_cw_perf")
{
    tetrit::blocks::snake_right_t cright;
    BENCHMARK("test_tetrit_blocks_snake_right_points_rotate_cw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            cright.rotate_cw();
        }
        return cright;
    };
}

TEST_CASE("test_tetrit_blocks_snake_right_points_rotate_ccw_perf")
{
    tetrit::blocks::snake_right_t cright;
    BENCHMARK("test_tetrit_blocks_snake_right_points_rotate_ccw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            cright.rotate_ccw();
        }
        return cright;
    };
}
