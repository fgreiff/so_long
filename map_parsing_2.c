/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:46:55 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/03 16:46:20 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_walkable(char c);
static int	check_floodfill(t_map *mp, char **visited);

void	fill_map(t_map *mp, char **map, int row, int col)
{
	if (row < 0 || row >= mp->map_height || col < 0 || col >= mp->map_width)
		return ;
	if (map[row][col] == 'V' || is_walkable(map[row][col]) != 1)
		return ;
	map[row][col] = 'V';
	fill_map(mp, map, row + 1, col);
	fill_map(mp, map, row - 1, col);
	fill_map(mp, map, row, col + 1);
	fill_map(mp, map, row, col - 1);
}

int	floodfill_map(t_map *mp)
{
	char	**visited;
	int		i;

	visited = NULL;
	visited = malloc(sizeof(char *) * (mp->map_height + 1));
	if (!visited)
		return (0);
	i = 0;
	while (mp->map[i])
	{
		visited[i] = ft_strdup(mp->map[i]);
		i++;
	}
	visited[i] = NULL;
	fill_map(mp, visited, mp->p_y, mp->p_x);
	i = 0;
	if (check_floodfill(mp, visited) == 1)
		return (array_free(visited), array_free(mp->map), 5);
	else
		return (array_free(visited), 0);
}

static int	is_walkable(char c)
{
	if (c == '0' || c == 'E' || c == 'P' || c == 'C')
		return (1);
	else
		return (0);
}

static int	check_floodfill(t_map *mp, char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->map_height)
	{
		j = 0;
		while (j < mp->map_width)
		{
			if ((mp->map[i][j] == 'C' || mp->map[i][j] == 'E') 
			&& visited[i][j] != 'V')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
