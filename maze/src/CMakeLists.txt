# Define all source files
set(SOURCE_FILES "NaiveMaze.cpp")

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Define the library
add_library(MazeCreator ${SOURCE_FILES})
