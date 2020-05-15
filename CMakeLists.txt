cmake_minimum_required(VERSION 3.5.0)
project(ppcl)

#######################################################
###  Compiler Options
#######################################################
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O3 -Wall \
  -Wextra -fPIC -ffast-math \
  -Wno-sign-compare \
  -Wno-unused-parameter \
  -Wno-unused-but-set-variable ")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

#### eigen ####
find_package(Eigen3 3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
message( STATUS 
  "Found Eigen in dir: ${EIGEN3_INCLUDE_DIR} version: ${EIGEN3_VERSION}")

include_directories(${PROJECT_SOURCE_DIR})

find_package(TBB REQUIRED)
message(STATUS "TBB version: ${TBB_INTERFACE_VERSION}")
include_directories(${TBB_INCLUDE_DIRS})
list(APPEND require_libs ${TBB_LIBRARIES})
link_libraries(glog)

add_executable(ppcl_test main.cc)
target_link_libraries(ppcl_test ${require_libs})