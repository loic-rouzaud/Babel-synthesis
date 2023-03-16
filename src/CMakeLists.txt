cmake_minimum_required(VERSION 3.10)

# Define project name
project(Babel)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add source files to the project
add_executable(${PROJECT_NAME} Core.cpp)

# Add source files to the project
target_sources(${PROJECT_NAME}
    PRIVATE
    Core.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(Babel PRIVATE Qt6::Widgets)

# Set the C++ standard to use
