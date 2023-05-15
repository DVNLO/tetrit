#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include "tetrit/blocks/tee.hpp"

TEST_CASE("test_tetrit_blocks_tee_default")
{
    tetrit::blocks::tee_t tee;
    REQUIRE(tee.position().NumDimensions == 1);
    REQUIRE(tee.position() == tetrit::blocks::tee_t::point_t{ 0, 0 });
    REQUIRE(tee.orientation().NumDimensions == 2);
    REQUIRE(tee.orientation().cols() == 2);
    REQUIRE(tee.orientation().rows() == 2);
    REQUIRE(tee.orientation()
            == tetrit::blocks::tee_t::basis_t{ { 1, 0 }, { 0, 1 } });
    REQUIRE(tee.points().NumDimensions == 2);
    REQUIRE(tee.points().cols() == 2);
    REQUIRE(tee.points().rows() == 10);
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_cw")
{
    tetrit::blocks::tee_t tee;
    tee.rotate_cw();
    REQUIRE(tee.render()
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
    REQUIRE(tee.render()
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
    REQUIRE(tee.centroid() == tetrit::blocks::tee_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_tee_points_rotate_cw_perf")
{
    tetrit::blocks::tee_t tee;
    BENCHMARK("test_tetrit_blocks_tee_points_rotate_cw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
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
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            tee.rotate_ccw();
        }
        return tee;
    };
}

TEST_CASE("test_tetrit_blocks_tee_points_render_perf")
{
    tetrit::blocks::tee_t tee;
    BENCHMARK("test_tetrit_blocks_tee_points_render_perf_1M")
    {
        tetrit::blocks::tee_t::points_t tmp;
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            tmp = tee.render();
        }
        return tmp;
    };
}
