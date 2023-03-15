cmake_minimum_required(VERSION 3.10)

# Define project name
project(Babel)

# Add source files to the project
add_executable(${PROJECT_NAME} Core.cpp)

# Add source files to the project
target_sources(${PROJECT_NAME}
    PRIVATE
    Core.cpp
)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)