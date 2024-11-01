# so_long @42_berlin

the very first 2D game project

## Table of Contents

- [Installation](#installation)
- [Introduction](#introduction)
- [Bonus](#bonus)
- [Technical Issues](#technical-issues)
- [Checklist](#checklist)

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>

2. 
	The executable file *so_long* will receive a map as the only argument, which has *.ber* datatype.

## Introduction

This project is about to build a simple 2D game, which aims to get familiar with mlx library, UI, and so on.

### Graphic management
- the management of the window(changing to another, minimizing, ...) should remain smooth
- if *ESC/Q* is pressed, the game is terminated.
- clicking on the cross on the window's frame must close it and quit the program in a clean way
- must use *images* of *MiniLibx*

### Maps
If the map doesn't follow any of these rules, the game must be terminated with a message *Error\n*. 
- contains only 5 characters which are *P*(pacman), *1*(wall), *0*(empty), *C*(collectible), and *E*(Exit)
- has to have at least one *P*, one *E*, and one *C*
- must not have duplicate characters: *E*, *P*
- must be rectangular, so all rows have the same length.
- must be closed, which means being surrounded by walls

### Player's goal
- has to collect all the *C*, and then go to *E*
- with the least possible number of steps.

### how players move
- *W*, *A, *S*, *D* lead the player to that directions untill it encounters any wall.
- Using *W*, *A, *S*, *D* is mandatory, but you can use arrow keys too.
- Player is not able to move into walls
- the number of movements must be displayed in the shell

## Bonus

### 1. Enemy patrol
- the player lose when they meet enemies

### 2. sprite animation
- add some sprite animation

### 3. movement count
- display it directly on screen instead of the shell

## Technical Issues

## Checklist
- to pass it in 42
1. check: map's validity
2. check: whether it's possible to parse any kind of map which respects the (#Maps) rules.
3. check: whether the program exit in a clean way and return 'Error\n', in case it encounters any misconfiguration in the file.
