Include(FetchContent)
FetchContent_Declare(
    Catch2
    SYSTEM
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(Catch2)
set(TEST_LIB_TETRIT "test_lib_tetrit")
add_executable(${TEST_LIB_TETRIT}
    src/test_blocks_block.cpp
    src/test_hello_world.cpp
)
target_link_libraries(${TEST_LIB_TETRIT} PRIVATE lib_tetrit)
target_link_libraries(${TEST_LIB_TETRIT} PRIVATE Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(${TEST_LIB_TETRIT})