# 0008: Save PNG files with LodePNG

## Context

The client needs images that open in ordinary viewers. PNG is lossless,
compressed, and includes checksums, so using a library is preferable to
writing the format ourselves.

The options compared were:

- **libpng:** The reference library since 1995, with a permissive libpng
  licence. It is not in the development container and its C API requires many
  calls to save one image. It is fast.
- **stb_image_write:** A single header from the stb collection, public domain.
  Its C API uses raw pointers and a `#define` that must appear in exactly one
  file. It requires no installation, is fast, and produces larger PNG files.
- **LodePNG:** One `.cpp` and one `.h`, under the permissive zlib licence, with
  no dependencies or installation. Its C++ API uses `std::vector`, but it is
  the slowest to save and produces the smallest files.
- **Writing PPM by hand:** Requires no library, but most viewers cannot open
  it and its files are much larger.

## Decision

Save images as PNG using LodePNG from
<https://github.com/lvandeve/lodepng>. Download it with CMake FetchContent,
like Catch2, and pin it to commit
`7b2893e35891c0c85bee5595caafaf3c2044b409` because it has no releases.

Only `src/output/` will use LodePNG, behind our own `ImageSaver` interface.
Changing the library or format will then require implementing one new class.

## Status

Proposed

## Consequences

PNG can be opened in ordinary viewers while preserving pixel values, and its
compression keeps files small. LodePNG requires no installation or additional
dependencies and provides a C++ interface based on `std::vector`.

LodePNG is slower at saving than the other libraries, though performance has
not yet been measured. Pinning a commit without releases makes upgrades
deliberate. `ImageSaver` adds an abstraction with only one implementation for
now, which is an additional interface to maintain.

## Alternatives considered

- **libpng:** Permissive licence and fast, but unavailable in the development
  container and has a multi-call C API.
- **stb_image_write:** Public domain, requires no installation, and is fast,
  but uses raw pointers and produces larger PNG files.
- **Writing PPM by hand:** No dependency, but limited viewer support and much
  larger files.
