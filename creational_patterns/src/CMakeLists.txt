# Define all source files
set(SOURCE_FILES # General files:
                 "MazeComponents.cpp"
                 "MazeGame.cpp"
                 # Creational Patterns:
                 "MazeAbstractFactory.cpp"
                 "MazeFactoryMethod.cpp"
                 "MazePrototypeFactory.cpp"
                 "MazeBuilder.cpp"
                 # Singleton:
                 "Logger.cpp")

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Define the library
add_library(MazeCreator SHARED ${SOURCE_FILES})
