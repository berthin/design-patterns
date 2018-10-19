# Define all source files
set(SOURCE_FILES # Structural Patterns:
                 # 1. Adapter
                 "FileSystem.cpp"
                 "FancyPrinter.cpp"
                 "FancyPathPrinter.cpp"
                 "AdapterClient.cpp"
                 # 2. Bridge
                 "Graph.cpp"
                 "GraphImpl.cpp"
                 "BridgeClient.cpp")

# Configure compiling flags
set(CMAKE_CXX_FLAGS "-std=c++14 -g")

# Define the library
add_library(StructuralPatternsLib ${SOURCE_FILES})
