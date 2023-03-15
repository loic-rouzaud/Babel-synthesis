cmake_minimum_required(VERSION 3.0)

project(MyProject)

include(ExternalProject)

# Set the path to the Makefile
set(./PortAudio/Makefile ${CMAKE_CURRENT_SOURCE_DIR}/Makefile)

# Define the external project
ExternalProject_Add(
    myproject_build  # Name of the external project
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}  # Source directory for the external project
    CONFIGURE_COMMAND ""  # No configure step
    BUILD_COMMAND make -f PortAudio/Makefile
    TEST_COMMAND ""  # No test step
)