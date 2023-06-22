/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:48:44 by bsafi             #+#    #+#             */
/*   Updated: 2023/06/19 17:17:52 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **mapi)
{
	int	i;

	i = 0;
	while (mapi[i])
		free(mapi[i++]);
	free(mapi);
}

void	checkerror(t_map *map)
{
	checkcont(map);
	checkrec(map);
	checkdoub(map);
	checkmapf(map);
	checkmapl(map);
	checkmap(map);
	checkpath(map);
}

void	error(void)
{
	ft_printf("error\n");
	exit(EXIT_FAILURE);
}

char	**cpycpy(t_map *map, char **tmp)
{
	int	i;

	i = -1;
	tmp = malloc(sizeof(char *) * (map->numline + 1));
	//tmp[i] = malloc(sizeof(char) * (map->num + 2));
	if (!(tmp))
		exit(EXIT_FAILURE);
	while (map->mapi[++i])
	{
		tmp[i] = ft_strdup(map->mapi[i]);
	}
	tmp[i] = 0;
	return (tmp);
}
