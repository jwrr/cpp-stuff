cmake_minimum_required(VERSION 3.16)
project(simple)
set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets COMPONENTS net gl core base)
if (NOT wxWidgets_FOUND)
  message(FATAL_ERROR "wxWidgets not found")
endif()

# cpp source files
set (SRC
  main.cpp
)

# Include path to wxWidget header files
include(${wxWidgets_USE_FILE})

# Compile
add_executable(simple ${SRC})

# Link wxWidget libaries
target_link_libraries(simple PRIVATE ${wxWidgets_LIBRARIES})




