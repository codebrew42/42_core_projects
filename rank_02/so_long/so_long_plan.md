# websites
https://thegimptutorials.com/how-to-make-pixel-art/
https://itch.io/
https://opengameart.org/
https://jamiecross.itch.io/8-bit-dungeon-tilesetsprites
https://overboundn.itch.io/sonic-time-twisted-> wow...
https://github.com/overbound/SonicTimeTwisted

## directly related
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

# structure
## general
/root of so_long  
so_long  
├── code  
│ ├── includes  
│ │ └── so_long.h  
│ ├── libft  
│ │ ├── ft_printf  
│ │ │ ├── includes  
│ │ │ │ └── ft_printf.h  
│ │ │ ├── ft_printf.c  
│ │ │ └── printing_utils.c  
│ │ ├── get_next_line  
│ │ │ ├── includes  
│ │ │ │ └── get_next_line.h  
│ │ │ ├── get_next_line.c  
│ │ │ └── get_next_line_utils.c  
│ │ ├── includes  
│ │ │ └── libft.h  
│ │ ├── Makefile  
│ │ └── .c (libft source files)  
│ ├── minilibx-linux  
│ │ └── (MLX library files)  
│ ├── maps  
│ │ └── .ber  
│ ├── src  
│ │ ├── main.c  
│ │ └── utils.c  
│ └── Makefile  
└── README.md  



# compilation

## code_linux
gcc main.c mlx_linux/libmlx_Linux.a  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

