cmake_minimum_required(VERSION 3.21)

project(ray-tracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer_core
    src/colour/colour.cpp
    src/greeting.cpp
    src/geometry/ray.cpp
    src/geometry/sphere.cpp
    src/math/vector.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_core PUBLIC include src)

add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE raytracer_core)

include(CTest)
add_test(NAME raytracer_demo COMMAND raytracer)
set_tests_properties(raytracer_demo PROPERTIES
    PASS_REGULAR_EXPRESSION "1, 0, 0"
)

if(BUILD_TESTING)
    include(FetchContent)

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
