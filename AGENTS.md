# Project instructions

Use `make build` to configure and compile, `make run` to compile and run the demo, `make test` to compile and run tests, and `make clean` to remove the build directory. These shortcuts require GNU Make and are intended for the development container.

Read `CONTRIBUTING.md`, `LICENSE`, and `CODE_OF_CONDUCT.md` before contributing; use the templates in `.github/`. CI is defined in `.github/workflows/ci.yml`.

Before changing the build, tools, test setup, or CI, read the architecture decisions in `docs/adr/`.

Never go against an accepted ADR. To change a decision, write a new ADR with status `Proposed` and ask me. Never set an ADR to `Accepted`.

## Source layout

New classes go in the folder for their concept under `src/`, and their tests
go in the matching folder under `tests/`.

## How we work

- TDD: write a failing test first, then only enough code to make it pass.
- Expected values come from the maths, not from running the code. If a test
  fails, ask me before changing its expected values.
- Work one small step at a time; do only what I ask for.
- Keep the C++ simple; don't use advanced features unless I ask.
- Don't build or run anything on the host; run project commands in the dev
  container.
