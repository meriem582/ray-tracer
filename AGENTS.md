# Project instructions

Configure with `cmake --preset unix-debug`, build with `cmake --build --preset unix-debug`, and test with `ctest --preset unix-debug`.

Run the demo with `./build/unix-debug/raytracer` (Linux/macOS) or `.\build\unix-debug\raytracer.exe` (Windows).

Before changing the build, tools, or test setup, read the architecture decisions in `docs/adr/`.

Never go against an accepted ADR. To change a decision, write a new ADR with status `Proposed` and ask me. Never set an ADR to `Accepted`.
