# Freeing Integer Arrays in C

## Overview
This document discusses the implementation of a function to print a 2D integer array (specifically, an array of integers) in C. It highlights the correct and incorrect ways to iterate through the array and the potential pitfalls that can lead to errors.

## Correct Implementation
```c
void	print_int_map(int **map, t_game *game)
{
	int	i;
	int j;
	int	rows = game->map_row;      // Get the number of rows from the game structure
	int	cols = game->map_column;   // Get the number of columns from the game structure

	i = 0;
	ft_printf("\npath finding map\n");
	while (i < rows)  // Iterate through each row
	{
		j = 0;
		while (j < cols)  // Iterate through each column in the current row
		{
			ft_printf("(%zu,%zu)%d ", i, j, map[i][j]);  // Print the current element
			j++;
		}
		ft_printf("\n");  // New line after each row
		i++;
	}
	ft_printf("\nFinished printing map\n");
}
```
### Explanation
- **Row and Column Count**: The function retrieves the number of rows and columns from the `game` structure, ensuring that it knows the dimensions of the array it is working with.
- **Safe Iteration**: The loops use the row and column counts to safely iterate through the array, preventing out-of-bounds access.

Yes, the second implementation you provided is still incorrect for the same reasons as before. Let's break down the issues with both implementations and clarify why they are problematic.

### Issues with the Incorrect Implementation

```c
void	print_int_map(int **map, t_game *game)
{
	int	i;
	int j;

	i = 0;
	ft_printf("\npath finding map\n");
	while (map[i])  // Incorrect: This condition is problematic
	{
		j = 0;
		while (map[i][j])  // Incorrect: This condition is also problematic
		{
			ft_printf("(%zu,%zu)%d ", i, j, map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\nFinished printing map\n");
}
```

### Problems

1. **Loop Condition for Rows**:
   - The condition `while (map[i])` assumes that `map` is null-terminated, which is not a standard practice for 2D arrays of integers. This can lead to accessing memory beyond the allocated array, resulting in undefined behavior or segmentation faults.

2. **Loop Condition for Columns**:
   - The condition `while (map[i][j])` also assumes that the row is null-terminated. In a 2D integer array, this is not valid. Instead, you should use the known number of columns to limit the loop.

