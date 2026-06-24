/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:16:09 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/03 16:08:52 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_shape(t_map *mp)
{
	int	i;
	int	len;

	len = ft_strlen(mp->map[0]);
	i = 1;
	while (mp->map[i] != NULL)
	{
		if ((int)ft_strlen(mp->map[i]) != len)
			return (2);
		i++;
	}
	mp->map_width = len;
	return (0);
}

int	check_walls(t_map *mp)
{
	int	j;
	int	i;

	i = 0;
	while (i < mp->map_height)
	{
		if (i == 0 || i == mp->map_height - 1)
		{
			j = 0;
			while (mp->map[i][j])
			{
				if (mp->map[i][j] != '1')
					return (3);
				j++;
			}
		}
		else 
		{
			if (mp->map[i][0] != '1' || mp->map[i][mp->map_width - 1] != '1')
				return (3);
		}
		i++;
	}
	return (0);
}

int	check_tiles(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->map[i])
	{
		j = 0;
		while (mp->map[i][j])
		{
			if (mp->map[i][j] != '0' && mp->map[i][j] != '1'
				&& mp->map[i][j] != 'P' && mp->map[i][j] != 'E'
				&& mp->map[i][j] != 'C')
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}

void	count_tiles(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (mp->map[i])
	{
		j = 0;
		while (mp->map[i][j])
		{
			if (mp->map[i][j] == 'P')
			{
				mp->p_x = j;
				mp->p_y = i;
				mp->p_count++;
			}
			if (mp->map[i][j] == 'E')
				mp->e_count++;
			if (mp->map[i][j] == 'C')
				mp->c_count++;
			j++;
		}
		i++;
	}
}

int	check_tile_count(t_map *mp)
{
	if (mp->p_count > 1)
		return (write (2, "Error\nMultiple players on map", 30), 0);
	if (mp->p_count < 1)
		return (write (2, "Error\nNo player on the map", 30), 0);
	if (mp->c_count < 1)
		return (write (2, "Error\nNo collectibles on the map", 30), 0);
	if (mp->e_count < 1)
		return (write (2, "Error\nNo exit on the map", 30), 0);
	if (mp->e_count > 1)
		return (write (2, "Error\nMultiple exits on the map", 30), 0);
	else
		return (1);
}
