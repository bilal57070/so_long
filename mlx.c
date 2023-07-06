/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:23:06 by bsafi             #+#    #+#             */
/*   Updated: 2023/07/05 19:40:42 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	test(t_map *map)
// {
// 	void	*im;
// 	int	i[6] = {100, 100, 100, 100, 100, 100};
// 	map->mlx = mlx_init();
// 	im = mlx_xpm_file_to_image(map->mlx, "test.xpm", i, i);
// 	map->nwin = mlx_new_window(map->mlx, (map->num * 100), (map->numline * 100), "bekhey");
// 	mlx_loop(map->mlx);
// }

/*void test(t_map *map)
{
	(void) map;
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		y;
	void	*img;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello bekhey");
	map->img = mlx_new_image(mlx, 800, 800);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, &map->line_length,
							&map->endian);
	while (i++ < 20)
	{
		y = 0;
		//mlx_pixel_put(mlx, mlx_win, 400 + i, 400, 0x00FF0000);
		//my_mlx_pixel_put(map, 400 + i, 400, 0x00FF0000);
		my_mlx_pixel_put(map, 400 - i, 400, 0x00FF0000);
		while (i == 20 && y++ < 20)
		{
			my_mlx_pixel_put(map, 400 - i, 400 + y, 0x00FF0000);
			my_mlx_pixel_put(map, 400 + i, 400 - y, 0x00FF0000);
		}
	}
	i = 0;
	y = 0;
	while (y++ < 20)
	{
		//my_mlx_pixel_put(map, 400, 400 + y, 0x00FF0000);
		my_mlx_pixel_put(map, 400, 400 - y, 0x00FF0000);
		while (y == 20 && i++ < 20)
		{
			my_mlx_pixel_put(map, 400 - i, 400 - y, 0x00FF0000);
			//my_mlx_pixel_put(map, 400 + i, 400 + y, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, map->img, 0, 0);
	mlx_loop(mlx);
}

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->addr + (y * map->line_length + x * (map->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

void	getimg(t_map *map)
{
	int		a;

	map->img1 = mlx_xpm_file_to_image(map->mlx, "test.xpm", &a, &a);
	map->img2 = mlx_xpm_file_to_image(map->mlx, "ground.xpm", &a, &a);
	map->grass = mlx_xpm_file_to_image(map->mlx, "grass.xpm", &a, &a);
	map->col = mlx_xpm_file_to_image(map->mlx, "col.xpm", &a, &a);
	map->exit = mlx_xpm_file_to_image(map->mlx, "exit.xpm", &a, &a);
}

int		test(t_map *map)
{
	int	i;
	int	j;

	getimg(map);
	i = -1;
	while (map->mapi[++i])
		{
			j = -1;
			while(map->mapi[i][++j])
			{
				check(map, i, j);
			}
		}
	return (0);
}

void	putimg(t_map *map, void *img, int x, int y)
{
	if(!img)
		error();
	mlx_put_image_to_window(map->mlx, map->win, img, x, y);
}

int		check(t_map *map, int i, int j)
{
	if(map->mapi[i][j] == '0' || map->mapi[i][j] == 'P')
		putimg(map, map->grass, j * 64, i * 64);
	if(map->mapi[i][j] == 'R')
	{
		putimg(map, map->grass, j * 64, i * 64);
		putimg(map, map->exit, j * 64, i * 64);
		putimg(map, map->img1, j * 64, i * 64);
	}
	if(map->mapi[i][j] == 'P')
		putimg(map, map->img1, j * 64, i * 64);
	if(map->mapi[i][j] == '1')
		putimg(map, map->img2, j * 64, i * 64);
	if(map->mapi[i][j] == 'C')
		putimg(map, map->col, j * 64, i * 64);
	if(map->mapi[i][j] == 'E')
		putimg(map, map->exit, j * 64, i * 64);
	return (1);
}


int key_hook(int keycode, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
    if (keycode == 53)
    {
		mlx_destroy_window(map->mlx, map->win);
		free(map->mlx);
		exit(EXIT_SUCCESS);
    }
	if (keycode == 2)
		right(map, i, j);
	if (keycode == 0)
		left(map);
	if (keycode == 1)
		down(map, i, j);
	if (keycode == 13)
		up(map);
    return (0);
}

int	right(t_map *map, int i, int j)
{
	i = -1;
	ft_printf("mouv = %d\n", map->count++);
	while(map->mapi[++i])
	{
		j = -1;
		while(map->mapi[i][++j])
		{
			if (map->mapi[i][j] == 'P' && map->mapi[i][j + 1] == 'E' && map->c == 0)
				ft_exit();
			if (map->mapi[i][j] == 'P' && map->mapi[i][j + 1] != '1' && map->mapi[i][j + 1] != 'E')
			{
				enfin(map, i, j);
				return (0);
			}
			if ((map->mapi[i][j] == 'P' && map->mapi[i][j + 1] == 'E' && map->c != 0) || 
			(map->mapi[i][j] == 'R' && map->mapi[i][j + 1] != '1'))
			{
				enfin(map, i, j);
				return (0);
			}
		}
	}
	return (0);
}

void	enfin(t_map *map, int i, int j)
{
	if (map->mapi[i][j + 1] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'P' && map->mapi[i][j + 1] != '1' && map->mapi[i][j + 1] != 'E')
	{
		map->mapi[i][j] = '0';
		map->mapi[i][j + 1] = 'P';
	}
	if (map->mapi[i][j] == 'P' && map->mapi[i][j + 1] == 'E' && map->c != 0)
	{
		map->mapi[i][j + 1] = 'R';
		map->mapi[i][j] = '0';
		//return (0);
	}
				//ex(map, i, j);
	if (map->mapi[i][j] == 'R' && map->mapi[i][j + 1] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i][j + 1] = 'P';
//		return (0);
	}
}

void	left(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("mouv = %d\n", map->count++);
	while(map->mapi[++i])
	{
		j = -1;
		while(map->mapi[i][++j])
		{
			if (map->mapi[i][j] == 'P' && map->mapi[i][j - 1] == 'E' && map->c == 0)
				ft_exit();
			if (map->mapi[i][j] == 'P' && map->mapi[i][j - 1] != '1' && map->mapi[i][j - 1] != 'E')
			{
				if (map->mapi[i][j - 1] == 'C')
					map->c--;
				map->mapi[i][j] = '0';
				map->mapi[i][j - 1] = 'P';
			}
			if (map->mapi[i][j] == 'P' && map->mapi[i][j - 1] == 'E')
				ex(map, i, j);
			if (map->mapi[i][j] == 'R' && map->mapi[i][j - 1] != '1')
				bug(map, i, j);
		}
	}
}

void	up(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("mouv = %d\n", map->count++);
	while(map->mapi[++i])
	{
		j = -1;
		while(map->mapi[i][++j])
		{
			if (map->mapi[i][j] == 'P' && map->mapi[i - 1][j] == 'E' && map->c == 0)
				ft_exit();
			if (map->mapi[i][j] == 'P' && map->mapi[i - 1][j] != '1' && map->mapi[i - 1][j] != 'E')
			{
				if (map->mapi[i - 1][j] == 'C')
					map->c--;
				map->mapi[i][j] = '0';
				map->mapi[i - 1][j] = 'P';
			}
			if (map->mapi[i][j] == 'P' && map->mapi[i - 1][j] == 'E')
				ex(map, i, j);
			if (map->mapi[i][j] == 'R' && map->mapi[i - 1][j] != '1')
				haut(map, i, j);
		}
	}
}

int		down(t_map *map, int i, int j)
{
	i = -1;
	//ft_printf("mouv = %d\n", map->count++);
	while(map->mapi[++i])
	{
		j = -1;
		while(map->mapi[i][++j])
		{
			if (map->mapi[i][j] == 'P' && map->mapi[i + 1][j] == 'E' && map->c == 0)
				ft_exit();
			if (map->mapi[i][j] == 'P' && map->mapi[i + 1][j] != '1' && map->mapi[i + 1][j] != 'E')
			{
				fini(map, i, j);
				return (0);
			}
			/*{
				if (map->mapi[i + 1][j] == 'C')
					map->c--;
				map->mapi[i][j] = '0';
				map->mapi[i + 1][j] = 'P';
				//return (0);
			}*/
			if ((map->mapi[i][j] == 'P' && map->mapi[i + 1][j] == 'E') ||
			 (map->mapi[i][j] == 'R' && map->mapi[i + 1][j] != '1'))
			 {
				fini(map, i, j);
				return (0);
			 }
		}
	}
	return (0);
}

