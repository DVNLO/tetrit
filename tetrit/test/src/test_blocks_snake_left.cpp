#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/snake_left.hpp"

TEST_CASE("test_tetrit_blocks_snake_left_default")
{
    tetrit::blocks::snake_left_t sleft;
    REQUIRE(sleft.position().NumDimensions == 1);
    REQUIRE(sleft.position()
            == tetrit::blocks::snake_left_t::point_t{ 0, 0 });
    REQUIRE(sleft.orientation().NumDimensions == 2);
    REQUIRE(sleft.orientation().cols() == 2);
    REQUIRE(sleft.orientation().rows() == 2);
    REQUIRE(sleft.orientation()
            == tetrit::blocks::snake_left_t::basis_t{ { 1, 0 }, { 0, 1 } });
    REQUIRE(sleft.points().NumDimensions == 2);
    REQUIRE(sleft.points().cols() == 2);
    REQUIRE(sleft.points().rows() == 10);
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_cw")
{
    tetrit::blocks::snake_left_t sleft;
    sleft.rotate_cw();
    REQUIRE(sleft.render()
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
    REQUIRE(sleft.render()
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
    REQUIRE(sleft.centroid() == tetrit::blocks::snake_left_t::point_t{ 0, 0 });
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_cw_perf")
{
    tetrit::blocks::snake_left_t sleft;
    BENCHMARK("test_tetrit_blocks_snake_left_points_rotate_cw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            sleft.rotate_cw();
        }
        return sleft;
    };
}

TEST_CASE("test_tetrit_blocks_snake_left_points_rotate_ccw_perf")
{
    tetrit::blocks::snake_left_t sleft;
    BENCHMARK("test_tetrit_blocks_snake_left_points_rotate_ccw_perf_1M")
    {
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            sleft.rotate_ccw();
        }
        return sleft;
    };
}

TEST_CASE("test_tetrit_blocks_snake_left_points_render_perf")
{
    tetrit::blocks::snake_left_t sleft;
    BENCHMARK("test_tetrit_blocks_snake_left_points_render_perf_1M")
    {
        tetrit::blocks::snake_left_t::points_t tmp;
        int constexpr count{ 1'000'000 };
        for(int i{ 0 }; i < count; ++i)
        {
            tmp = sleft.render();
        }
        return tmp;
    };
}
