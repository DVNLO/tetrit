#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/corner_right.hpp"

TEST_CASE("test_tetrit_blocks_corner_right_default")
{
    tetrit::blocks::corner_right_t cright;
    REQUIRE(cright.points.NumDimensions == 2);
    REQUIRE(cright.points.cols() == 2);
    REQUIRE(cright.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_corner_right_points_rotate_cw")
{
    tetrit::blocks::corner_right_t cright;
    cright.rotate_cw();
    REQUIRE(cright.points
            == tetrit::blocks::corner_right_t::points_t{ { -1, 0 },
                                                         { -1, -1 },
                                                         { -1, -2 },
                                                         { 0, 0 },
                                                         { 0, -1 },
                                                         { 0, -2 },
                                                         { 1, 0 },
                                                         { 1, -1 },
                                                         { 2, 0 },
                                                         { 2, -1 } });
}

TEST_CASE("test_tetrit_blocks_corner_right_points_rotate_ccw")
{
    tetrit::blocks::corner_right_t cright;
    cright.rotate_ccw();
    REQUIRE(cright.points
            == tetrit::blocks::corner_right_t::points_t{ { 1, 0 },
                                                         { 1, 1 },
                                                         { 1, 2 },
                                                         { 0, 0 },
                                                         { 0, 1 },
                                                         { 0, 2 },
                                                         { -1, 0 },
                                                         { -1, 1 },
                                                         { -2, 0 },
                                                         { -2, 1 } });
}

TEST_CASE("test_tetrit_blocks_corner_right_points_center_of_mass")
{
    tetrit::blocks::corner_right_t cright;
    REQUIRE(cright.center_of_mass()
            == tetrit::blocks::corner_right_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_corner_right_points_rotate_cw_perf")
{
    tetrit::blocks::corner_right_t cright;
    BENCHMARK("test_tetrit_blocks_corner_right_points_rotate_cw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            cright.rotate_cw();
        }
        return cright;
    };
}

TEST_CASE("test_tetrit_blocks_corner_right_points_rotate_ccw_perf")
{
    tetrit::blocks::corner_right_t cright;
    BENCHMARK("test_tetrit_blocks_corner_right_points_rotate_ccw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            cright.rotate_ccw();
        }
        return cright;
    };
}
