cmake_minimum_required(VERSION 3.5)

set(QUICK_START_VERSION_MAJOR 1)
set(QUICK_START_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#################################################################
set(CONCURRENT_COLLECTIONS_SOURCES ${PROJECT_SOURCE_DIR}/ConcurrentCollections/ConcurrentCollections.cpp)
include_directories("${PROJECT_SOURCE_DIR}/ConcurrentCollections/include")
add_library(ConcurrentCollections SHARED ${CONCURRENT_COLLECTIONS_SOURCES})
