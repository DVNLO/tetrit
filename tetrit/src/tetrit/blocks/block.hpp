#ifndef TETRIT_BLOCKS_BLOCK_H
#define TETRIT_BLOCKS_BLOCK_H

#include <cstdint>

#include <Eigen/Core>

namespace tetrit {
namespace blocks {

class block_t
{
    using point_t = Eigen::Matrix<int32_t, 2, 1>;

public:
    int val{ 0 };
};

} // namespace blocks
} // namespace tetrit

#endif // TETRIT_BLOCKS_BLOCK_H