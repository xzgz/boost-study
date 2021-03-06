cmake_minimum_required(VERSION 2.8)

project(boost-study C CXX)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    message("Have set c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    message("Have set c++0x.")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
#if(COMPILER_SUPPORTS_CXX0X)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#    message("Have set c++0x.")
#endif()

set(BOOST_INCLUDE_DIR /media/xzgz/Ubuntu/Ubuntu/Library/boost_1_69_0/include)
set(BOOST_LIBRARY_DIR /media/xzgz/Ubuntu/Ubuntu/Library/boost_1_69_0/lib)

include_directories(${BOOST_INCLUDE_DIR})
link_directories(${BOOST_LIBRARY_DIR})

file(GLOB boost_static_libs ${BOOST_LIBRARY_DIR}/*.a*)
file(GLOB boost_shared_libs ${BOOST_LIBRARY_DIR}/*.so.*)
#set(Boost_LINKER_LIBS ${boost_static_libs})
set(Boost_LINKER_LIBS ${boost_shared_libs})

find_package(Threads REQUIRED)
message("Threads libs:")
foreach(val ${CMAKE_THREAD_LIBS_INIT})
    message(${val})
endforeach()
message("\n")

list(APPEND Boost_LINKER_LIBS ${CMAKE_THREAD_LIBS_INIT})

#message("\n\nboost_static_libs:")
#foreach(val ${boost_static_libs})
#    message(${val})
#endforeach()
#message("\n\nboost_shared_libs:")
#foreach(val ${boost_shared_libs})
#    message(${val})
#endforeach()
#message("Boost_LINKER_LIBS:")
#foreach(val ${Boost_LINKER_LIBS})
#    message(${val})
#endforeach()

#add_subdirectory(boost-thread)
#add_subdirectory(boost-ptr)
add_subdirectory(array)


