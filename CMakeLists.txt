cmake_minimum_required(VERSION 3.15)
project(gaya)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)

add_executable(gaya main.cpp MainWindow.cpp MainWindow.h Card.cpp Card.h MyButton.cpp MyButton.h)

include_directories(usr/local/include)
link_directories(usr/local/lib)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
