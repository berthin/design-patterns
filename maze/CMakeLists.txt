cmake_minimum_required(VERSION 3.4)

project(Maze)

include_directories(${PROJECT_BINARY_DIR})

# Specify the directories to store the executables and libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Include directories of subprojects
include_directories(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
set(EXTRA_LIBS ${EXTRA_LIBS} MazeCreator)

# Create the executable
add_executable(Maze Maze.cpp)

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Link libraries with the executable
target_link_libraries(Maze ${EXTRA_LIBS})
