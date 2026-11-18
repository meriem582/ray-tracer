# 0002: Use CMake and CTest

## Context

The project needs a cross-platform way to configure and build its C++ code, and a consistent way to run tests. Alternatives include platform-specific project files or another build system such as Meson.

## Decision

Use CMake 3.21 or newer with Ninja presets to configure and build the project. Use CTest, included with CMake, to run the registered tests.

## Status

Proposed

## Consequences

CMake is commonly used for C++ and supports the project's cross-platform goal. Contributors must learn and maintain CMake configuration and presets, and install CMake and Ninja.
