cmake_minimum_required(VERSION 3.10)

# Define project name
project(Babel)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}../Interface
    ${CMAKE_CURRENT_SOURCE_DIR}../Systems
)

# Add source files to the project
set(SRC_FILES
    Core.cpp
    ../Systems/GraphicSystem.cpp
    ../Interface/ISystem.cpp
    client.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

qt_wrap_cpp(MOC_FILES
    ../Systems/GraphicSystem.hpp
    Client.hpp
    ../server/ANetwork.hpp
)

# Add source files to the project
add_executable(${PROJECT_NAME} ${SRC_FILES} ${MOC_FILES})

target_link_libraries(Babel PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Widgets
)