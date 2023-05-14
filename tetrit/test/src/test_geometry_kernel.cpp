#include <catch2/catch_test_macros.hpp>

#include <type_traits>

#include "tetrit/geometry/kernel.hpp"

TEST_CASE("test_tetrit_geometry_kernel_value_t")
{
    using kernel_t = tetrit::geometry::kernel_t;
    REQUIRE(std::is_same<kernel_t::value_t, std::int32_t>::value);
}

TEST_CASE("test_tetrit_geometry_kernel_point_t")
{
    using kernel_t = tetrit::geometry::kernel_t;
    REQUIRE(std::is_same<kernel_t::point_t,
                         Eigen::Matrix<std::int32_t, 1, 2>>::value);
}

TEST_CASE("test_tetrit_geometry_kernel_points_t")
{
    using kernel_t = tetrit::geometry::kernel_t;
    REQUIRE(std::is_same<kernel_t::points_t,
                         Eigen::Matrix<std::int32_t, -1, 2>>::value);
}