#ifndef TETRIT_BLOCKS_BLOCK_H
#define TETRIT_BLOCKS_BLOCK_H

#include <cstdint>

#include <Eigen/Core>

namespace tetrit {
namespace blocks {

class block_t
{
public:
    using value_t = int64_t;
    using points_t = Eigen::Matrix<value_t, Eigen::Dynamic, 2>;
    points_t points;

private:
    /**
     * @warning eigen implements *= operator expansion on the rhs (eg: A *= B
     * is equivalent to A = A * B). This is conceptually inconvenient for
     * rotation operations since it requires a transpose operation to maintain
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
};

} // namespace blocks
} // namespace tetrit

#endif // TETRIT_BLOCKS_BLOCK_H