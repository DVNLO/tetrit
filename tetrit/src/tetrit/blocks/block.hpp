#ifndef TETRIT_BLOCKS_BLOCK_H
#define TETRIT_BLOCKS_BLOCK_H

#include <cassert>

#include "tetrit/geometry/kernel.hpp"

namespace tetrit::blocks {

template <int point_count_v>
class block_t
{
public:
    static constexpr int point_count{ point_count_v };
    using kernel_t = tetrit::geometry::kernel_t;
    using value_t = kernel_t::value_t;
    using point_t = kernel_t::point_t;
    using vector_t = kernel_t::vector_t;
    using points_t = kernel_t::points_t<point_count>;
    using basis_t = kernel_t::basis_t;
    using rotation_t = kernel_t::rotation_t;

private:
    point_t position_val{ 0, 0 }; // of the centroid
    basis_t orientation_val{ { 1, 0 }, { 0, 1 } };
    points_t points_val;

public:
    block_t() = default;
    explicit block_t(points_t && points) noexcept
        : points_val{ std::move(points) }
    {}

    /**
     * @brief this block's position
     */
    [[nodiscard]] auto position() -> point_t & { return position_val; }
    [[nodiscard]] auto position() const -> point_t const &
    {
        return position_val;
    }

    /**
     * @brief this block's orientation
     */
    [[nodiscard]] auto orientation() -> basis_t & { return orientation_val; }
    [[nodiscard]] auto orientation() const -> basis_t const &
    {
        return orientation_val;
    }

    /**
     * @brief this block's points
     */
    [[nodiscard]] auto points() -> points_t & { return points_val; }
    [[nodiscard]] auto points() const -> points_t const &
    {
        return points_val;
    }

    /**
     * @brief render this block
     */
    [[nodiscard]] auto render() const -> points_t
    {
        return (points_val * orientation_val).rowwise() + position_val;
    }

    /**
     * @warning eigen implements *= operator expansion on the rhs (eg: A *= B
     * is equivalent to A = A * B). This is conceptually inconvenient for
     * rotation operations since it requires a transpose to maintain
     * consistency with traditional mathematical notation where matrix A is
     * rotated by matrix R using A = R * A = A * R^T.
     * https://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html
     */

    /**
     * @brief rotates this block's orientation 90 degrees clockwise.
     * @note rotation matrix is manually transposed to avoid the possibility of
     * runtime overhead.
     */
    auto rotate_cw() -> void
    {
        orientation_val *= rotation_t{ { 0, -1 }, { 1, 0 } };
    }

    /**
     * @brief rotates this block's orientation 90 degrees counter-clockwise.
     * @note rotation matrix is manually transposed to avoid the possibility of
     * runtime overhead.
     */
    auto rotate_ccw() -> void
    {
        orientation_val *= rotation_t{ { 0, 1 }, { -1, 0 } };
    }

    /**
     * @brief computes this block's centroid.
     */
    [[nodiscard]] auto centroid() const -> point_t
    {
        return point_t{ points_val.col(0).mean(), points_val.col(1).mean() };
    }
};

} // namespace tetrit::blocks

#endif // TETRIT_BLOCKS_BLOCK_H