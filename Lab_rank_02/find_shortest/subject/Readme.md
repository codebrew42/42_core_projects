# One Stroke Quest

## Concept of the game
- The user should draw a path with one stroke in a given time
- the path should be the shortest, if not, the game is over
- the game should be more difficult as the level goes up

## user input
- WASD, arrow keys
- mouse can move one step further

## shortest path
- if the map is read, the shortest way is saved in advance
- if the users movement is correct, nothing happens, if not, the game is over

## graphic
- minilibx

# code
## structure
### main 
(1) validaate
- check argv is given
- check if the map is valid
- check if there is single or multiple shortest path of the given map

(2) open the window and display the map on it
- measure the size of the given map
- using the given graphic files, display the map and the player

(2) get user input
- loop will be maintained, moves unless ESC, or cross is pressed
