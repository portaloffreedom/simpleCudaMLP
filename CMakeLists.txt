cmake_minimum_required(VERSION 2.8.11)
project(simpleCudaMLP)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag(--std=c++11 SUPPORTS_STD_CXX11)
    if(SUPPORTS_STD_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++11")
    else()
        message(ERROR "Compiler does not support --std=c++11")
    endif()
endif()

# cuda
find_package(CUDA REQUIRED)

# jsoncpp
find_package(PkgConfig)
pkg_check_modules(PC_JSONCPP REQUIRED jsoncpp)


# Add the include directories
INCLUDE_DIRECTORIES(${CUDA_INCLUDE_DIRS} ${PC_JSONCPP_INCLUDE_DIRS} src)

# Use the compile definitions
add_definitions()

# Add compiler flags for bulding executables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

FILE(GLOB_RECURSE simpleCudaMLP_SRCS src/*.cpp src/*.cu)

CUDA_ADD_EXECUTABLE(simpleCudaMLP ${simpleCudaMLP_SRCS})
target_link_libraries(simpleCudaMLP ${CUDA_LIBRARIES} ${PC_JSONCPP_LIBRARIES})

install(TARGETS simpleCudaMLP RUNTIME DESTINATION bin)
