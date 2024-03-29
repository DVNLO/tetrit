#ifndef TETRIT_BLOCKS_TOWER_H
#define TETRIT_BLOCKS_TOWER_H

#include "tetrit/blocks/block.hpp"

namespace tetrit::blocks {

class tower_t : public block_t<10>
{
public:
    tower_t()
        : block_t{ points_t{ { 0, -2 },
                             { 1, -2 },
                             { 0, -1 },
                             { 1, -1 },
                             { 0, 0 },
                             { 1, 0 },
                             { 0, 1 },
                             { 1, 1 },
                             { 0, 2 },
                             { 1, 2 } } }
    {}
};

} // namespace tetrit::blocks

#endif // TETRIT_BLOCKS_TOWER_H