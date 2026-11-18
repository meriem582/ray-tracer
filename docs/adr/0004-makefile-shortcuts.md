# 0004: Add Makefile command shortcuts

## Context

The existing CMake preset commands are difficult to remember. The project needs short commands for building, running the demo, testing, and cleaning. An alternative is to keep using the documented CMake and CTest commands directly.

## Decision

Add a Makefile with `build`, `run`, `test`, and `clean` targets that wrap the existing CMake preset workflow.

## Status

Proposed

## Consequences

The common workflow becomes easier to remember without replacing CMake, CTest, or Catch2. Contributors need GNU Make in addition to the existing tools, and `make clean` removes the build directory so the next build must be performed again.
