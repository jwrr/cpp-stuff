cmake_minimum_required(VERSION 3.16)
project(simple VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets COMPONENTS net gl core base)
if (NOT wxWidgets_FOUND)
  message(FATAL_ERROR "wxWidgets not found")
endif()
include(${wxWidgets_USE_FILE})

add_subdirectory(src)
add_subdirectory(app)




