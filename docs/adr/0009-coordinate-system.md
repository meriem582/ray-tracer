# 0009: Use a consistent coordinate system

## Context

The camera maps image pixels to points on the screen. Image columns and rows
are counted from the top left, so both indices increase rightward and
downward. World coordinates need an explicit convention so that this mapping
does not reverse an axis by mistake.

## Decision

Use x to the right, y up, and positive z forward. Count image pixels from the
top left, with columns increasing to the right and rows increasing downward.
Map each pixel's centre to the screen, reversing the row direction when
calculating its world-space y coordinate.

## Status

Proposed

## Consequences

The convention keeps world-space y increasing upward while image rows increase
downward; the camera must account for that inversion when generating rays.
Using positive z as forward is consistent with the pinhole spike and the
current camera setup. Pixel-centre and off-centre ray tests record the mapping.

## Alternative considered

Use negative z as the forward viewing direction, as in *Ray Tracing in One
Weekend*. This was not chosen because the project's pinhole spike already uses
positive z as forward.
