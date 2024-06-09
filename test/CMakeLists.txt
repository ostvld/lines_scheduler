cmake_minimum_required(VERSION 3.5)

project(qmltest LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-fprofile-arcs -ftest-coverage)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -fprofile-arcs --coverag -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Charts LinguistTools Test QuickTestREQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Quick Core Qml Charts Test QuickTest)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

set(QUICK_TEST_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/qml)

if(QT_VERSION_MAJOR EQUAL 6)
    qt6_add_resources(APP_RESOURCES ${CMAKE_CURRENT_LIST_DIR}/qml/tst_tests.qrc)
else()
    qt5_add_resources(APP_RESOURCES ${CMAKE_CURRENT_LIST_DIR}/qml/tst_tests.qrc)
endif()

add_executable(qmltest tst_qmltest.cpp ${APP_RESOURCES})
add_test(NAME qmltest COMMAND qmltest)

target_compile_definitions(qmltest PRIVATE "QUICK_TEST_SOURCE_DIR=\"${CMAKE_CURRENT_LIST_DIR}/qml\"")

target_include_directories(qmltest PUBLIC
    ${CMAKE_SOURCE_DIR}/csc/inc
    ${CMAKE_SOURCE_DIR}/core_fake/inc
    ${CMAKE_SOURCE_DIR}/integrity/inc
)

target_link_libraries(qmltest PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::Qml
    Qt${QT_VERSION_MAJOR}::Charts
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::QuickTest
    core_fake
    csc
    integrity_Lib
    )



