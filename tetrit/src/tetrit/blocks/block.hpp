#ifndef TETRIT_BLOCKS_BLOCK_H
#define TETRIT_BLOCKS_BLOCK_H

#include <cassert>

#include "tetrit/geometry/kernel.hpp"

namespace tetrit::blocks {

template <int point_count>
class block_t
{
public:
    using kernel_t = tetrit::geometry::kernel_t;
    using value_t = kernel_t::value_t;
    using point_t = kernel_t::point_t;
    using points_t = kernel_t::points_t<point_count>;
    points_t points;

    block_t() = default;
    explicit block_t(points_t && points) noexcept : points{ std::move(points) }
    {}

private:
    /**
     * @warning eigen implements *= operator expansion on the rhs (eg: A *= B
     * is equivalent to A = A * B). This is conceptually inconvenient for
     * rotation operations since it requires a transpose to maintain
     * consistency with traditional mathematical notation where matrix A is
     * rotated by matrix R using A = R * A = A * R^T.
     * https://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html
     */
    using rotation_t = Eigen::Matrix<value_t, 2, 2>;

public:
    /**
     * @brief rotates this object 90 degrees clockwise.
     * @note rotation matrix is manually transposed to avoid the possibility of
     * runtime overhead.
     */
    auto rotate_cw() -> void { points *= rotation_t{ { 0, -1 }, { 1, 0 } }; }

    /**
     * @brief rotates this object 90 degrees counter-clockwise.
     * @note rotation matrix is manually transposed to avoid the possibility of
     * runtime overhead.
     */
    auto rotate_ccw() -> void { points *= rotation_t{ { 0, 1 }, { -1, 0 } }; }

    /**
     * @brief computes this block's center of mass
     */
    [[nodiscard]] auto center_of_mass() const -> point_t
    {
        return point_t{ points.col(0).mean(), points.col(1).mean() };
    }
};

} // namespace tetrit::blocks

#endif // TETRIT_BLOCKS_BLOCK_H