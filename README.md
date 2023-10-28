# Tetrit App  
   
Tetrit is a simple yet powerful application designed to simulate and benchmark different blocks used in the popular game Tetris. The application uses the Eigen library for linear algebra and Catch2 for testing and benchmarking.   
  
The application is structured as follows:  
   
- `main.cpp`: This is the entry point of the application. It currently checks for the correct number of command line arguments and returns the size of the last argument.  
- `tetrit/blocks/`: This directory contains the definitions for different types of blocks.  
- `tetrit/geometry/kernel.hpp`: This file defines basic types and operations used by the blocks.  
- `test/src/`: This directory contains tests and benchmarks for the blocks and other parts of the application.  
   
## Features  
   
Tetrit includes seven different types of blocks:  
   
1. `block_t`: This is the base class for all other blocks. It includes basic operations like rotation and rendering.  
2. `corner_left_t`: This class represents a block with a corner facing left.  
3. `corner_right_t`: This class represents a block with a corner facing right.  
4. `snake_left_t`: This class represents a snake-like block facing left.  
5. `snake_right_t`: This class represents a snake-like block facing right.  
6. `square_t`: This class represents a square block.  
7. `tee_t`: This class represents a T-shaped block.  
8. `tower_t`: This class represents a tower-like block.  
   
All blocks can be rotated clockwise and counter-clockwise, and their current state can be rendered to a 2D matrix.  
   
The `geometry/kernel.hpp` file defines basic types and operations used by the blocks, like 2D points and vectors, and rotation matrices.  
   
The `test/src/` directory contains tests and benchmarks for the blocks and other parts of the application. The tests verify the correctness of the blocks' operations, and the benchmarks measure their performance.  
   
## Methods  
   
Each block class has the following methods:  
   
- `rotate_cw()`: Rotates the block 90 degrees clockwise.  
- `rotate_ccw()`: Rotates the block 90 degrees counter-clockwise.  
- `render()`: Returns the current state of the block as a 2D matrix.  
- `centroid()`: Returns the centroid of the block's current state.  
   
## Approaches  
   
The application uses the Eigen library for all linear algebra operations. This allows for efficient and readable code.  
   
The tests and benchmarks are written using the Catch2 framework. This makes it easy to add new tests and benchmarks as the application grows.  
   
The blocks are designed to be immutable. This means that all operations return a new block, leaving the original block unchanged. This makes the blocks easier to use and reason about.  
   
The application uses a simple command line interface. This makes it easy to run tests and benchmarks, and to experiment with different parameters.
