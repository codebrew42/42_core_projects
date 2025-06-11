# pixel
## RECOMMENDED: 
Keep image sizes as powers of 2 (32x32, 64x64) for better performance


## case: rendering diff pixels

### conclusion : 
it is okay to have diff pixels XPM, it will be rendered.
but its better to match the disp size for better performance

in the main function : settiing 40 * 40
	// Initialize MLX (graphics library)
    game.mlxpointer = mlx_init();
    
    // Create window (map width * 40 pixels by map height * 40 pixels)
    game.winpointer = mlx_new_window(game.mlxpointer, 
        (game.widthmap * 40), (game.heightmap * 40), "solong");
    

however, actual XPM files has 50  * 50

	void place_images_in_game(t_complete *game)
	{
		int img_width;
		int img_height;

		game->floor = mlx_xpm_file_to_image(game->mlxpointer,
				"game_images/floor.xpm", &img_width, &img_height);
		// ... rest of the code
	}
	/* XPM */
	static char *result[] = {
	/* columns rows colors chars-per-pixel */
	"50 50 80 1 ",