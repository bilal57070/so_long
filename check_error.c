/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:47:42 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/15 20:28:55 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkrec(t_map *map)
{
	int	i;
	int	len;

	i = -1;
	while (map->mapi[++i])
	{
		len = ft_strlen(map->mapi[i]);
		if (len != map->num)
		{
			free_tab(map->mapi);
			error();
		}
	}
}

void	checkcont(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapi[++i])
	{
		j = -1;
		while (map->mapi[i][++j])
		{
			if (map->mapi[i][j] != '0' && map->mapi[i][j] != '1'
			&& map->mapi[i][j] != 'E' &&
			map->mapi[i][j] != 'C' && map->mapi[i][j] != 'P'
			&& map->mapi[i][j] != '\n')
			{
				free_tab(map->mapi);
				error();
			}
		}
	}
}

void	checkdoub(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (map->mapi[++i])
	{
		j = -1;
		while (map->mapi[i][++j])
		{
			if (map->mapi[i][j] == 'P' || map->mapi[i][j] == 'E')
				c++;
		}
	}
	if (c != 2)
	{
		free_tab(map->mapi);
		error();
	}
}

void	checkmapf(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map->mapi[i][++j])
	{
		if (map->mapi[i][j] != '1' && map->mapi[i][j] != '\n')
		{
			free_tab(map->mapi);
			error();
		}
	}
}

void	checkmapl(t_map *map)
{
	int	i;
	int	j;

	i = map->numline - 1;
	j = -1;
	while (map->mapi[i][++j])
	{
		if (map->mapi[i][j] != '1' && map->mapi[i][j] != '\n')
		{
			free_tab(map->mapi);
			error();
		}
	}
}
