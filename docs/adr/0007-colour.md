# 0007: Give Colour its own value type

## Context

`Vector` and `Colour` both contain three numeric components, but they represent
different concepts. A vector describes a direction or position and supports
geometric operations. A colour describes red, green, and blue channels. Using
one type for both would make it easier to apply vector operations where colour
semantics are intended.

## Decision

Represent colour with a separate `Colour` value type and named `r`, `g`, and
`b` accessors. `Sphere` holds a `Colour`, and `trace` returns a `Colour` for
the pixel. The planned `Image` model stores a `Colour` for each pixel.

## Status

Proposed

## Consequences

The type makes the distinction between geometry and appearance explicit.
Colour-specific operations can be added to `Colour` when rendering needs them;
vector operations are not automatically available for colours.

## Alternative considered

Use `Vector` for colour because both types have three numeric components. This
was not chosen because matching storage does not make their meanings or
operations interchangeable.
