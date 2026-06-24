/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:56:26 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/05 11:55:50 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_and_exit(int ret, t_map *mp)
{
	if (ret != 0)
	{
		array_free(mp->map);
		print_error(ret);
	}
}

int	check_map(t_map *mp)
{
	int	ret;

	ret = check_shape(mp);
	check_and_exit(ret, mp);
	ret = check_walls(mp);
	check_and_exit(ret, mp);
	ret = check_tiles(mp);
	check_and_exit(ret, mp);
	count_tiles(mp);
	if (check_tile_count(mp) == 0)
	{
		array_free(mp->map);
		mp->map = NULL;
		return (1);
	}
	ret = floodfill_map(mp);
	if (ret != 0)
		print_error(ret);
	return (0);
}

void	print_error(int nbr)
{
	if (nbr == 2)
		write (2, "Error\nShape not rectangular", 30);
	if (nbr == 3)
		write (2, "Error\nMap not fully enclosed by walls", 37);
	if (nbr == 4)
		write (2, "Error\nInvalid tile on the map", 30);
	if (nbr == 5)
		write (2, "Error\nNo valid path found", 25);
	exit(EXIT_FAILURE);
}
