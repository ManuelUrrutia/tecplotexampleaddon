cmake_minimum_required (VERSION 2.8)
project (example_addon)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules;${CMAKE_MODULE_PATH}")

find_package (Tecplot REQUIRED)
include_directories ("${TECPLOT_INCLUDE_DIR}")
add_library (${PROJECT_NAME}
    SHARED
    src/main.cpp
    )
target_link_libraries (${PROJECT_NAME}
    libtec
    tptoolbox
    )

include (cmake/SetupCompilerFlags.cmake)
include (cmake/SetupMSVCUserFile.cmake)