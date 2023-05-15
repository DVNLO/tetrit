#ifndef TETRIT_BLOCKS_CORNER_RIGHT_H
#define TETRIT_BLOCKS_CORNER_RIGHT_H

#include "tetrit/blocks/block.hpp"

namespace tetrit::blocks {

class corner_right_t : public block_t<10>
{
public:
    corner_right_t()
        : block_t{ points_t{ { 0, -1 },
                             { 1, -1 },
                             { 2, -1 },
                             { 0, 0 },
                             { 1, 0 },
                             { 2, 0 },
                             { 0, 1 },
                             { 1, 1 },
                             { 0, 2 },
                             { 1, 2 } } }
    {}
};

} // namespace tetrit::blocks

#endif // TETRIT_BLOCKS_CORNER_RIGHT_H