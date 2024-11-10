# related to : so_long

Let me explain the difference between using `.` and `->` in C:

### Syntax Rules
1. `.` (dot) is used when accessing members of a struct directly
2. `->` (arrow) is used when accessing members through a pointer to a struct

### Examples:

````c
// Example 1: Direct struct (using .)
typedef struct s_game
{
    t_image images;  // Direct struct, not a pointer
}   t_game;

game->images.wall   // Correct! Because 'images' is a struct, not a pointer


// Example 2: Pointer to struct (using ->)
typedef struct s_game
{
    t_image *images;  // Pointer to struct
}   t_game;

game->images->wall  // Correct! Because 'images' is a pointer
````

### Why use direct struct (`.`) in this case?
1. No need for additional memory allocation
2. Guaranteed memory contiguity
3. One less pointer to manage
4. No risk of null pointer for the structure itself

### Memory visualization:
```
Direct struct (using .):
t_game {
    ├── other_members
    └── images {         // Directly embedded in t_game
        ├── wall
        ├── player
        └── ...
    }
}

Pointer to struct (using ->):
t_game {
    ├── other_members
    └── images --------→ t_image {    // Separate allocation
        ├── wall
        ├── player
        └── ...
    }
}
```

In your case, since you don't need to dynamically allocate/free the image structure separately, using a direct struct member (`.`) is the better choice!