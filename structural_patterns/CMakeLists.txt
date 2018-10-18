cmake_minimum_required(VERSION 3.4)

project(StructuralPatternsDemo)

include_directories(${PROJECT_BINARY_DIR})

# Enable Logger 
add_definitions(-D "ENABLE_LOGGER")

# Specify the directories to store the executables and libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Include directories of subprojects
include_directories(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
set(EXTRA_LIBS ${EXTRA_LIBS} StructuralPatternsLib)

# Create the executable
add_executable(demo Demo.cpp)

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Link libraries with the executable
target_link_libraries(demo ${EXTRA_LIBS})
