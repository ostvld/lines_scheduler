cmake_minimum_required(VERSION 3.7)

set(PRO_NAME integrity)

project(${PRO_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Три варианта сборки - plugin, module (dynamic module) и static (static module)
set(${PRO_NAME}_BUILD_TYPE module CACHE STRING "Design system build type")
set_property(CACHE ${PRO_NAME}_BUILD_TYPE PROPERTY STRINGS module plugin static)

set(BUILD_TYPE MODULE)
if(${PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        set(${PRO_NAME}_TARGET_NAME integrityplugin)
elseif(${PRO_NAME}_BUILD_TYPE STREQUAL "module")
        set(${PRO_NAME}_TARGET_NAME integrity)
	set(BUILD_TYPE SHARED)
        add_definitions(-D${PRO_NAME}_BUILD)
else()
        set(${PRO_NAME}_TARGET_NAME integrity)
	set(BUILD_TYPE STATIC)
endif()

list(APPEND HEADERS
        inc/integrity_registrator.h
)

list(APPEND SOURCES
        src/integrity_registrator.cpp
)

if(${PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        list(APPEND HEADERS inc/integrity_plugin.h)
        list(APPEND SOURCES src/integrity_plugin.cpp)
else()
        list(APPEND HEADERS inc/integrity_library.h inc/integrity_export.h)
        list(APPEND SOURCES src/integrity_library.cpp)
endif()

add_library(${PRO_NAME}_Lib ${BUILD_TYPE}
	${HEADERS} ${SOURCES}
        IntegrityDesignRes.qrc
	# добавим сюда qmldir, чтобы он отображался в IDE в дереве проекта
        IntegrityQmldir
)
if(${PRO_NAME}_BUILD_TYPE STREQUAL "static")
        target_compile_definitions(${PRO_NAME}_Lib PUBLIC -D${PRO_NAME}_STATIC_BUILD)
endif()

find_package(Qt5 REQUIRED COMPONENTS Quick Core Qml)


target_include_directories(${PRO_NAME}_Lib PUBLIC
    ${CMAKE_SOURCE_DIR}/custom_style_components/inc
    ${CMAKE_SOURCE_DIR}/core/inc
    ${CMAKE_SOURCE_DIR}/integrity/inc
)

target_link_libraries(${PRO_NAME}_Lib
  PRIVATE
  Qt5::Core
  Qt5::Quick
  Qt5::Qml
  csc
  core)

target_include_directories(${PRO_NAME}_Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Название папки для плагина
set(Integrity_MODULE_NAME Integrity)

# Собираем плагин в папку с именем плагина
set_target_properties(${PRO_NAME}_Lib PROPERTIES
   LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${Integrity_MODULE_NAME})

# Копируем qmldir в папку с плагином, чтобы его можно было загрузить
# Актуально только для сборки плагина
if(${PRO_NAME}_BUILD_TYPE STREQUAL "plugin")
        add_custom_command(TARGET ${PRO_NAME}_Lib POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
		${CMAKE_CURRENT_SOURCE_DIR}/qmldir
                ${CMAKE_CURRENT_BINARY_DIR}/${Integrity_MODULE_NAME}/qmldir)
elseif(${PRO_NAME}_BUILD_TYPE STREQUAL "module")
	# динамическую библиотеку (тип module) добавляем в цель install
        install(TARGETS ${PRO_NAME}_Lib
			RUNTIME DESTINATION .
			LIBRARY DESTINATION .
			ARCHIVE DESTINATION .)
endif()

# Сообщаем другим CMake модулям папку, в которой собран плагин
SET(${PRO_NAME}_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/${Integrity_MODULE_NAME}" CACHE INTERNAL "Integrity Design library build path")
# Сообщаем другим CMake модулям название цели
SET(${PRO_NAME}_TARGET_NAME ${${PRO_NAME}_TARGET_NAME} CACHE INTERNAL "Integrity Design library target name")
# Сообщаем другим CMake модулям название модуля QML
SET(${PRO_NAME}_MODULE_NAME ${Integrity_MODULE_NAME} CACHE INTERNAL "Integrity Design qml module name")

# Регистрируем путь до QML файлов, чтобы типы корректно отображались в QtCreator
list(APPEND QML_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(QML_IMPORT_PATH "${QML_DIRS}" CACHE STRING "Qt Creator 4.1+ extra qml import paths" FORCE)
set(QML_IMPORT_PATH2 "${QML_DIRS}" CACHE STRING "Qt Creator 4.1+ extra qml import paths" FORCE)

