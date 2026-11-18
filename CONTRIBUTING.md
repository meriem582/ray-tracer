# Contributing

Thanks for your interest in contributing. The project is still being prepared
for outside contributions; these instructions describe the current setup and
workflow.

## Set up the development environment

The recommended environment is the included development container:

- In VS Code, install Docker Desktop and the Dev Containers extension, open
  this repository, and choose **Reopen in Container**.
- In Zed, accept the development-container prompt or run
  `projects: open dev container`.

The container provides the C++ toolchain, CMake, Ninja, and GNU Make. From the
repository root, use:

```sh
make build
make run
make test
```

`make clean` removes the `build/` directory. The next build will configure the
project again and may download Catch2.

## Test-driven development

1. Add a test in `tests/` that describes the behavior you want.
2. Run `make test` and confirm that the test fails for the expected reason.
3. Implement the behavior in `src/` or `include/`.
4. Run `make test` again and keep the tests passing as you refactor.

## Architecture decisions

Read the records in [`docs/adr/`](docs/adr/) before changing the build system,
tools, test setup, or CI. To change a decision, write a new ADR with status
`Proposed` and ask the maintainer; do not mark an ADR `Accepted`.

## Submitting a change

Open a pull request using the repository's pull request template. Include a
summary of the change and how you tested it.
