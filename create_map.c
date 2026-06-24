/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:53:52 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/05 10:24:04 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile_image(t_map *mp, char tile, int x, int y);

void	open_window(t_map *mp)
{
	mp->mlx.win_height = mp->map_height * 32;
	mp->mlx.win_width = mp->map_width * 32;
	mp->mlx.con = mlx_init();
	load_xpm(mp);
	mp->mlx.win = mlx_new_window(mp->mlx.con,
			mp->mlx.win_width, mp->mlx.win_height, "Felix so_long");
	draw_map(mp);
	draw_items(mp);
}

void	load_xpm(t_map *mp)
{
	int	w;
	int	h;

	mp->mlx.floor = mlx_xpm_file_to_image(mp->mlx.con,
			"sprites/floor.xpm", &w, &h);
	mp->mlx.wall = mlx_xpm_file_to_image(mp->mlx.con,
			"sprites/wall.xpm", &w, &h);
	mp->mlx.player = mlx_xpm_file_to_image(mp->mlx.con,
			"sprites/player.xpm", &w, &h);
	if (!mp->mlx.player)
		return (ft_printf("Error: failed to load player sprite\n"),
			exit(1), (void)0);
	mp->mlx.collect = mlx_xpm_file_to_image(mp->mlx.con,
			"sprites/col.xpm", &w, &h);
	mp->mlx.exit = mlx_xpm_file_to_image(mp->mlx.con,
			"sprites/exit.xpm", &w, &h);
}

void	draw_map(t_map *mp)
{
	int	i;
	int	j;

	if (!mp->mlx.floor || !mp->mlx.wall) 
		return (ft_printf("Error: image not loaded properly\n"),
			exit(1), (void)0);
	i = 0;
	while (i < mp->map_height)
	{
		j = 0;
		while (j < mp->map_width)
		{
			put_tile_image(mp, mp->map[i][j], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_items(t_map *mp)
{
	int	i;
	int	j;

	i = 0;
	while (i < mp->map_height)
	{
		j = 0;
		while (j < mp->map_width)
		{
			if (mp->map[i][j] == 'P' || mp->map[i][j] == 'E'
				|| mp->map[i][j] == 'C')
				put_tile_image(mp, mp->map[i][j], j * 32, i * 32);
			j++;
		}
		i++;
	}
}

static void	put_tile_image(t_map *mp, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(mp->mlx.con,
			mp->mlx.win, mp->mlx.wall, x, y);
	else
		mlx_put_image_to_window(mp->mlx.con,
			mp->mlx.win, mp->mlx.floor, x, y);
	if (tile == 'P')
		mlx_put_image_to_window(mp->mlx.con,
			mp->mlx.win, mp->mlx.player, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(mp->mlx.con,
			mp->mlx.win, mp->mlx.collect, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(mp->mlx.con,
			mp->mlx.win, mp->mlx.exit, x, y);
}
