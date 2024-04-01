##########################################################################
# Sets the generator to "MinGW Makefiles" on Windows
# https://stackoverflow.com/questions/11269833/cmake-selecting-a-generator-within-cmakelists-txt
##########################################################################

if(CMAKE_HOST_WIN32)
    message(STATUS "Windows Host System detected")
    set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
    message(STATUS "Using CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
endif()
