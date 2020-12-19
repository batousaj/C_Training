
# Version Required 
# First Cmake config for build sandboxes/project
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.11)

# project name
PROJECT (HT_MAIN)

# add  header/ libary for project
include_directories(
    ${PROJECT_SOURCE_DIR}/header
)

# Build file
add_executable(
    HT_MAIN
    ${PROJECT_SOURCE_DIR}/src/ht_main_debug.c
)



