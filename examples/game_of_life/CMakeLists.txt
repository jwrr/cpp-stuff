cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 14)
project (game_of_life)
add_executable(game_of_life main.cpp Board.cpp Cell.cpp)
#[[
add_executable(game_of_life_test main_gtest.cpp Board.cpp Cell.cpp)
find_package(GTest REQUIRED)
target_link_libraries(game_of_life_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(game_of_life_test)
]]

