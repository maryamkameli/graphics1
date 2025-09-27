Here is the original picture
![App screenshot](original.png)

It can be translated to any location by clicking only inside the square.
![App screenshot](translate.png)

It can be rotated by any angle by clicking near the edges.
![App screenshot](rotate.png)

The picture can be resized by taking its corners and drag it.
![App screenshot](resize.png)

Here is a demo that I showed all the changes can be reset by pressing "r". 
![Short demo](demo.gif)

The code can be run by this command on macOS: 
clang -c glad/glad.c -o build/glad.o
clang++ -std=c++17 -Wall squareStarter.cpp build/glad.o \
  -I /opt/homebrew/include -L /opt/homebrew/lib \
  -lSDL3 -framework OpenGL \
  -o square
./square
