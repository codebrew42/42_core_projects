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