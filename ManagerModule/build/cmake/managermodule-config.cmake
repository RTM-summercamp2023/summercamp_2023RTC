# ManagerModule CMake config file
#
# This file sets the following variables:
# ManagerModule_FOUND - Always TRUE.
# ManagerModule_INCLUDE_DIRS - Directories containing the ManagerModule include files.
# ManagerModule_IDL_DIRS - Directories containing the ManagerModule IDL files.
# ManagerModule_LIBRARIES - Libraries needed to use ManagerModule.
# ManagerModule_DEFINITIONS - Compiler flags for ManagerModule.
# ManagerModule_VERSION - The version of ManagerModule found.
# ManagerModule_VERSION_MAJOR - The major version of ManagerModule found.
# ManagerModule_VERSION_MINOR - The minor version of ManagerModule found.
# ManagerModule_VERSION_REVISION - The revision version of ManagerModule found.
# ManagerModule_VERSION_CANDIDATE - The candidate version of ManagerModule found.

message(STATUS "Found ManagerModule-1.0.0")
set(ManagerModule_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(ManagerModule_INCLUDE_DIRS
#    "/usr/local/include/managermodule-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(ManagerModule_IDL_DIRS
#    "/usr/local/include/managermodule-1/idl")
set(ManagerModule_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(ManagerModule_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(ManagerModule_LIBRARIES
        "/usr/local//libmanagermodule.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(ManagerModule_LIBRARIES
        "/usr/local//libmanagermodule.so"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(ManagerModule_DEFINITIONS ${<dependency>_DEFINITIONS})

set(ManagerModule_VERSION 1.0.0)
set(ManagerModule_VERSION_MAJOR 1)
set(ManagerModule_VERSION_MINOR 0)
set(ManagerModule_VERSION_REVISION 0)
set(ManagerModule_VERSION_CANDIDATE )

