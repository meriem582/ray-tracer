# ray-tracer

A C++ project bootstrapped for a maintainable, cross-platform ray tracer.

## Requirements

- CMake 3.21 or newer
- A C++20 compiler (GCC 10+, Clang 10+, or MSVC 19.29+)
- Ninja
- GNU Make for the short commands
- Internet access on the first configure, to download Catch2

The short commands below are intended for the development container. You can
also use CMake directly with a local C++20 toolchain.

## Short commands

From the repository root, use:

```sh
make build  # configure and compile
make run    # build, then run the demo
make test   # build, then run the tests
make clean  # remove the build directory
```

`make run` runs a one-pixel ray-tracing demo and prints `(1, 0, 0)`. The
`clean` target removes all files under `build/`; the next build will configure
the project and may download Catch2.

## Build and run with CMake

For a local toolchain, configure and build with:

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

Expected demo output:

```text
(1, 0, 0)
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

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for development setup, the TDD workflow,
and how to work with architecture decisions. Review the [MIT license](LICENSE)
and [Code of Conduct](CODE_OF_CONDUCT.md) before contributing. Issue and pull
request templates are in [`.github/`](.github/); pull requests run the
container-based checks defined in [`.github/workflows/ci.yml`](.github/workflows/ci.yml).

## Project layout

```text
.
├── .devcontainer/       # Shared container environment
├── docs/                 # Discovery report, domain model, and ADRs
├── src/
│   ├── colour/
│   ├── geometry/
│   ├── math/
│   └── render/
└── tests/                # Catch2 tests, organized by concept
```
