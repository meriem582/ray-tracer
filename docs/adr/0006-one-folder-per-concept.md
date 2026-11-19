# 0006: Organize source and tests by concept

## Context

The project is beginning to add more concepts, including rays, shapes, cameras,
and images. Keeping every source file in one flat `src/` directory will make
the code harder to navigate. Contributors should be able to find a class and
its tests from the concept they implement.

## Decision

Place each concept's source files in a folder under `src/`, and mirror that
folder structure under `tests/`. Include project headers using paths relative
to `src/`, such as `math/vector.h`.

## Status

Proposed

## Consequences

Related source and test files are easier to locate, and include paths identify
the concept. The directory tree and CMake source lists require updates when
files move or new concepts are added; includes are also longer than with a
flat directory. This structure does not by itself separate build targets,
public headers, or symbol names.

## Deliberately deferred

- **Namespaces:** Add them when names collide or partner studios need to use
  the code alongside other libraries.
- **One library per folder:** Split build targets when dependencies between
  concepts or build times make independent compilation valuable.
- **A separate `include/` folder:** Introduce it when distributing the ray
  tracer as a library and public headers need to be separated from private
  implementation details.
