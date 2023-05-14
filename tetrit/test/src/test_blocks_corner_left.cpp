#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/corner_left.hpp"

TEST_CASE("test_tetrit_blocks_corner_left_default")
{
    tetrit::blocks::corner_left_t cleft;
    REQUIRE(cleft.points.NumDimensions == 2);
    REQUIRE(cleft.points.cols() == 2);
    REQUIRE(cleft.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_corner_left_points_rotate_cw")
{
    tetrit::blocks::corner_left_t cleft;
    cleft.rotate_cw();
    REQUIRE(cleft.points
            == tetrit::blocks::corner_left_t::points_t{ { -1, 1 },
                                                        { -1, 0 },
                                                        { -1, -1 },
                                                        { 0, 1 },
                                                        { 0, 0 },
                                                        { 0, -1 },
                                                        { 1, 0 },
                                                        { 1, -1 },
                                                        { 2, 0 },
                                                        { 2, -1 } });
}

TEST_CASE("test_tetrit_blocks_corner_left_points_rotate_ccw")
{
    tetrit::blocks::corner_left_t cleft;
    cleft.rotate_ccw();
    REQUIRE(cleft.points
            == tetrit::blocks::corner_left_t::points_t{ { 1, -1 },
                                                        { 1, 0 },
                                                        { 1, 1 },
                                                        { 0, -1 },
                                                        { 0, 0 },
                                                        { 0, 1 },
                                                        { -1, 0 },
                                                        { -1, 1 },
                                                        { -2, 0 },
                                                        { -2, 1 } });
}

TEST_CASE("test_tetrit_blocks_corner_left_points_center_of_mass")
{
    tetrit::blocks::corner_left_t cleft;
    REQUIRE(cleft.center_of_mass()
            == tetrit::blocks::corner_left_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_corner_left_points_rotate_cw_perf")
{
    tetrit::blocks::corner_left_t cleft;
    BENCHMARK("test_tetrit_blocks_corner_left_points_rotate_cw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            cleft.rotate_cw();
        }
        return cleft;
    };
}

TEST_CASE("test_tetrit_blocks_corner_left_points_rotate_ccw_perf")
{
    tetrit::blocks::corner_left_t cleft;
    BENCHMARK("test_tetrit_blocks_corner_left_points_rotate_ccw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            cleft.rotate_ccw();
        }
        return cleft;
    };
}
