cmake_minimum_required (VERSION 2.6)
  project (labelGeneratorPlugin) 

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

set(${PROJECT_NAME}_HDRS
  include/labelGeneratorBase.h
  include/b.h
  include/c.h
)
  include_directories (include "${PROJECT_SOURCE_DIR}/include")

  FILE(GLOB SRC_LIST_CPP "${PROJECT_SOURCE_DIR}/src/*.cpp")
  FILE(GLOB SRC_LIST_C "${PROJECT_SOURCE_DIR}/src/*.c")


set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib/ )
set(CONSOLE_DIR /lib/x86_64-linux-gnu/)

link_directories(${LINK_DIR} ${CONSOLE_DIR})

  add_executable (main test/main.cpp src/b.cpp src/c.cpp)

  target_link_libraries( main optimized
    libclass_loader.so
    libconsole_bridge.so

 )

  add_library(labelPluginDemo SHARED ${SRC_LIST_CPP} ${${PROJECT_NAME}_HDRS})
  target_link_libraries(labelPluginDemo optimized
    libclass_loader.so
    libconsole_bridge.so

 )
