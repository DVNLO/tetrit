#ifndef TETRIT_BLOCKS_SNAKE_LEFT_H
#define TETRIT_BLOCKS_SNAKE_LEFT_H

#include "tetrit/blocks/block.hpp"

namespace tetrit::blocks {

class snake_left_t : public block_t<10>
{
public:
    snake_left_t()
        : block_t{ points_t{ { -1, -1 },
                             { 0, -1 },
                             { 1, -1 },
                             { -1, 0 },
                             { 0, 0 },
                             { 1, 0 },
                             { 2, 0 },
                             { 0, 1 },
                             { 1, 1 },
                             { 2, 1 } } }
    {}
};

} // namespace tetrit::blocks

#endif // TETRIT_BLOCKS_SNAKE_LEFT_H