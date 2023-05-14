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
    tetrit::blocks::corner_left_t cleft;
    tetrit::blocks::corner_left_t cright;
    tetrit::blocks::snake_left_t snake_left;
    tetrit::blocks::snake_right_t snake_right;
    tetrit::blocks::square_t square;
    tetrit::blocks::tee_t tee;
    tetrit::blocks::tower_t tower;
    for(int i{ 0 }; i < sz; ++i)
    {
        cleft.rotate_cw();
        cright.rotate_cw();
        snake_left.rotate_cw();
        snake_right.rotate_cw();
        square.rotate_cw();
        tee.rotate_cw();
        tower.rotate_cw();
    }
    for(int i{ 0 }; i < sz; ++i)
    {
        cleft.rotate_ccw();
        cright.rotate_ccw();
        snake_left.rotate_ccw();
        snake_right.rotate_ccw();
        square.rotate_ccw();
        tee.rotate_ccw();
        tower.rotate_ccw();
    }

    return 0;
}