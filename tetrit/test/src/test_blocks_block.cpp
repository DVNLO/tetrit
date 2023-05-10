#include <catch2/catch_test_macros.hpp>

#include "tetrit/blocks/block.hpp"

TEST_CASE("test_tetrit_blocks_block_default")
{
    tetrit::blocks::block_t b;
    REQUIRE(b.val == 0);
}