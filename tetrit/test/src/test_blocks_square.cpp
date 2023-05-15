#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/square.hpp"

TEST_CASE("test_tetrit_blocks_square_default")
{
    tetrit::blocks::square_t sqr;
    REQUIRE(sqr.position().NumDimensions == 1);
    REQUIRE(sqr.position() == tetrit::blocks::square_t::point_t{ 0, 0 });
    REQUIRE(sqr.orientation().NumDimensions == 2);
    REQUIRE(sqr.orientation().cols() == 2);
    REQUIRE(sqr.orientation().rows() == 2);
    REQUIRE(sqr.orientation()
            == tetrit::blocks::square_t::basis_t{ { 1, 0 }, { 0, 1 } });
    REQUIRE(sqr.points().NumDimensions == 2);
    REQUIRE(sqr.points().cols() == 2);
    REQUIRE(sqr.points().rows() == 9);
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_cw")
{
    tetrit::blocks::square_t sqr;
    sqr.rotate_cw();
    REQUIRE(sqr.render()
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
    REQUIRE(sqr.render()
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
    REQUIRE(sqr.centroid() == tetrit::blocks::square_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_square_points_rotate_cw_perf")
{
    tetrit::blocks::square_t sqr;
    BENCHMARK("test_tetrit_blocks_square_points_rotate_cw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
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
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            sqr.rotate_ccw();
        }
        return sqr;
    };
}

TEST_CASE("test_tetrit_blocks_square_points_render_perf")
{
    tetrit::blocks::square_t sqr;
    BENCHMARK("test_tetrit_blocks_square_points_render_perf_1M")
    {
        tetrit::blocks::square_t::points_t tmp;
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            tmp = sqr.render();
        }
        return tmp;
    };
}
