# Copyright (c) 2024 Jim Eliot

add_executable(app main.cpp)

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE imgfilter)
