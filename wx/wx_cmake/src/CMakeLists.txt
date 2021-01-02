set (SOURCE_FILES
  SimpleApp.cpp
    SimpleFrame.cpp
      SimpleMenuBar.cpp
)

add_library(simple_lib ${SOURCE_FILES})
target_include_directories(simple_lib PUBLIC  ../include)
target_link_libraries(simple_lib PRIVATE ${wxWidgets_LIBRARIES})




