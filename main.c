/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:36:58 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/22 23:25:08 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	map.count = 0; 

	if (ac != 2)
		return (0);
	checkav(av);
	cpymap(av[1], &map);
	//system("leaks so_long");
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, (map.num - 1) * 64, map.numline * 64, "Hello bekhey");
	test(&map);
	mlx_loop_hook(map.mlx, &test, &map);
	mlx_hook(map.win, 2, 0, &key_hook, &map);
	mlx_hook(map.win, 17, 0, &ft_exit, &map);
	mlx_loop(map.mlx);
	free(map.mlx);
}
/*typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
	(void) data;
	This function needs to exist, but it is useless for the moment 
	return (0);
}
int	handle_input(int keysym, t_data *data)
{
	if (keysym == 2)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1200, 1200,
			"My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}

	 Setup hooks 
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

	 we will exit the loop if there's no window left, and execute this code 
	//mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}*/
