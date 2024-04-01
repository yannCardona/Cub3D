# CUB3D Project
here is the full subject description: [en.subject.pdf](https://github.com/yannCardona/Cub3D/files/14260191/en.subject.pdf)

This Project is coded in C. It's inspired by the game Wolfenstein 3D.
The Project works as a Raycasting Game Engine, where you can upload different maps and textures and place different enemies.
The enemies follow you and you must not get catched by them. 

You can compile the Project with 'make' and run it with './cub3D labyrinth.cub'

The program takes a .cub file as parameter, which contains information about the textures and the map design:
  * 'S', 'W', 'N', 'E' indicate the starting position of the player depending on which direction he's facing (South, West, North, East). 
  * 'X' indicates the position of the enemy.
  * '1' indcate walls and '2' doors.

here is an example of a .cub file:

<img width="412" alt="Bildschirmfoto 2024-02-13 um 11 32 35" src="https://github.com/yannCardona/Cub3D/assets/119678666/25ee1ce6-f814-4645-9692-7d83916dc381">



here are some screenshots:

<img width="1280" alt="Bildschirmfoto 2024-02-13 um 11 25 42" src="https://github.com/yannCardona/Cub3D/assets/119678666/2ffe2196-e4d6-4d72-951c-a4bd4614418e">
<img width="1280" alt="Bildschirmfoto 2024-02-13 um 11 26 24" src="https://github.com/yannCardona/Cub3D/assets/119678666/db3e755b-a788-47f2-acd7-aa1099fc22cc">
