#include <catch2/catch_test_macros.hpp>

#include "tetrit/hello_world.hpp"

TEST_CASE("test_tetrit_hello_world") { REQUIRE(tetrit::hello_world() == 8); }