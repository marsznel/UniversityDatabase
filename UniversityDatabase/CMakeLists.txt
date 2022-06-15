cmake_minimum_required (VERSION 3.9)
project(database)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(.)
include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(${PROJECT_NAME} ${SOURCE})
