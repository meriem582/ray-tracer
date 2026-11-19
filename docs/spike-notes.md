# Pinhole spike notes

## Completed

- [x] Organize source and tests by concept.
- [x] Test `Colour`, `Ray`, `Sphere`, and `Camera`.
- [x] Reject sphere intersections behind the ray origin.
- [x] Move the hit-colour-or-black decision into `trace` and test both cases.
- [x] Compare colours through a shared test helper, while keeping
  `test_colour.cpp`'s channel assertions against numeric values.
- [x] Remove the bootstrap greeting after replacing the demo.

## Parked

- [ ] `Sphere` owns a `Colour`; revisit when materials are introduced.
- [ ] `Sphere::isHitBy` returns only a boolean; return hit distance when the
  renderer needs to choose the nearest object.
- [ ] `trace` accepts one concrete `Sphere`; generalize when another shape is
  added.
- [ ] Add explicit tangent and eye-inside-sphere tests when those cases need
  specified behavior. The current code counts a tangent with positive `t` as
  a hit and counts an eye-inside-sphere hit when one root is positive.
- [ ] Replace the console pixel output when an `Image` is implemented.
- [ ] Name black as a background colour if that concept is needed in more than
  this one place.
- [ ] Decide with the client whether to constrain colour channels or reject a
  camera whose eye equals the screen centre.
- [ ] Test sphere intersection with a non-unit ray direction when that
  behavior needs direct coverage. The `Ray` test already checks storing a
  non-unit direction, but not intersection behavior.

## Rejected for now

- Keep repeated ray setup explicit in the tests. The coordinates make each
  scenario easy to read, and a shared fixture would hide those details.