jin@jin:~/coding/42_core_projects_git/rank_02/so_long/code_linux$ gcc main.c utils.c -Lmlx_linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz
/usr/bin/ld: /tmp/ccRPPRJ3.o: in function `read_map':
main.c:(.text+0x78): undefined reference to `ft_strcmp'
/usr/bin/ld: main.c:(.text+0xac): undefined reference to `get_next_line'
/usr/bin/ld: /tmp/ccJbxBbi.o: in function `report_error':
utils.c:(.text+0x18): undefined reference to `ft_printf'
collect2: error: ld returned 1 exit status


# guide
## version1
To analyze the structure of the provided codebase and outline the steps involved in its operation, we can break it down into several key components and processes. The code appears to be a game, likely a variant of Pac-Man, implemented in C using the MiniLibX library for graphics. Here’s a structured analysis:

### 1. **File Structure Overview**
- **Source Files (`src/`)**: Contains the main game logic, rendering, player management, and animations.
  - `anim_dir.c`: Handles animations for different directions and panic mode.
  - `ghosts.c`: Manages ghost behavior and interactions.
  - `pacman.c`: Manages Pac-Man's behavior and animations.
  - `render_linux.c` and `render_mac.c`: Handle rendering logic for different operating systems.
  - `playerlist.c`: Manages the linked list of players and ghosts.
  - `load_dir.c`: Loads sprite images for different directions.
  - `game_linux.c` and `game_mac.c`: Contains the main game loop and event handling.
  - `utils.c`: Contains utility functions.
  
- **Header Files (`inc/`)**: Define structures, function prototypes, and constants used throughout the game.
  - `game.h`: Main header for game-related structures and function prototypes.
  - `map.h`: Defines layout properties and error handling for the game map.
  - `check.h`: Functions for checking and validating the game map.
  - `colors.h`: Defines color codes for console output.

- **Makefile**: Automates the build process, compiling the source files into an executable and managing dependencies.

### 2. **Key Components**
- **Game Structures**: (in game.h)
  - `t_game`: Main structure holding game state, including player and ghost lists, map, and graphical elements.
  - `t_player`: Represents a player (Pac-Man or ghost) with position, direction, and sprite information.
  - `t_lay`: Represents the layout of the game map.
  
- **Sprite Management**: Functions to load and manage sprites for different characters and animations.

- **Game Logic**: Functions to handle player movement, ghost behavior, collision detection, and game state updates.

### 3. **Game Flow Steps**
1. **Initialization**:
   - The game starts by initializing the game state, loading the map, and setting up the graphical window.
   - Sprites for Pac-Man and ghosts are loaded.

2. **Event Handling**:
   - The game listens for keyboard events (e.g., movement keys) and updates the direction of Pac-Man accordingly.
   - The game can be reset or exited based on user input.

3. **Game Loop**:
   - The main game loop runs continuously, performing the following steps:
     - **Input Handling**: Check for user input and update game state.
     - **Game Logic Update**: Update positions of Pac-Man and ghosts based on their current directions and handle collisions.
     - **Rendering**: Clear the window and redraw the game state, including the map, players, and any collectibles.
     - **Animation**: Update animations for Pac-Man and ghosts based on their states (moving, stopped, etc.).

4. **Collision Detection**:
   - Check for collisions between Pac-Man and ghosts, as well as between Pac-Man and collectibles or exits.
   - Handle game-over conditions if Pac-Man collides with a ghost.

5. **Game End**:
   - When the game ends (either by winning or losing), free allocated resources and display the final score or message.

### 4. **Compilation and Execution**
- The Makefile automates the compilation process, ensuring all source files are compiled into object files and linked into a final executable.
- The game can be run with different maps, and the Makefile includes targets for testing and cleaning up build artifacts.

### Conclusion
This codebase represents a structured approach to developing a 2D game using C, with clear separation of concerns through the use of multiple source files and header files. The game loop and event handling are central to the gameplay experience, while the Makefile facilitates easy compilation and management of the project.

## version 2
The code you've provided is a simple game called "so_long," which is built using the MinilibX graphics library. The game involves navigating a player character through a map, collecting items, and reaching an exit. Below is an analysis of the structure of the program, along with steps to code a simplified version.

### Structure of the Program

1. **Header Files**:
   - **`mlx.h`**: Contains declarations for the MinilibX graphics library functions.
   - **`so_long.h`**: Contains the main game structure and function declarations.
   - **`get_next_line.h`**: Contains declarations for reading lines from a file.

2. **Source Files**:
   - **`game_logic/*.c`**: Contains the core game logic, including:
     - **`map.c`**: Handles reading the map from a file and storing it in memory.
     - **`errors.c`**: Validates the map structure and checks for errors.
     - **`controls.c`**: Handles player movement and controls.
     - **`graphics.c`**: Manages rendering images to the window.
     - **`so_long.c`**: The main entry point of the program, initializes the game and starts the loop.

3. **Utility Files**:
   - **`get_next_line/*.c`**: Implements functions to read a line from a file, which is used to read the game map.

4. **Makefile**: Automates the build process, compiling the source files and linking them with the MinilibX library.

5. **Game Map**: A text file (`map1.ber`) that defines the layout of the game, including walls, the player, collectables, and the exit.

### Steps to Code a Simplified Version

1. **Define the Game Structure**:
   - Create a structure to hold game state information (e.g., player position, map data).

2. **Initialize the Graphics Library**:
   - Set up the MinilibX library to create a window for the game.

3. **Load the Game Map**:
   - Implement a function to read the map from a file and store it in a suitable data structure (e.g., a 2D array).

4. **Render the Game**:
   - Create a function to draw the game elements (walls, player, collectables, exit) on the screen.

5. **Handle Player Input**:
   - Implement functions to respond to keyboard inputs for moving the player character.

6. **Check for Game Conditions**:
   - Add logic to check if the player has collected all items and reached the exit.

7. **Clean Up Resources**:
   - Ensure that all allocated memory is freed and the window is closed when the game ends.

### Example Code Structure

Here’s a simplified version of how you might structure the code:

```c
// main.c
#include "so_long.h"

int main(int argc, char **argv) {
    // Initialize game state
    // Load map
    // Initialize graphics
    // Game loop
    // Handle input
    // Render graphics
    // Clean up
    return 0;
}

// so_long.h
#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>

typedef struct s_game {
    void *mlx_ptr;
    void *win_ptr;
    char **map;
    int player_x;
    int player_y;
    // Other game state variables
} t_game;

void load_map(t_game *game, const char *filename);
void render(t_game *game);
void handle_input(t_game *game, int keycode);

#endif

// game.c
#include "so_long.h"

void load_map(t_game *game, const char *filename) {
    // Read the map from the file and store it in game->map
}

void render(t_game *game) {
    // Draw the map and player on the window
}

void handle_input(t_game *game, int keycode) {
    // Update player position based on input
}
```

### Summary

To create a simplified version of the "so_long" game, focus on the core functionalities: initializing the graphics, loading the map, rendering the game state, handling player input, and checking game conditions. Start with a basic structure and gradually add features as you become more comfortable with the code.


# 1. Where is `t_game` Defined?

The `t_game` structure is defined in the `game.h` header file. Here’s a brief overview of its definition:

```c
typedef struct s_game
{
    int         width;          // Width of the game window
    int         height;         // Height of the game window
    void        *id;            // Pointer to the MLX instance
    void        *w_id;          // Pointer to the MLX window
    t_lay       *lay;           // Pointer to the layout structure
    t_lay       lay_bak;        // Backup of the layout
    t_sprite    sprites;        // Struct containing all sprite images
    t_player    *pl;            // Pointer to the linked list of players (Pac-Man)
    t_player    *gh;            // Pointer to the linked list of ghosts
    int         next_dir;       // Next direction for Pac-Man
    char        **map;          // 2D array representing the game map
    char        **map_bak;      // Backup of the game map
    int         n_collect_bak;  // Backup of the number of collectibles
    int         pac_dying;      // Flag indicating if Pac-Man is dying
    int         panic_mode;     // Flag indicating if panic mode is active
    int         n_frames;       // Frame counter for the game loop
    int         n_moves;        // Number of moves made in the game
    int         redraw;         // Flag indicating if the screen needs to be redrawn
    int         g_rate;         // Game rate for controlling speed
} t_game;
```

### Explanation of `t_game` Structure:
- **Purpose**: The `t_game` structure encapsulates all the necessary information and state for the game. It includes properties for the game window dimensions, the current state of the game (like the layout and player positions), and various flags to control game behavior.
- **Components**:
  - `width` and `height`: Define the dimensions of the game window.
  - `id` and `w_id`: Pointers to the MLX instance and window, which are used for rendering graphics.
  - `lay`: A pointer to the layout structure (`t_lay`), which contains information about the game map.
  - `sprites`: A structure that holds all the sprite images used in the game.
  - `pl` and `gh`: Pointers to linked lists of players (Pac-Man) and ghosts, respectively.
  - `next_dir`: Stores the next direction that Pac-Man will move.
  - `map` and `map_bak`: Represent the current game map and a backup of it.
  - `n_collect_bak`: Keeps track of the number of collectibles in the backup layout.
  - `pac_dying`: A flag indicating whether Pac-Man is in a dying state.
  - `panic_mode`: A flag indicating whether the game is in panic mode (when ghosts become more aggressive).
  - `n_frames`: A counter for the number of frames processed in the game loop.
  - `n_moves`: Counts the number of moves made by the player.
  - `redraw`: A flag indicating whether the game screen needs to be redrawn.
  - `g_rate`: Controls the speed of the game.

# 2. What is a Sprite?

A **sprite** is a two-dimensional image or animation that is integrated into a larger scene, often used in video games to represent characters, objects, or other visual elements. Sprites can be static images or animated sequences that change over time to create the illusion of movement.

#### Key Characteristics of Sprites:
- **2D Graphics**: Sprites are typically used in 2D games, where they represent characters, enemies, items, and other game elements.
- **Animation**: Sprites can be animated by displaying a sequence of images (frames) in rapid succession. For example, a walking character might have several frames showing different leg positions.
- **Layering**: Sprites can be layered on top of each other to create complex scenes. For instance, a background layer can be drawn first, followed by characters and foreground elements.
- **Interactivity**: Sprites can respond to user input or game events, such as moving when a player presses a key or changing appearance when a character takes damage.

#### In the Context of the Provided Code:
In the provided codebase, the `t_sprite` structure is defined in `game.h` and contains pointers to various sprite images used in the game:

```c
typedef struct s_sprite
{
    void        *logo;          // Pointer to the game logo sprite
    void        **wall;         // Pointer to an array of wall sprites
    void        *pacfood;       // Pointer to the sprite for collectible food
    void        *portal;        // Pointer to the exit portal sprite
    void        *pacman;        // Pointer to the Pac-Man sprite
    void        *pixels;        // Pointer to pixel data for rendering
    void        *black;         // Pointer to a black sprite (used for clearing)
    t_list      *pac_dying_bak; // List of sprites for Pac-Man's dying animation
    t_list      *pac_dying;     // List of sprites for Pac-Man's dying animation
    t_font      score_font;     // Font for displaying scores
} t_sprite;
```

### Explanation of `t_sprite` Structure:
- **Purpose**: The `t_sprite` structure is designed to hold references to all the graphical elements (sprites) used in the game. This allows for easy access and management of the visual components.
- **Components**:
  - `logo`: Represents the game's logo.
  - `wall`: An array of wall sprites used to render the game environment.
  - `pacfood`: Represents the collectible items (food) that Pac-Man can eat.
  - `portal`: Represents the exit portal sprite.
  - `pacman`: Represents the main character (Pac-Man) sprite.
  - `pixels`: May hold pixel data for rendering purposes.
  - `black`: A sprite used to clear or overwrite parts of the screen.
  - `pac_dying_bak` and `pac_dying`: Lists of sprites used for animating Pac-Man's death sequence.
  - `score_font`: Holds the font used for displaying scores in the game.

In summary, sprites are essential for creating the visual elements of a game, and the `t_sprite` structure in the provided codebase organizes and manages these graphical assets for the Pac-Man game.