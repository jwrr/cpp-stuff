add_executable(simple_app main.cpp)
target_include_directories(simple_app PUBLIC  ../include)
target_link_libraries(simple_app PRIVATE simple_lib)




