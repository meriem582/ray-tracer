# 0001: Use a development container

## Context

The project should use the same C++ tools across contributors' computers. The repository provides a Debian 12 development-container image with a C++ compiler, CMake, and Ninja. An alternative is to install and maintain a local toolchain on each computer.

## Decision

Provide a development container for VS Code and Zed, using the Debian 12 C++ image.

## Status

Proposed

## Consequences

Contributors can share a consistent toolchain. They need Docker and must download the container image; local toolchains remain an option.
