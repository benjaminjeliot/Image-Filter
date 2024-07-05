# Copyright (c) 2024 Jim Eliot

cmake_minimum_required(VERSION 3.20)

project(
  image-filter
  VERSION 0.1.0
  DESCRIPTION "Image filter project"
  LANGUAGES CXX)

# Project options
option(ENABLE_UNIT_TESTS "Enable unit tests" OFF)
option(ENABLE_DOCUMENTATION "Enable documentation" OFF)
option(ENABLE_IWYU "Enable include-what-you-use" OFF)

if(ENABLE_UNIT_TESTS)
  enable_testing()
endif()

# Dependencies
find_package(Boost REQUIRED COMPONENTS log program_options)
find_package(OpenMP REQUIRED)
if(ENABLE_UNIT_TESTS)
  find_package(GTest REQUIRED)
endif()
if(ENABLE_IWYU)
  find_program(IWYU_EXECUTABLE include-what-you-use)
  if(IWYU_EXECUTABLE)
    message(STATUS "Found include-what-you-use: ${IWYU_EXECUTABLE}")
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE
        ${IWYU_EXECUTABLE} -Xiwyu
        --mapping_file=${PROJECT_SOURCE_DIR}/iwyu_mapping.imp)
  endif()
endif()

add_subdirectory(src)

if(ENABLE_UNIT_TESTS)
  add_subdirectory(test)
endif()
