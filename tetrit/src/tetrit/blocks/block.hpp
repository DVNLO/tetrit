#ifndef TETRIT_BLOCKS_BLOCK_H
#define TETRIT_BLOCKS_BLOCK_H

#include <cassert>
#include <cstdint>

#include <Eigen/Core>

namespace tetrit {
namespace blocks {

class block_t
{
public:
    /**
     * @note all blocks are assumed to exist in a 2 dimensional cartesian
     * coordinate system. The 0-th dimension is the x-axis. The 1-th dimension
     * is the y-axis. Visually,
     *                 +y ^
     *                    |                  |
     *                    |                  |
     *                    |                  |
     *                    |                  |
     *              (0,0) |------------------|-----> +x
     *
     * @note this block's center of mass is its origin
     */
    using value_t = int64_t;

    // https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
    using point_t = Eigen::Matrix<value_t, 1, 2>;
    using points_t = Eigen::Matrix<value_t, Eigen::Dynamic, 2>;
    points_t points;

    block_t() = default;
    block_t(points_t && points) noexcept : points{ std::move(points) }
    {
        assert((center_of_mass() == point_t{ 0, 0 }));
    }

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
     * @note rotation matrix is manually transposed to avoid runtime overhead.
     */
    void rotate_cw() { points *= rotation_t{ { 0, -1 }, { 1, 0 } }; }

    /**
     * @brief rotates this object 90 degrees counter-clockwise.
     * @note rotation matrix is manually transposed to avoid runtime overhead.
     */
    void rotate_ccw() { points *= rotation_t{ { 0, 1 }, { -1, 0 } }; }

    /**
     * @brief computes this block's center of mass
     */
    point_t center_of_mass()
    {
        return point_t{ points.col(0).mean(), points.col(1).mean() };
    }
};

} // namespace blocks
} // namespace tetrit

#endif // TETRIT_BLOCKS_BLOCK_H