# mycobot_Transform CMake config file
#
# This file sets the following variables:
# mycobot_Transform_FOUND - Always TRUE.
# mycobot_Transform_INCLUDE_DIRS - Directories containing the mycobot_Transform include files.
# mycobot_Transform_IDL_DIRS - Directories containing the mycobot_Transform IDL files.
# mycobot_Transform_LIBRARIES - Libraries needed to use mycobot_Transform.
# mycobot_Transform_DEFINITIONS - Compiler flags for mycobot_Transform.
# mycobot_Transform_VERSION - The version of mycobot_Transform found.
# mycobot_Transform_VERSION_MAJOR - The major version of mycobot_Transform found.
# mycobot_Transform_VERSION_MINOR - The minor version of mycobot_Transform found.
# mycobot_Transform_VERSION_REVISION - The revision version of mycobot_Transform found.
# mycobot_Transform_VERSION_CANDIDATE - The candidate version of mycobot_Transform found.

message(STATUS "Found mycobot_Transform-")
set(mycobot_Transform_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(mycobot_Transform_INCLUDE_DIRS
#    "/usr/local/include/mycobot_transform-"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(mycobot_Transform_IDL_DIRS
#    "/usr/local/include/mycobot_transform-/idl")
set(mycobot_Transform_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(mycobot_Transform_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(mycobot_Transform_LIBRARIES
        "/usr/local//libmycobot_transform.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(mycobot_Transform_LIBRARIES
        "/usr/local//libmycobot_transform.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(mycobot_Transform_DEFINITIONS ${<dependency>_DEFINITIONS})

set(mycobot_Transform_VERSION )
set(mycobot_Transform_VERSION_MAJOR )
set(mycobot_Transform_VERSION_MINOR )
set(mycobot_Transform_VERSION_REVISION )
set(mycobot_Transform_VERSION_CANDIDATE )

