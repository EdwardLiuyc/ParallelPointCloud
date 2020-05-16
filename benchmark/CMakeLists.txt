find_package(PCL REQUIRED QUIET)
if(${PCL_VERSION} VERSION_GREATER "1.8.0" OR 
   ${PCL_VERSION} VERSION_EQUAL "1.8.0")
  message(STATUS "pcl version ${PCL_VERSION}")
  ## it is a trick to remove annoying warning in pcl-1.8 like this
  ## warning: ‘pcl::SAC_SAMPLE_SIZE’ ... [-Wdeprecated-declarations]
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem /usr/include/pcl-1.8") 
endif()
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
link_libraries(${PCL_LIBRARIES})

file(GLOB perf_srcs "performance/*.cc")
add_executable(tbb_vs_stl ppcl_tbb_vs_stl.cc ${perf_srcs})
target_link_libraries(tbb_vs_stl ${require_libs} pthread)