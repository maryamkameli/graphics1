# Project 1 – Interactive 2D Geometry

## Difficulties Encountered

Installing SDL3 + OpenGL was the first step. Then I learned how to read **P3 PPM**s. The interactions were straightforward. I did some web browsing to get an idea how to brighten the image and I used linear brightness adjustment. Finally, packaging for submission took a few tries.


## Original
<p align="center">
  <img src="original.png" alt="Original app screenshot" width="560">
</p>

## Interactions

**Translate** — click **inside** the square and drag.
<p align="center">
  <img src="translate.png" alt="Translate demo" width="560">
</p>

**Rotate** — click **near the edges** and drag.
<p align="center">
  <img src="rotate.png" alt="Rotate demo" width="560">
</p>

**Resize** — grab a **corner** and drag.
<p align="center">
  <img src="resize.png" alt="Resize demo" width="560">
</p>

**Reset** — press **r** to reset position, scale, and orientation.
<p align="center">
  <img src="demo.gif" alt="Short demo showing reset" width="560">
</p>

## Build & Run (macOS)

```bash
# 1) Compile GLAD
clang -c glad/glad.c -o build/glad.o

# 2) Build app (C++17, SDL3 + OpenGL)
clang++ -std=c++17 -Wall squareStarter.cpp build/glad.o \
  -I /opt/homebrew/include -L /opt/homebrew/lib \
  -lSDL3 -framework OpenGL \
  -o square

# 3) Run
./square



