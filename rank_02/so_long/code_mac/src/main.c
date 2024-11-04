#include "../includes/so_long.h"

int main(int ac, char **av)
{
	mlx_t*	mlx;
	mlx_image_t	*image;
	int		i;

	if (ac != 2)
		return (1);
		
	
	if(!(mlx= mlx_init(500, 500, "1st_window", 0))) //no resize
		return (EXIT_FAILURE);
	//mlx_loop_hook(mlx, ft_randomize, mlx);
	//mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);

	i = 0;
	while (i++ < 100)
	{
		mlx_put_pixel(image, 250+i, 250, 0xff0000);
	}
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}