#ifndef TETRIT_GEOMETRY_KERNEL_H
#define TETRIT_GEOMETRY_KERNEL_H

#include <cstdint>

#include <Eigen/Core>

namespace tetrit::geometry::kernel {

/**
 * @note use int_fast32_t as fundamental value type for portable and stable
 * performance with at least 32 bit width.
 * @ref https://en.cppreference.com/w/cpp/header/cstdint
 * @ref https://cplusplus.com/reference/cstdint/
 */
using value_t = std::int_fast32_t;

/**
 * @note all points are assumed to exist in a 2 dimensional cartesian
 * coordinate system. The 0-th dimension is the x-axis. The 1-th dimension
 * is the y-axis. Visually,
 *                 +y ^
 *                    |
 *                    |
 *                    |
 *                    |
 *              (0,0) |-----------------------> +x
 * @note points are rows
 * @note vectors are columns
 * @ref https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
 */
using point_t = Eigen::Matrix<value_t, 1, 2>;
using vector_t = Eigen::Matrix<value_t, 2, 1>;

template <int point_count>
using points_t = Eigen::Matrix<value_t, point_count, 2>;

using basis_t = Eigen::Matrix<value_t, 2, 2>;

using rotation_t = Eigen::Matrix<value_t, 2, 2>;

} // namespace tetrit::geometry::kernel

#endif // TETRIT_BLOCKS_BLOCK_H