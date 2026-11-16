# Discovery report

## Problem statement

A Los Angeles film studio cannot rely on its previous renderer, which was too expensive and produced image defects that nobody could explain, to deliver high-quality images from software that its teams can understand, debug and maintain over time.

## Client interview summary

> Note: questions and answers are written from my interview notes, as close to the original words as I can.

### Reliability and ease of debugging

**Need:** The renderer must be reliable, and when something goes wrong in an image, the team must be able to understand why and fix it.

> **Q (me):** "What is the one thing you are looking for in this project that would make you say: this is exactly what I need?"
>
> **A:** "Reliability and ease of debugging. In our previous project there were black dots in the images, and nobody could tell us why."

**My conclusion:** The black dots are a rendering defect, but the bigger problem for the client is that nobody could explain them. The client values understanding the software as much as the result itself. Our renderer must make problems easy to investigate: clear and documented code, tests for each part (ray–sphere intersection, shadows, lighting), clear error messages, and debug tools such as rendering only one pixel or saving intermediate information (normals, hit distance) as images. In ray tracing, isolated black pixels often come from numerical errors, for example a shadow ray hitting the surface it starts from, or invalid values such as NaN, so floating-point precision must be handled carefully and tested.

### Cost

**Need:** The new solution must cost significantly less than the previous one.

> **Q (a classmate, paraphrased):** "Why do you want a new renderer instead of keeping your current one?"
>
> **A:** "The old product cost us a lot of money, it is too expensive."

**My conclusion:** Cost is a main reason for the project. An open source renderer avoids per-seat licence fees, but the cost also includes computing time: the faster the renderer, the fewer machines and hours the studio pays for.

### Expected quality level

**Need:** The images must be of high quality, suitable for cinema.

> **Q (a classmate, paraphrased):** "What level of image quality do you expect?"
>
> **A:** "High quality."

**My conclusion:** "High quality" is not measurable yet. I need to turn it into criteria: resolution, acceptable noise level, and absence of artifacts.

### Maintainability

**Need:** The software must stay maintainable over time.

> **Q (a classmate, paraphrased):** "What matters most to you in the long term?"
>
> **A:** "We want it to be maintainable."

**My conclusion:** This matches the course context: software that works in a demo but that nobody can maintain is a failure for this client. It means clear architecture, tests, documentation and recorded design decisions (ADRs).

### Open questions

- **"High quality":** which resolution (HD, 4K)? How much noise is acceptable? Who decides that a frame is good enough?
- **Black dots:** did they appear in every scene or only in some (reflections, shadows, specific materials)? Do they have example images? How did the team try to debug them?
- **Ease of debugging:** what tools or information would the client's team expect when a frame is wrong (logs, debug images, re-rendering a single pixel)?
- **Cost:** what was too expensive exactly: licences, computing machines, or the time spent by the teams? What budget is acceptable?
- **Maintainability:** who will maintain the code (the studio, partner studios, us)? What would show that it is no longer maintainable?
- **Possible contradiction:** the client wants high quality but lower cost. High quality usually means more rays per pixel, so more computing time and more cost. The priority between quality, speed and cost must be clarified.

## State of the art

