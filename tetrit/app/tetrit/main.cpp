#include <memory>
#include <string>

#include "tetrit/blocks/corner_left.hpp"
#include "tetrit/blocks/corner_right.hpp"
#include "tetrit/blocks/snake_left.hpp"
#include "tetrit/blocks/snake_right.hpp"
#include "tetrit/blocks/square.hpp"
#include "tetrit/blocks/tee.hpp"
#include "tetrit/blocks/tower.hpp"

int
main(int const argc, char const * const * argv)
{
    if(argc != 2)
    {
        return -1;
    }
    int const sz{ std::stoi(std::string(argv[argc - 1])) };
    return sz;
}