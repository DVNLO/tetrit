#include <catch2/catch_test_macros.hpp>

#include <type_traits>

#include "tetrit/geometry/kernel.hpp"

TEST_CASE("test_tetrit_geometry_kernel_value_t")
{
    namespace kernel = tetrit::geometry::kernel;
    REQUIRE(std::is_same<kernel::value_t, std::int_fast32_t>::value);
    REQUIRE(sizeof(kernel::value_t) >= 4);
}

TEST_CASE("test_tetrit_geometry_kernel_point_t")
{
    namespace kernel = tetrit::geometry::kernel;
    REQUIRE(std::is_same<kernel::point_t,
                         Eigen::Matrix<std::int_fast32_t, 1, 2>>::value);
    kernel::point_t p;
    REQUIRE(p.NumDimensions == 1);
    REQUIRE(p.rows() == 1);
    REQUIRE(p.cols() == 2);
}

TEST_CASE("test_tetrit_geometry_kernel_points_t")
{
    namespace kernel = tetrit::geometry::kernel;
    using points_t = kernel::points_t<2>;
    REQUIRE(
        std::is_same<points_t, Eigen::Matrix<std::int_fast32_t, 2, 2>>::value);
    points_t ps;
    REQUIRE(ps.NumDimensions == 2);
    REQUIRE(!ps.IsRowMajor);
    REQUIRE(ps.rows() == 2);
    REQUIRE(ps.cols() == 2);
}