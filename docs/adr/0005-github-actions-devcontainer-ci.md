# 0005: Run pull request checks in the development container

## Context

Partner studios need confidence that proposed changes build and pass tests. The repository already has a development container and `make test` command. An alternative is to configure CI to install and maintain a separate toolchain on the runner.

## Decision

Use GitHub Actions on pull requests and the `devcontainers/ci` action to run `make test` inside the repository's development container.

## Status

Proposed

## Consequences

Pull requests use the same container-based build and test setup as contributors. This adds a dependency on GitHub Actions, Docker-capable runners, and the external `devcontainers/ci` action, which must be maintained.
