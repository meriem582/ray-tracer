# 0010: A shape has a material

## Context

Shapes such as spheres and planes have geometry, while materials describe
their appearance and how they respond to light. Creating a separate shape
subclass for each material would multiply classes as new shapes and materials
are added.

## Decision

Each shape has one `Material` and includes it in the `Hit` it returns. A
material owns its surface colour and shading behaviour. Shapes delegate
shading to their material rather than inheriting from material-specific shape
classes.

## Status

Proposed

## Consequences

Shape and material choices remain independent: adding a shape or material
requires one class rather than a class for every combination. A shape can
change its material without changing its type. `Hit` carries a copy of the
material so rendering can shade the surface it intersected.

## Alternative considered

Use subclasses such as `MatteSphere`, `MirrorSphere`, `MattePlane`, and
`MirrorPlane`. This makes each combination a separate class and causes the
number of classes to grow with both the number of shapes and materials.
