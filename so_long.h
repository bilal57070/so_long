/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:53:42 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/22 22:52:25 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"

typedef struct s_map
{
	char	**mapi;
	int		numline;
	int		num;
	void	*nwin;
	
	void	*mlx;
	void	*img1;
	void	*img2;
	void	*grass;
	void	*col;
	void	*exit;
	void	*win;
	int		count;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;

}		t_map;

void	cpymap(char *av, t_map *map);
void	countmap(char *av, t_map *map);
void	checkrec(t_map *map);
void	free_tab(char **mapi);
void	checkcont(t_map *map);
void	checkdoub(t_map *map);
void	checkmapf(t_map *map);
void	checkmapl(t_map *map);
void	checkmap(t_map *map);
void	checkerror(t_map *map);
int		checkav(char **av);
void	checkpath(t_map *map);
void	checkcar(char **tmp, int i, int j);
void	checkall(char **tmp);
char	**cpycpy(t_map *map, char **tnp);
void	error(void);


void	getimg(t_map *map);
int		test(t_map *map);
void	putimg(t_map *map, void *img, int x, int y);
int		check(t_map *map, int i, int j);
int		right(t_map *map);
int		left(t_map *map);
int		up(t_map *map);
int		down(t_map *map);
int 	key_hook(int keycode, t_map *map);
//int		toz(t_map *map);
void	mouv(t_map *map);
int		ft_exit(void);

#endif
