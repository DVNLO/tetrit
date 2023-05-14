#ifndef TETRIT_GEOMETRY_KERNEL_H
#define TETRIT_GEOMETRY_KERNEL_H

#include <cstdint>

#include <Eigen/Core>

namespace tetrit {
namespace geometry {

class kernel_t
{
public:
    using value_t = std::int32_t;

    /**
     * @note all points are assumed to exist in a 2 dimensional cartesian
     * coordinate system. The 0-th dimension is the x-axis. The 1-th dimension
     * is the y-axis. Visually,
     *                 +y ^
     *                    |                  |
     *                    |                  |
     *                    |                  |
     *                    |                  |
     *              (0,0) |------------------|-----> +x
     *
     * @ref https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
     */
    using point_t = Eigen::Matrix<value_t, 1, 2>;
    using points_t = Eigen::Matrix<value_t, Eigen::Dynamic, 2>;
};

} // namespace geometry
} // namespace tetrit

#endif // TETRIT_BLOCKS_BLOCK_H