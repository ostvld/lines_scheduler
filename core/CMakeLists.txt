 cmake_minimum_required(VERSION 3.14)

 project(core VERSION 0.1 LANGUAGES CXX)

 set(CMAKE_INCLUDE_CURRENT_DIR ON)

 set(CMAKE_AUTOUIC ON)
 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTORCC ON)

 set(CMAKE_CXX_STANDARD 20)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)

 find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick LinguistTools REQUIRED)
 find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick LinguistTools REQUIRED)

 set(PROJECT_SOURCES
         inc/core.hpp
         src/core.cpp
 )

add_library(${PROJECT_NAME} STATIC
             ${PROJECT_SOURCES}
         )

target_include_directories(${PROJECT_NAME}
         PUBLIC
         ./inc)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    Qt5::Core
    Qt5::Quick
)
