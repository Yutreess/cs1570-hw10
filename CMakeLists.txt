
cmake_minimum_required (VERSION 2.6)
project (burger-joint)

# I dont know the standard you use but this is something supported since 14
set (CMAKE_CXX_STANDARD 14)

# some flags that affect compiling to make it super fest
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions(-s -mtune=generic -Ofast -DNDEBUG -fno-rtti -fshort-enums -fno-plt -fvisibility=hidden -fno-operator-names)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_definitions(/D_CRT_SECURE_NO_WARNINGS=1) # So we can use our normal libc functions
    add_definitions(/w /GR- CONFIG Release)
endif ()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Find all of our sources and make an executable with them
file(GLOB sources "./*.cpp")
add_executable(burger-joint ${sources})
