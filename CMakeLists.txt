
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
# Should be add all file which use in the code of project
add_executable(
    HT_MAIN #naming of debug on cmd

    src/ht_countingsort_src.c 
    ${PROJECT_SOURCE_DIR}/src/ht_main_debug.c
)



