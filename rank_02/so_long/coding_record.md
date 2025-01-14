# records

## 241104
- planning : [structrue](#structure)
- learning : how minilibx works

## 241106
- plan > check param, init map, validate map

## 241107
checking the map valid? -> str_cmp causes error
reading the map -> core_dump

### to learn
- .ber type

## 241108
### what i did
- reading map
- found issue : edge case(not ends with '\n' in the last line)
- ASCII for debugging : ASCII 0 = NULL, 10 = Newline/NL, 48 = 0, 49 = 1
- found error of my ft_printf 

### to do
- A1. deal with map0 cases(invalid), valgrind check (O)
- B1. fix ft_printf (of so_long, of rank_01) (O)

## 241109
### what i did
- reading map : almost finished (all the .ber file so far: 0-*, 1-*)
- found error of my gnl (both updated:rank01, solong)
- setting "net_len" improved my code (see: *has_invalid_wall()*)
- I still make mistakes about freeing, returning on error(sub func)

### to do
- A1. see the plan, plan again from [init_game](#init_game)
- B1. check more edge cases of .ber (slack)

## 241110
### what i did
- init window
- pixels : 32*32 recommended, matching XPM files' pixel is also recommended
- *Still reachable* prob of XLM
- when freeing double pointer: always set NULL str[i][j] level, and also str[i] level. both. -> it caused err
### to do
- B1. the window's shape does not match the maps shape
- A1. to see if it's fixable : - Still reachable prob of XLM
- A2. save image, using the example XPM files (I copied)

## 241111
### issues to fix
- .xpm : graphic only 1/4 shown, background not sync
- valgrind issue with valid maps : freeing?

### what i did
- pixel : set as 64*64 (128*128 didnt solve .xpm issue)

### to do
- A1. solve valgrind issue :  check free-game() (O)
- A2. validate map_path 
- B0. https://github.com/Vpekdas/so_long
- B1. right .xpm files update (O)
- B2. see K-blog on so_long
- B3. if(have time){bonus}


## 241112
### what i did
- valgrind issue (fixed)
- updated .xpm files

### what i learned
- on termination (suc&fail) ; if not exit(0), it causes leak

### what to do
- A2. validate map_path *till wednesday*
-> Thursday, get eval!, freez from friday?
- B1. see K-blog on so_long
- B2. if(have time){bonus}
: https://github.com/Vpekdas/so_long

# 241113
## what I did
- init3_path_check.c (ING)
-> DSF < BSF (more understandable)

## what to do
1. init3_ : finish
2. check eval sheet 

# 241114

## what I did
- init3_path_check.c (O)
- norminette(OK)
- checked all maps(group 1-4) (O)
- Bonus: display_score (O)

## what to do
1. check eval sheet
: if ctrl+c exit -> free : have to? then how?
2. bonus

## basic plan
(0) getting ready
- initializing the game (O)
- loading the map (ING: check more edge cases)

(1) visual part
- init graphical window using XML library (O)
- load images from XPMs-> save to t_game (O)
	*image pixel should be 32 * 32, set to be 32 * 32 too
- draw initial game state (ING: call appropriated .xpm)

(2)event/control part
- listen for events(keyboards/window) (O)
- update game state (O)
- redraw the screen when required (O)

(3)bonus part
- blinking images, sprite
- disp count on the window
- add monsters

[code]
    mlx_key_hook(game.winpointer, controls_working, &game);  // Keyboard input
    mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);      // Window close button
    mlx_loop(game.mlxpointer);  // Start the game loop

# plans
## param check -> map check (finished)

(1) param check
- argc = 2 
    -> fd = open(av[1], O_RDONLY)
    -> fd >= 0
    -> ft_strcmp(av[1], ".ber", 4)

(2) read map, errcheck map
- read_map()
    : get_next_line, line by line
        -> (1)add to map() (2)count> column, row, (3)free>last line, 
        -> if (!line)
                -> last line
                -> not last line : err
- errcheck_map()
    : missing_wall() 
        -> vertical_wall(), horizontal_wall()
    : character_check() 
        -> count nbr of each()
        -> errcheck : collectives > 1, player = 1, exit = 1

## init game

(1) save layout info: nubr of > row, col, exit, player, ghost, collectable
(2) save map
(3) save id = mlx_init()
(4) save window_id = mlx_new_window()
(5) save : nbr_frame, nbr_moves, width, height, layout, map, sprite,rate ...
(6) mlx_loop_hook(id, ...)
(6) mlx_hook(win_id, )
(7) mlx_key_hook(win_id, )
(8) mlx_loop(id, ...)

## put image, graphic
(1) save images
    t_complete->floor = mlx_xpm_file_to_image()
    + ->barrier/player/exit/collectable

(2) add images in graphics
    while(height < game->heigt_map)
        width = 0
        while(game->map[height][width])
            if == c/p/e/o/1
                mlx_put_image_to_window