add_executable(raytracer_tests
    test_greeting.cpp
    math/test_vector.cpp
)
target_link_libraries(raytracer_tests PRIVATE raytracer_core Catch2::Catch2WithMain)
catch_discover_tests(raytracer_tests)
