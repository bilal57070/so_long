/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:17:57 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/17 20:20:48 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpymap(char *av, t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	countmap(av, map);
	fd = open(av, O_RDONLY);
	map->mapi = malloc(sizeof(char *) * (map->numline + 1));
	if (!(map->mapi))
		exit(EXIT_FAILURE);
	while (i < map->numline)
	{
		map->mapi[i] = get_next_line(fd);
		i++;
	}
	map->mapi[i] = 0;
	checkerror(map);
	i = 0;
	//while (map->mapi[i])
	//	ft_printf("map = %s", map->mapi[i++]);
}

void	countmap(char *av, t_map *map)
{
	char	*str;
	int		fd;

	map->numline = 0;
	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	map->num = ft_strlen(str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		map->numline++;
	}
	close(fd);
	ft_printf("line = %d\n", map->num);
	ft_printf("col = %d\n", map->numline);
}
