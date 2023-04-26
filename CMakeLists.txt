cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(hello-qml)

# Qt setup ---

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED ENV{QT6_DIR})
  message(FATAL_ERROR "QT6 was not found")
endif()

message(STATUS "Using Qt6: \"$ENV{QT6_DIR}\"")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}$ENV{QT6_DIR})

find_package(Qt6 COMPONENTS Quick REQUIRED)

# ------------

add_executable(
  ${PROJECT_NAME}
  Resources/qml/qml.qrc
  SourceFiles/main.cpp
)

if (APPLE)

  # Fix error:
  # module "QtQuick" plugin "qtquick2plugin" not found
  # in static linked application ---

  get_target_property(QT_TARGET_TYPE Qt6::Core TYPE)
  if(${QT_TARGET_TYPE} STREQUAL "STATIC_LIBRARY")
    find_package(Qt6QmlImportScanner REQUIRED)
    qt6_import_qml_plugins(${CMAKE_PROJECT_NAME})
  endif()

  # ------------

endif()


target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick)

