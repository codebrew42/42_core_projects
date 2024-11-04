#include "includes/so_long.h"

int main()
{
	void    *mlx_connection;
	void	*mlx_window1;
	void	*mlx_window2;
	int		i;


	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (1);
	//create two windows
	mlx_window1 = mlx_new_window(mlx_connection, 500, 500, "window1");
	if (mlx_window1 == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	mlx_window2 = mlx_new_window(mlx_connection, 500, 500, "window2");
	if (mlx_window2 == NULL)
	{
		mlx_destroy_window(mlx_connection, mlx_window1);
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	//color
	i = 0;
	int j = 0;
	while (i++ < 100)
	{	
		while (j++ < 150)
			mlx_pixel_put(mlx_connection, mlx_window1, 100+i, 100+j, 0xff0000);
	}

	//to keep the proc alive
	mlx_loop(mlx_connection);

}
