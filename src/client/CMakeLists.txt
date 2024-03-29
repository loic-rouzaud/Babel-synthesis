cmake_minimum_required(VERSION 3.10)

project(Client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
    ${CMAKE_CURRENT_SOURCE_DIR}/Systems
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

set(SRC_FILES
    Core.cpp
    Client.cpp
    Systems/GraphicSystem.cpp
)

qt_wrap_cpp(MOC_FILES
    Core.hpp
    Client.hpp
    Systems/GraphicSystem.hpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${MOC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Network)