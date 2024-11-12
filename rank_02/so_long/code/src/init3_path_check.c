// #include "../includes/so_long.h"

// // Direction arrays for right, down, up, left //put it in the func
// static const int dx[] = {1, 0, -1, -1};
// static const int dy[] = {0, 1, -1, 0};

// static t_path	*init_path_data(t_game *game)
// {
// 	t_path		*path;
// 	//malloc for t_path

// 	//init path data : check map->row/column necessary?
// 	//malloc "path->visited"
// 	//init "path->visited[][]" with zero 
// }

// static void	 free_path(t_path *data)
// {}

// static void	dfs(t_path *data, int x, int y)
// {
// 	//current pos = makr as visited
// 	//curruent == 'c'/'e'? -> update 'path'
// 	//try all four dir
// 		//if the next pos == valid -> recursively call dfs(path, next_x, next_y)
// 		//if invalid -> next dir(right->down->up->next) use dx[], dy[]
// }

// int	has_valid_path(t_game *game)
// {
// //init
// //start dfs from player pos
// //if all items found, exit_found : free_path -> return()
// }