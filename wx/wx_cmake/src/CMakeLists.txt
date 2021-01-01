set (SOURCE_FILES
  SimpleFrame.cpp
  SimpleApp.cpp
)

add_library(simple_lib ${SOURCE_FILES})
target_include_directories(simple_lib PUBLIC  ../include)
target_link_libraries(simple_lib PRIVATE ${wxWidgets_LIBRARIES})




