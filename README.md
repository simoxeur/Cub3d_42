# Cub3D

This project is about creating a small 3D game in C using raycasting and the MLX42 library.  

in assossiation with: [Marin](https://github.com/marn11)

![Demo](demo.gif)

## How to Run

### 1. Clone MLX42

     git clone https://github.com/codam-coding-college/MLX42.git


### 2. Build MLX

     cd MLX42
     cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ .
     make
     cd ..

### 3. Build Cub3D

     make

### 4. Run the Game

     ./cub3D maps/map.cub

. Press space to take the Torch, look to Controls to know the keys



## Controls:

        Key               | Action
        W                 | Move Forth
        S                 | Move Back
        D                 | Move Right
        A                 | Move Left
        M                 | Enable and Disable the mouse use
        Space             | Take Up and Down The Torch
        right arrow       | Turn Right
        right arrow       | Turn Left
        Up arrow          | Speed Up
        Down arrow        | Speed Down
