
# Version Required 
# First Cmake config for build sandboxes/project
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.11)

# project name
PROJECT (HT_MAIN)

# add  header/ libary for project
include_directories(
    ${PROJECT_SOURCE_DIR}/header
    ${PROJECT_SOURCE_DIR}
    # ${PROJECT_SOURCE_DIR}/common
    # ${PROJECT_SOURCE_DIR}/Platform
)

# Build file
# Should be add all file which use in the code of project
add_executable(
    HT_MAIN #naming of debug on cmd

    # main.c
    # ht_main_debug.c
    src/main.cpp
)



