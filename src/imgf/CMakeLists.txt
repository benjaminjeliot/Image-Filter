# Copyright (c) 2024 Jim Eliot

add_library(
  imgfilter SHARED
  InputPort.cpp
  Node.cpp
  OutputPort.cpp
  ScalarDouble.cpp
  ScalarDoubleAddNode.cpp
  ScalarDoubleInputPort.cpp
  ScalarDoubleNode.cpp
  ScalarDoubleOutputPort.cpp)

target_compile_features(imgfilter PUBLIC cxx_std_17)

target_include_directories(
  imgfilter
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(imgfilter PUBLIC Boost::log)
