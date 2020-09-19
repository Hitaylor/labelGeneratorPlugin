cmake_minimum_required (VERSION 3.0)
project (micros_labelGeneratorPlugin VERSION 0.1.0) 

include(../micros.cmake)
message(MICROS_VERSION: ${MICROS_VERSION})

set(CMAKE_CXX_STANDARD 11)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


include_directories (include "${PROJECT_SOURCE_DIR}/include")

FILE(GLOB SRC_LIST_CPP "${PROJECT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB SRC_LIST_C "${PROJECT_SOURCE_DIR}/src/*.c")


set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib/ )
set(CONSOLE_DIR /lib/x86_64-linux-gnu/)

link_directories(${LINK_DIR} ${CONSOLE_DIR})

add_executable (test_time_color_label_main test/main.cpp src/b.cpp src/c.cpp)

target_link_libraries( test_time_color_label_main optimized
                      libclass_loader.so
                      libconsole_bridge.so
)

add_library(time_color_labelGeneratorPlugin.0.1.0 SHARED src/b.cpp src/c.cpp)
target_link_libraries(time_color_labelGeneratorPlugin.0.1.0 optimized
                      libclass_loader.so
                      libconsole_bridge.so
)

#### install #####
install(TARGETS time_color_labelGeneratorPlugin.0.1.0 LIBRARY DESTINATION lib/plugins)
## install(DIRECTORY include/  DESTINATION include/micros_dataCapture)
## install(TARGETS test_v4l2_plugin_main RUNTIME DESTINATION bin)
