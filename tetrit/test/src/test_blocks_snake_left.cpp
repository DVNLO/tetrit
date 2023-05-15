#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/snake_left.hpp"

TEST_CASE("test_tetrit_blocks_snake_left_default")
{
    tetrit::blocks::snake_left_t sleft;
    REQUIRE(sleft.points.NumDimensions == 2);
    REQUIRE(sleft.points.cols() == 2);
    REQUIRE(sleft.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_cw")
{
    tetrit::blocks::snake_left_t sleft;
    sleft.rotate_cw();
    REQUIRE(sleft.points
            == tetrit::blocks::snake_left_t::points_t{ { -1, 1 },
                                                       { -1, 0 },
                                                       { -1, -1 },
                                                       { 0, 1 },
                                                       { 0, 0 },
                                                       { 0, -1 },
                                                       { 0, -2 },
                                                       { 1, 0 },
                                                       { 1, -1 },
                                                       { 1, -2 } });
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_ccw")
{
    tetrit::blocks::snake_left_t sleft;
    sleft.rotate_ccw();
    REQUIRE(sleft.points
            == tetrit::blocks::snake_left_t::points_t{ { 1, -1 },
                                                       { 1, 0 },
                                                       { 1, 1 },
                                                       { 0, -1 },
                                                       { 0, 0 },
                                                       { 0, 1 },
                                                       { 0, 2 },
                                                       { -1, 0 },
                                                       { -1, 1 },
                                                       { -1, 2 } });
}

TEST_CASE("test_tetrit_blocks_snake_left_points_center_of_mass")
{
    tetrit::blocks::snake_left_t sleft;
    REQUIRE(sleft.center_of_mass()
            == tetrit::blocks::snake_left_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_cw_perf")
{
    tetrit::blocks::snake_left_t cleft;
    BENCHMARK("test_tetrit_blocks_snake_left_points_rotate_cw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            cleft.rotate_cw();
        }
        return cleft;
    };
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_ccw_perf")
{
    tetrit::blocks::snake_left_t cleft;
    BENCHMARK("test_tetrit_blocks_snake_left_points_rotate_ccw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            cleft.rotate_ccw();
        }
        return cleft;
    };
}
