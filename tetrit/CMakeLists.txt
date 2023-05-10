set(LIB_TETRIT "lib_tetrit")
add_library(${LIB_TETRIT} INTERFACE)
target_sources(${LIB_TETRIT} INTERFACE
    src/tetrit/hello_world.hpp
)
target_include_directories(${LIB_TETRIT} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(${LIB_TETRIT} INTERFACE cxx_std_20)
set(LIB_TETRIT_COMPILE_WARNINGS
    "-Wall"
    "-Walloca"
    "-Wcast-align"
    "-Wdouble-promotion"
    "-Werror"
    "-Wextra"
    "-Wfloat-equal"
    "-Wpedantic"
    "-Wshadow"
    "-Wswitch-enum"
    "-Wundef"
    "-Wunused"
    "-Wnon-virtual-dtor"
    "-Wold-style-cast"
)
target_compile_options(${LIB_TETRIT} INTERFACE ${LIB_TETRIT_COMPILE_WARNINGS})
set(LIB_TETRIT_COMPILE_FLAGS
    "-O3"
    "-flto"
    "-fno-common"
)
target_compile_options(${LIB_TETRIT} INTERFACE ${LIB_TETRIT_COMPILE_FLAGS})
set(LIB_TETRIT_LINK_OPTIONS
    ${LIB_TETRIT_COMPILE_FLAGS}
)
target_link_options(${LIB_TETRIT} INTERFACE ${LIB_TETRIT_LINK_OPTIONS})

set(TETRIT "tetrit")
add_executable(${TETRIT}
    app/tetrit/main.cpp
)
target_link_libraries(${TETRIT} PRIVATE ${LIB_TETRIT})
