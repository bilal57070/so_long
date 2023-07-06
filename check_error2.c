/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:29:40 by bsafi             #+#    #+#             */
/*   Updated: 2023/07/04 17:33:09 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapi[++i] && i < (map->numline))
	{
		j = -1;
		while (map->mapi[i][++j])
		{
			if ((j == 0 && map->mapi[i][j] != '1')
			|| (j == (map->num - 2) && map->mapi[i][j] != '1'))
			{
				free_tab(map->mapi);
				error();
			}
		}
	}
}

int	checkav(char **av)
{
	int	i;
	int	fd;

	i = ft_strlen(av[1]) - 1;
	if (open(av[1], O_DIRECTORY) != -1)
		error();
	fd = open(av[1], O_RDONLY);
	/*while(av[1] && fd != 0)
	{
		if (av[1][i] == 'r' && av[1][i - 1] == 'e' && av[1][i - 2] == 'b' && av[1][i - 3] == '.')
		{
			return (0);	
		}
		else
		{
			ft_printf("erreur : mauvais fichier");
			exit(EXIT_FAILURE);
		}
	}*/
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 48) && fd != 0)
	{
		error();
	}
	//close(fd);
	return (0);
}

void	checkpath(t_map *map)
{
	int		j;
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	j = 0;
	tmp = cpycpy(map, tmp);
	//while (tmp[i])
	//	ft_printf("map = %s", tmp[i++]);
	i = 0;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (tmp[i][j] == 'P' || tmp[i][j] == 'T')
			{
				tmp[i][j] = 'X';
				checkcar(tmp, i, j);
				i = 0;
			}
		}
	}
	checkall(tmp);
}

void	checkcar(char **tmp, int i, int j)
{
	if (tmp[i][j] == 'X')
	{
		if (tmp[i - 1][j] != '1' && tmp[i - 1][j] != 'X')
			tmp[i - 1][j] = 'T';
		if (tmp[i + 1][j] != '1' && tmp[i + 1][j] != 'X')
			tmp[i + 1][j] = 'T';
		if (tmp[i][j + 1] != '1' && tmp[i][j + 1] != 'X')
			tmp[i][j + 1] = 'T';
		if (tmp[i][j - 1] != '1' && tmp[i][j - 1] != 'X')
			tmp[i][j - 1] = 'T';
	}
}

void	checkall(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (tmp[i][j] == 'C' || tmp[i][j] == 'E')
				error();
		}
		free(tmp[i]);
	}
	free(tmp);
}
