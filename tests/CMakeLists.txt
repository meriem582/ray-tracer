add_executable(raytracer_tests
    test_helpers.cpp
    colour/test_colour.cpp
    geometry/test_ray.cpp
    geometry/test_sphere.cpp
    math/test_vector.cpp
    render/test_camera.cpp
    render/test_trace.cpp
)
target_include_directories(raytracer_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(raytracer_tests PRIVATE raytracer_core Catch2::Catch2WithMain)
catch_discover_tests(raytracer_tests)
