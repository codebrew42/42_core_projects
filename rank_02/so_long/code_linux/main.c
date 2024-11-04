#include "mlx_linux/mlx.h"

int main()
{
	void    *mlx_connection;
	void	*mlx_window;

	mlx_connection = mlx_init();
//create window
	mlx_window = mlx_new_window(mlx_connection, 500, 500, "1st_window");
//to keep the proc alive
	mlx_loop(mlx_connection);

}
