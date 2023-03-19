cmake_minimum_required(VERSION 3.10)

project(Server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
    ${CMAKE_CURRENT_SOURCE_DIR}/Systems
)

set(SRC_FILES
    Core.cpp
    Server.cpp
    TcpSocket.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets)

qt_wrap_cpp(MOC_FILES
    Server.hpp
    ANetwork.hpp
    TcpSocket.hpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${MOC_FILES})

target_link_libraries(Server PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Network
    Qt::Widgets
)