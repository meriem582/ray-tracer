# ray-tracer

A C++ project bootstrapped for a maintainable, cross-platform ray tracer.

## Requirements

- CMake 3.21 or newer
- A C++20 compiler (GCC 10+, Clang 10+, or MSVC 19.29+)
- Ninja
- Internet access on the first configure, to download Catch2

The commands below work on Windows, macOS, and Linux when run with the
included development container. You can also use a local C++20 toolchain.

## Build and run

From the repository root:

```sh
cmake --preset unix-debug
cmake --build --preset unix-debug
```

Run the demo:

```sh
# Windows PowerShell
.\build\unix-debug\raytracer.exe

# macOS or Linux
./build/unix-debug/raytracer
```

Expected output:

```text
Hello, World!
```

## Run tests

Catch2 is downloaded automatically during the first configure. Run the tests
with:

```sh
ctest --preset unix-debug
```

To see each test's output, use:

```sh
ctest --test-dir build/unix-debug --output-on-failure
```

### TDD workflow

1. Add a test in `tests/` describing the behavior you want.
2. Run `ctest --preset unix-debug` and confirm the test fails for the expected reason.
3. Implement the behavior in `src/` or `include/`.
4. Run the tests again and keep them passing as you refactor.

## Development environments

### VS Code Dev Container

Install Docker Desktop and the **Dev Containers** extension, open this folder
in VS Code, then select **Reopen in Container** when prompted. The container
provides a C++ compiler, CMake, and Ninja. Run the build and test commands above
in the integrated terminal.

### Zed or another editor

The build is managed by CMake, not by a specific editor. In Zed, accept the
development-container prompt or run `projects: open dev container`, then use
the commands above in its terminal. For a local toolchain, install CMake,
Ninja, and a C++20 compiler first.

## Project layout

```text
.
├── .devcontainer/       # Shared container environment
├── include/raytracer/   # Public project headers
├── src/                 # Application and implementation
└── tests/               # Catch2 tests
```
