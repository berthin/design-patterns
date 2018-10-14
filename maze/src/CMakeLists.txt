# Define all source files
set(SOURCE_FILES # General files:
                 "MazeComponents.cpp"
                 "MazeGame.cpp"
                 # Patterns:
                 "MazeAbstractFactory.cpp"
                 "MazeFactoryMethod.cpp"
                 "MazePrototypeFactory.cpp"
                 "MazeBuilder.cpp")

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Define the library
add_library(MazeCreator ${SOURCE_FILES})
