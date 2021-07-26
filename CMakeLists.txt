cmake_minimum_required(VERSION 3.19)
project(Laboratorio)

set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.1.1/lib/cmake")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)

add_subdirectory(test)

set(SOURCE_FILES main.cpp File.cpp File.h Observer.h Subject.h FileLoader.cpp FileLoader.h GUI.cpp GUI.h)

add_executable(Laboratorio main.cpp File.cpp File.h FileLoader.cpp FileLoader.h Subject.h Observer.h GUI.cpp GUI.h)
add_library(core ${SOURCE_FILES})

target_link_libraries(core Qt6::Widgets)
target_link_libraries(${PROJECT_NAME} core)