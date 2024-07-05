# Copyright (c) 2024 Jim Eliot

# Project options
set(ENABLE_UNIT_TESTS
    ON
    CACHE BOOL "Enable unit tests")
set(ENABLE_DOCUMENTATION
    ON
    CACHE BOOL "Enable documentation")
set(ENABLE_IWYU
    ON
    CACHE BOOL "Enable include-what-you-use")

# Install location
# set(CMAKE_INSTALL_PREFIX
#     "${CMAKE_CURRENT_LIST_DIR}/install"
#     CACHE PATH "CMake install prefix")

set(DOXYGEN_INSTALL_PREFIX
    ""
)

set(SPHINX_INSTALL_PREFIX
    ""
)

set(GTEST_INSTALL_PREFIX
    ""
)

set(CMAKE_PREFIX_PATH
    "${DOXYGEN_INSTALL_PREFIX}" "${SPHINX_INSTALL_PREFIX}"
    "${GTEST_INSTALL_PREFIX}"
    CACHE PATH "CMake prefix path")

# clang-tidy
set(CMAKE_CXX_CLANG_TIDY clang-tidy)
