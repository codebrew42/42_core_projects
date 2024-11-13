updated: 24.10.30

# to fix

## (1) \n
my_tester/main.c

	printf("hi\n");
	printf("%d", 100);

-> result: hi100 
\n is not included


## (2) %d, next things of specifier does not appear

	char last_char = game->map[game->map_row - 1][game->map_column - 1];
	ft_printf("ASCII value of last char: (%d)\n\n", last_char);
	ft_printf("last line of the map: (%s)\n\n", game->map[game->map_row - 1]);
	ft_printf("last char of the map: (%c)\n\n", last_char);cur row: 4 C/P/E: 2 1 1

#output
ASCII value of last char: (10

last line of the map: (11111111111111111111


last char of the map: (


##(3) %3d function

code
	void	print_int_map(int **map, t_game *game)
{
	int	i;
	int j;
	int	rows = game->map_row;
	int	cols = game->map_column;


	i = 0;
	ft_printf("\npath finding map\n");
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] > 0)
				ft_printf("(%3d,%3d)+%d ", i, j, map[i][j]);
			else
				ft_printf("(%3d,%3d)%d ", i, j, map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\nFinished printing map\n");
}

path finding map
(d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 (d,d)0 
(d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 (d,d)1 
(d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 (d,d)2 
(d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 (d,d)3 
(d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 (d,d)4 

=> d,d should be index(0,0) (0,1)...