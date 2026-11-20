# Domain model

The camera creates a ray for each pixel and asks `trace` for its colour.
`trace` asks the `Scene` for the nearest hit, then asks the hit's `Material`
to shade it using the surface normal and the scene's direction towards the
light. The scene owns its shapes. Each shape has a material; a sphere and a
plane are the current shapes. A miss gives black. The camera stores the
resulting colours in an `Image`, and a saver writes it to a file.

```mermaid
classDiagram
    class Camera {
        +render(scene, width, height) Image
    }
    class Scene {
        +toLight() Vector
        +add(shape) void
        +nearestHit(ray) optional~Hit~
    }
    class Shape {
        <<abstract>>
        +hit(ray) optional~Hit~
    }
    class Sphere {
        +centre Vector
        +radius double
        +hit(ray) optional~Hit~
    }
    class Plane {
        +point Vector
        +normal Vector
        +hit(ray) optional~Hit~
    }
    class Material {
        +colour() Colour
        +shade(normal, toLight) Colour
    }
    class Hit {
        +t double
        +point Vector
        +normal Vector
        +material Material
    }
    class Image {
        +pixel(column, row) Colour
        +setPixel(column, row, colour) void
    }
    class Colour
    class Vector
    class ImageSaver {
        <<abstract>>
        +save(image, path) void
    }
    class PngSaver {
        +save(image, path) void
    }

    Scene *-- "many" Shape : owns
    Sphere --|> Shape : implements
    Plane --|> Shape : implements
    Sphere *-- Material : has
    Plane *-- Material : has
    Hit --> Material : carries
    Scene --> Vector : light direction
    Camera ..> Scene : renders
    Camera ..> Image : produces
    Image *-- Colour : one per pixel
    Material ..> Colour : shades
    Material ..> Vector : uses
    Shape ..> Hit : returns
    ImageSaver ..> Image : saves
    ImageSaver <|-- PngSaver : implements
```

`Shape::hit` returns the nearest hit in front of the ray origin, with a unit
normal, or no hit. `Sphere` and `Plane` implement that contract. `Scene`
compares the hits from all its shapes and keeps the nearest one. `Material`
holds a surface colour and applies Lambert's law. `Image` stores one `Colour`
per pixel, addressed by column and row from the top left. `ImageSaver` defines
the saving contract; `PngSaver` writes the whole image to the requested path
or throws `std::runtime_error`, so `Image` does not need to know about file
formats.
