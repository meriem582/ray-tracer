cmake_minimum_required(VERSION 3.21)

project(ray-tracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    lodepng
    GIT_REPOSITORY https://github.com/lvandeve/lodepng.git
    GIT_TAG 7b2893e35891c0c85bee5595caafaf3c2044b409
)
FetchContent_MakeAvailable(lodepng)

add_library(lodepng STATIC ${lodepng_SOURCE_DIR}/lodepng.cpp)
target_include_directories(lodepng PUBLIC ${lodepng_SOURCE_DIR})

add_library(raytracer_core
    src/colour/colour.cpp
    src/geometry/ray.cpp
    src/geometry/plane.cpp
    src/geometry/sphere.cpp
    src/image/image.cpp
    src/material/material.cpp
    src/math/vector.cpp
    src/output/png_saver.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_core PUBLIC include src)
target_link_libraries(raytracer_core PRIVATE lodepng)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_core)

include(CTest)
add_test(NAME raytracer_demo COMMAND raytracer)
set_tests_properties(raytracer_demo PROPERTIES
    PASS_REGULAR_EXPRESSION "image.png"
)

if(BUILD_TESTING)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
    include(Catch)

    add_subdirectory(tests)
endif()
