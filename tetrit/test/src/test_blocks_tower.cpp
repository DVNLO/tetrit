#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/tower.hpp"

TEST_CASE("test_tetrit_blocks_tower_default")
{
    tetrit::blocks::tower_t twr;
    REQUIRE(twr.points.NumDimensions == 2);
    REQUIRE(twr.points.cols() == 2);
    REQUIRE(twr.points.rows() == 10);
}

TEST_CASE("test_tetrit_blocks_tower_points_rotate_cw")
{
    tetrit::blocks::tower_t twr;
    twr.rotate_cw();
    REQUIRE(twr.points
            == tetrit::blocks::tower_t::points_t{ { -2, 0 },
                                                  { -2, -1 },
                                                  { -1, 0 },
                                                  { -1, -1 },
                                                  { 0, 0 },
                                                  { 0, -1 },
                                                  { 1, 0 },
                                                  { 1, -1 },
                                                  { 2, 0 },
                                                  { 2, -1 } });
}

TEST_CASE("test_tetrit_blocks_tower_points_rotate_ccw")
{
    tetrit::blocks::tower_t twr;
    twr.rotate_ccw();
    REQUIRE(twr.points
            == tetrit::blocks::tower_t::points_t{ { 2, 0 },
                                                  { 2, 1 },
                                                  { 1, 0 },
                                                  { 1, 1 },
                                                  { 0, 0 },
                                                  { 0, 1 },
                                                  { -1, 0 },
                                                  { -1, 1 },
                                                  { -2, 0 },
                                                  { -2, 1 } });
}

TEST_CASE("test_tetrit_blocks_tower_points_center_of_mass")
{
    tetrit::blocks::tower_t twr;
    REQUIRE(twr.center_of_mass() == tetrit::blocks::tower_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_tower_points_rotate_cw_perf")
{
    tetrit::blocks::tower_t twr;
    BENCHMARK("test_tetrit_blocks_tower_points_rotate_cw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            twr.rotate_cw();
        }
        return twr;
    };
}

TEST_CASE("test_tetrit_blocks_tower_points_rotate_ccw_perf")
{
    tetrit::blocks::tower_t twr;
    BENCHMARK("test_tetrit_blocks_tower_points_rotate_ccw_perf_1M")
    {
        for(int i{ 0 }; i < 1'000'000; ++i)
        {
            twr.rotate_ccw();
        }
        return twr;
    };
}