void	fini(t_map *map, int i, int j)
{
	if (map->mapi[i + 1][j] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'P' && map->mapi[i + 1][j] != '1' && map->mapi[i + 1][j] != 'E')
	{
		map->mapi[i][j] = '0';
		map->mapi[i + 1][j] = 'P';
	}
	if (map->mapi[i][j] == 'P' && map->mapi[i + 1][j] == 'E' && map->c != 0)
	{
		map->mapi[i + 1][j] = 'R';
		map->mapi[i][j] = '0';
		//return (0);
	}
				//ex(map, i, j);
	if (map->mapi[i][j] == 'R' && map->mapi[i + 1][j] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i + 1][j] = 'P';
//		return (0);
	}
}

int		ex(t_map *map, int i , int j)
{
	if (map->mapi[i][j] == 'P' && map->mapi[i + 1][j] == 'E')
	{
		map->mapi[i + 1][j] = 'R';
		map->mapi[i][j] = '0';
		return (0);
	}
	if (map->mapi[i][j] == 'P' && map->mapi[i - 1][j] == 'E')
	{
		map->mapi[i - 1][j] = 'R';
		map->mapi[i][j] = '0';
		return (0);
	}
	if (map->mapi[i][j] == 'P' && map->mapi[i][j + 1] == 'E')
	{
		map->mapi[i][j + 1] = 'R';
		map->mapi[i][j] = '0';
		return (0);
	}
	if (map->mapi[i][j] == 'P' && map->mapi[i][j - 1] == 'E')
	{
		map->mapi[i][j - 1] = 'R';
		map->mapi[i][j] = '0';
		return (0);
	}
	return (0);
}

void	bug(t_map *map, int	i, int j)
{
	if (map->mapi[i][j - 1] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'R' && map->mapi[i][j - 1] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i][j - 1] = 'P';
	}
}

void	droi(t_map *map, int i, int j)
{
	if (map->mapi[i][j + 1] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'R' && map->mapi[i][j + 1] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i][j + 1] = 'P';
	}
}

void	bas(t_map *map, int	i, int j)
{
	if (map->mapi[i + 1][j] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'R' && map->mapi[i + 1][j] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i + 1][j] = 'P';
	}
}

void	haut(t_map *map, int i, int j)
{
	if (map->mapi[i - 1][j] == 'C')
		map->c--;
	if (map->mapi[i][j] == 'R' && map->mapi[i - 1][j] != '1')
	{
		map->mapi[i][j] = 'E';
		map->mapi[i - 1][j] = 'P';
	}
}

int		ft_exit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
