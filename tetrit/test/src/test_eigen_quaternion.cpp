#include <iostream>
#include <numbers>

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <Eigen/Geometry>

template <typename value_t>
class degree_t
{
public:
    value_t value;
    explicit degree_t(value_t const value_in) : value{ value_in } {}
};

template <typename value_t>
class radian_t
{
public:
    value_t value;
    explicit radian_t(value_t const value_in) : value{ value_in } {}
};

template <typename value_t>
constexpr auto
to_radian(degree_t<value_t> const d) -> radian_t<value_t>
{
    constexpr value_t d2r_factor{ std::numbers::pi_v<value_t>
                                  / static_cast<value_t>(180) };
    return radian_t<value_t>(d.value * d2r_factor);
}

template <typename value_t>
constexpr auto
to_degree(radian_t<value_t> const r) -> degree_t<value_t>
{
    constexpr value_t r2d_factor{ static_cast<value_t>(180)
                                  / std::numbers::pi_v<value_t> };
    return degree_t<value_t>(r.value * r2d_factor);
}

auto
rotate_axis0(double const e0) -> Eigen::Matrix3d
{
    double const c{ std::cos(e0) };
    double const s{ std::sin(e0) };
    return Eigen::Matrix3d{ { 1, 0, 0 }, { 0, c, -s }, { 0, s, c } };
}

auto
rotate_axis1(double const e1) -> Eigen::Matrix3d
{
    double const c{ std::cos(e1) };
    double const s{ std::sin(e1) };
    return Eigen::Matrix3d{ { c, 0, s }, { 0, 1, 0 }, { -s, 0, c } };
}

auto
rotate_axis2(double const e2) -> Eigen::Matrix3d
{
    double const c{ std::cos(e2) };
    double const s{ std::sin(e2) };
    return Eigen::Matrix3d{ { c, -s, 0 }, { s, c, 0 }, { 0, 0, 1 } };
}

auto
rotate(double const e0, double const e1, double const e2) -> Eigen::Matrix3d
{
    return rotate_axis0(e0) * rotate_axis1(e1) * rotate_axis2(e2);
}

auto
quaternion(double const e0, double const e1, double const e2)
    -> Eigen::Quaterniond
{
    Eigen::Quaterniond q(Eigen::AngleAxisd(e0, Eigen::Vector3d::UnitX())
                         * Eigen::AngleAxisd(e1, Eigen::Vector3d::UnitY())
                         * Eigen::AngleAxisd(e2, Eigen::Vector3d::UnitZ()));
    q.normalize();
    return q;
}

#include <Eigen/Dense>
#include <random>

TEST_CASE("test_eigen_benchmark")
{
    // https://eigen.tuxfamily.org/dox/group__TutorialGeometry.html
    // NOLINTBEGIN(*-magic-numbers)
    std::random_device rd{};
    std::mt19937 gen{ rd() };
    std::normal_distribution<double> d{ 180, 180 };
    radian_t<double> const roll{ to_radian(degree_t<double>(d(gen))) };
    radian_t<double> const pitch{ to_radian(degree_t<double>(d(gen))) };
    radian_t<double> const yaw{ to_radian(degree_t<double>(d(gen))) };
    Eigen::Matrix<double, 3, -1> M{ Eigen::MatrixXd::Random(3, 1048576) };

    Eigen::Vector3d const b{ d(gen), d(gen), d(gen) };
    // NOLINTEND(*-magic-numbers)

    BENCHMARK("test_eigen_quaternion_benchmark")
    {
        // https://eigen.tuxfamily.org/dox/classEigen_1_1Quaternion.html
        // https://eigen.tuxfamily.org/dox/classEigen_1_1AngleAxis.html
        // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
        Eigen::Quaterniond const q{ quaternion(roll.value, pitch.value,
                                               yaw.value) };
        // https://stackoverflow.com/questions/50507665/eigen-rotate-a-vector3d-with-a-quaternion
        return q.toRotationMatrix() * M;
    };
    BENCHMARK("test_eigen_rotation_vector_benchmark")
    {
        Eigen::Matrix3d const R{ rotate(roll.value, pitch.value, yaw.value) };
        return R * M;
    };
    // after a day exploring it seems that rotation matricies will beat
    // quaternioins when the bulk of the work is vector rotation. However, when
    // the bulk of the work is chaining successive rotations, quaternions can
    // quickly compute the final rotation matrix rather than chaining
    // successive matrix multiplications.
    // https://math.stackexchange.com/questions/1355081/why-is-representing-rotations-through-quaternions-more-compact-and-quicker-than
    // https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation#Comparison_with_other_representations_of_rotations
    // when the quaternion is constructed from euler angles the same degenerate
    // cases arrise with "gimbal lock
    // https://mathoverflow.net/questions/95902/the-gimbal-lock-shows-up-in-my-quaternions/95908#95908
    BENCHMARK("test_eigen_quaternion_benchmark_direction")
    {
        Eigen::Quaterniond q;
        q = Eigen::Quaterniond::FromTwoVectors(Eigen::Vector3d{ 1, 1, 1 }, b);
        q.normalize();
        return q.toRotationMatrix() * M;
    };
}