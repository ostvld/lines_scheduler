cmake_minimum_required(VERSION 3.7)
set(TARGET_PRO_NAME CSC)

project(${TARGET_PRO_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Три варианта сборки - plugin, module (dynamic module) и static (static module)
set(${TARGET_PRO_NAME}_BUILD_TYPE module CACHE STRING "Design system build type")
set_property(CACHE ${TARGET_PRO_NAME}_BUILD_TYPE PROPERTY STRINGS module plugin static)


set(BUILD_TYPE MODULE)
if(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        set(TARGET_NAME cscplugin)
elseif(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "module")
        set(TARGET_NAME csc)
        set(BUILD_TYPE SHARED)
        add_definitions(-D${TARGET_PRO_NAME}_BUILD)
else()
        set(TARGET_NAME csc)
        set(BUILD_TYPE STATIC)
endif()

list(APPEND HEADERS
        inc/csc_registrator.h
)

list(APPEND SOURCES
        src/csc_registrator.cpp
)

if(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        list(APPEND HEADERS inc/csc_plugin.h)
        list(APPEND SOURCES src/csc_plugin.cpp)
else()
        list(APPEND HEADERS inc/csc_library.h inc/csc_export.h)
        list(APPEND SOURCES src/csc_library.cpp)
endif()

add_library(${TARGET_NAME} ${BUILD_TYPE}
        ${HEADERS} ${SOURCES}
        custom_components_res.qrc
        qmldir
)
if(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "static")
        target_compile_definitions(${TARGET_NAME} PUBLIC -D${TARGET_PRO_NAME}_STATIC_BUILD)
endif()

find_package(Qt5 REQUIRED COMPONENTS Quick Core Qml)

target_link_libraries(${TARGET_NAME} PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Qml
)

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Название папки для плагина
set(CSC_MODULE_NAME CSC)

# Собираем плагин в папку с именем плагина
set_target_properties(${TARGET_NAME} PROPERTIES
   LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CSC_MODULE_NAME})

# Копируем qmldir в папку с плагином, чтобы его можно было загрузить
# Актуально только для сборки плагина
if(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/qmldir
                ${CMAKE_CURRENT_BINARY_DIR}/${CSC_MODULE_NAME}/qmldir)
elseif(${TARGET_PRO_NAME}_BUILD_TYPE STREQUAL "module")
        # динамическую библиотеку (тип module) добавляем в цель install
        install(TARGETS ${TARGET_NAME}
                        RUNTIME DESTINATION .
                        LIBRARY DESTINATION .
                        ARCHIVE DESTINATION .)
endif()

# Сообщаем другим CMake модулям папку, в которой собран плагин
SET(${TARGET_PRO_NAME}_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/${CSC_MODULE_NAME}" CACHE INTERNAL "Unified Design library build path")
# Сообщаем другим CMake модулям название цели
SET(${TARGET_PRO_NAME}_TARGET_NAME ${TARGET_NAME} CACHE INTERNAL "Unified Design library target name")
# Сообщаем другим CMake модулям название модуля QML
SET(${TARGET_PRO_NAME}_MODULE_NAME ${CSC_MODULE_NAME} CACHE INTERNAL "Unified Design qml module name")

# Регистрируем путь до QML файлов, чтобы типы корректно отображались в QtCreator
list(APPEND QML_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt Creator 4.1+ extra qml import paths" FORCE)
set(QML_IMPORT_PATH2 "${QML_DIRS}" CACHE STRING "Qt Creator 4.1+ extra qml import paths" FORCE)


