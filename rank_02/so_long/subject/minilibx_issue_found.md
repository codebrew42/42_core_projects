# why it causes valgrind error (X11 Error)

## code
	game->mlx_pointer = mlx_init();
	if (!game->mlx_pointer)
		return (clean_exit(-1, game, NULL, "MLX init failed"));
	game->window_pointer = mlx_new_window(game->mlx_pointer, 
		game->map_row * 32, game->map_column * 32, "so_long");
	if (!game->window_pointer)
		return (clean_exit(-1, game, NULL, "Window creation failed"));

this part caused error

## err msg
	==22864== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==22864== Command: ./so_long maps/map1-2.ber
==22864== 
adr:0x15adr:0x15adr:0x15adr:0x15adr:0x15row(0): C/P/E: 0/0/0    row(1): C/P/E: 0/0/0    row(2): C/P/E: 0/0/0 row(3): C/P/E: 2/1/0    row(4): C/P/E: 2/1/1    ==22864== Syscall param writev(vector[0]) points to uninitialised byte(s)
==22864==    at 0x4B4B610: writev (writev.c:26)
==22864==    by 0x4C2C51B: ??? (in /usr/lib/aarch64-linux-gnu/libxcb.so.1.1.0)
==22864==    by 0x4C2C6D3: ??? (in /usr/lib/aarch64-linux-gnu/libxcb.so.1.1.0)
==22864==    by 0x4C2D88F: xcb_writev (in /usr/lib/aarch64-linux-gnu/libxcb.so.1.1.0)
==22864==    by 0x4941B1F: _XSend (in /usr/lib/aarch64-linux-gnu/libX11.so.6.4.0)
==22864==    by 0x494676F: _XReadEvents (in /usr/lib/aarch64-linux-gnu/libX11.so.6.4.0)
==22864==    by 0x4946A8F: XWindowEvent (in /usr/lib/aarch64-linux-gnu/libX11.so.6.4.0)
==22864==    by 0x10B44B: mlx_int_wait_first_expose (in /home/jin/coding/42_core_projects_git/rank_02/so_long/code/so_long)
==22864==    by 0x10B31B: mlx_new_window (in /home/jin/coding/42_core_projects_git/rank_02/so_long/code/so_long)
==22864==    by 0x109883: main (in /home/jin/coding/42_core_projects_git/rank_02/so_long/code/so_long)
==22864==  Address 0x4d4293c is 28 bytes inside a block of size 16,384 alloc'd
==22864==    at 0x488C0AC: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-arm64-linux.so)
==22864==    by 0x4930617: XOpenDisplay (in /usr/lib/aarch64-linux-gnu/libX11.so.6.4.0)
==22864==    by 0x10B0E7: mlx_init (in /home/jin/coding/42_core_projects_git/rank_02/so_long/code/so_long)
==22864==    by 0x109817: main (in /home/jin/coding/42_core_projects_git/rank_02/so_long/code/so_long)
==22864== 
suc==22864== 
==22864== HEAP SUMMARY:
==22864==     in use at exit: 71,269 bytes in 63 blocks
==22864==   total heap usage: 524 allocs, 461 frees, 82,794 bytes allocated
==22864== 
==22864== LEAK SUMMARY:
==22864==    definitely lost: 136 bytes in 1 blocks
==22864==    indirectly lost: 1,096 bytes in 2 blocks
==22864==      possibly lost: 0 bytes in 0 blocks
==22864==    still reachable: 70,037 bytes in 60 blocks
==22864==         suppressed: 0 bytes in 0 blocks
==22864== Rerun with --leak-check=full to see details of leaked memory


## notes (from claude-3.5)

The error you're seeing isn't actually from those lines directly, but it's related to how the MLX library interacts with the X11 system on Linux. Let's break down what's happening:

```c
game->mlx_pointer = mlx_init();
game->window_pointer = mlx_new_window(game->mlx_pointer, game->map_row * 32,
        game->map_column * 32, "so_long");
```

The error message shows:
```
==22473== Syscall param writev(vector[0]) points to uninitialised byte(s)
```

This is happening because:

1. **Memory Management Issue:**
   - The error is coming from the X11 system's internal workings
   - It's a common and generally harmless warning when using MLX with X11 on Linux
   - It's related to how the X11 window system handles some uninitialized memory during window creation

2. **Why It's Not Critical:**
   - This is actually a known issue with the MLX library on Linux
   - It doesn't affect the functionality of your program
   - The warning comes from Valgrind being very strict about memory initialization

3. **How to Handle It:**
   - For the 42 project, you can safely ignore this specific warning
   - If you want to suppress it in Valgrind, you can create a suppression file
   - The more important issues to focus on are the memory leaks shown in the leak summary:
     ```
     definitely lost: 136 bytes in 1 blocks
     indirectly lost: 1,096 bytes in 2 blocks
     ```

4. **What You Should Fix:**
   - Instead of focusing on the X11 warning, you should add proper cleanup for MLX:
   ```c
   int main(int ac, const char **av)
   {
       t_game *game;

       if (ac != 2)
           return (report_error("Usage: ./so_long map.ber"));
       if (init_game(&game))
           return (1);
       if (is_valid_map(game, av[1]))
           return (1);
       if (read_map(game, av[1]))
           return (1);
       
       game->mlx_pointer = mlx_init();
       if (!game->mlx_pointer)
           return (clean_exit(-1, game, NULL, "MLX init failed"));
           
       game->window_pointer = mlx_new_window(game->mlx_pointer, 
           game->map_row * 32, game->map_column * 32, "so_long");
       if (!game->window_pointer)
           return (clean_exit(-1, game, NULL, "Window creation failed"));

       // Add your mlx_loop here before cleaning up
       
       free_game(game);
       return (0);
   }
   ```

The main focus should be on properly handling memory allocation/deallocation and adding error checks for MLX functions, rather than worrying about the X11 warning from Valgrind.