| Solution | Maker | Licence | Pricing (date checked) | Capabilities | Sources |
|---|---|---|---|---|---|
| Arnold | Autodesk | Proprietary, subscription | About $476 per year for 1 seat, through a reseller (CDW). Autodesk does not show the price on its own page. (2026-11-16) | Production renderer used in film and VFX, CPU and GPU, integrated with Maya, 3ds Max, Houdini | [Autodesk Arnold](https://www.autodesk.com/products/arnold/buy), [CDW](https://www.cdw.com/product/arnold-2026-new-subscription-annual-1-seat/8331003) |
| RenderMan | Pixar | Proprietary. Free non-commercial version | $595 per licence, plus $250 per year for maintenance. Rental: $5 per licence per day. (2026-11-16) | Pixar's film renderer, hybrid CPU/GPU (XPU), includes the Tractor render farm manager | [RenderMan store](https://renderman.pixar.com/store/) |
| V-Ray | Chaos | Proprietary, subscription | Solo: $432 per year. Premium: $623.04 per year. Collection: $968.64 per year (prices shown with a discount). (2026-11-16) | Widely used in architecture and VFX, CPU and GPU, many 3D software integrations | [Chaos V-Ray](https://www.chaos.com/vray/buy-online) |
| Cycles | Blender Foundation | Open source (Apache 2.0) | Free (2026-11-16) | Path tracer built into Blender, CPU and GPU, can be used outside Blender | [Blender Cycles licence](https://code.blender.org/2013/08/cycles-render-engine-released-with-permissive-license/) |
| pbrt-v4 | Pharr, Jakob, Humphreys | Open source (Apache 2.0) | Free (2026-11-16) | Research and teaching renderer, spectral rendering, GPU on NVIDIA (CUDA/OptiX), documented in the book *Physically Based Rendering* | [pbrt-v4 on GitHub](https://github.com/mmp/pbrt-v4) |

Commercial renderers are mature and used in real productions, but they are paid per seat or per licence, and the cost grows with the number of machines in a render farm. This matches the client's complaint that their previous product was too expensive. They are also closed source: when a commercial renderer produces a defect, the studio cannot look inside the code to find the cause, which is exactly what happened with the black dots. Open source renderers are free, but Cycles is designed mainly around Blender, and pbrt-v4 is designed for teaching and research rather than for a studio pipeline. None of them is designed for this client's specific needs: a renderer that is cheap to run, that partner studios can contribute to, and whose code stays maintainable.

## What is ray tracing?

Ray tracing is a way to create an image of a 3D scene by simulating light. The input is a description of the scene: objects (for example a sphere and a floor), their materials, the light sources and a camera. The output is an image, which is a grid of pixels. In between, for each pixel, the program sends a ray (a straight line) from the camera through that pixel into the scene, and finds the first object the ray hits. Then it checks how that point is lit: if a ray from that point towards the light is blocked by another object, the point is in shadow and gets a darker colour. The colour found becomes the colour of the pixel. When every pixel is done, the image is complete. A film is a sequence of these images, so the same work is repeated for every frame.

**Sources:** I started from *Ray Tracing in One Weekend* by Peter Shirley ([raytracing.github.io](https://raytracing.github.io/)). The reference I would come back to is *Physically Based Rendering* by Pharr, Jakob and Humphreys ([pbr-book.org](https://pbr-book.org/)).

## What is C++?

### Programming paradigms

C++ supports several paradigms. It is procedural like C: you can write functions that run step by step. It is object-oriented like Java or Python: you can group data and behaviour in classes, use encapsulation, inheritance and polymorphism. It is also generic: templates let you write code once for several types. Compared to Python, it is compiled and statically typed, so many errors are found before the program runs, and the program is usually much faster.

### What to watch out for

C++ gives a lot of control to the developer, and so a lot of responsibility. Memory can be managed by hand, which can cause memory leaks or crashes if memory is used after being freed. Some mistakes, such as reading outside an array, cause "undefined behaviour": the program may seem to work and then fail later. Modern C++ reduces these risks with smart pointers (`std::unique_ptr`, `std::shared_ptr`) and standard containers (`std::vector`). Floating-point precision also matters for a ray tracer, because small errors can create visual defects such as the black dots the client described.

### Shaping the domain model

The domain is easy to describe with objects: a scene contains objects, lights and a camera; a ray has an origin and a direction; a hit records where a ray touched an object. Polymorphism fits shapes and materials well: a common `Shape` interface with an intersection method, implemented by `Sphere`, `Plane`, and later other shapes. This is also where partner studios could add new shapes or materials without changing existing code. Small mathematical types, such as vectors and colours, should be simple value types, because they are created millions of times and must stay fast.

**Sources:** I started from [learncpp.com](https://www.learncpp.com/). The references I would come back to are [cppreference.com](https://en.cppreference.com/) and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/).
