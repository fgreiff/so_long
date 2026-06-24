/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:57:12 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/05 10:24:37 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_under_player(t_map *mp, char next_tile);
static void	put_old_tile(t_map *mp, int old_x, int old_y);

void	play_game(t_map *mp)
{
	mlx_key_hook(mp->mlx.win, key_hook, mp);
	mlx_hook(mp->mlx.win, 17, 0, close_handler, mp);
}

int	key_hook(int keycode, void *param)
{
	t_map	*mp;
	int		x_new;
	int		y_new;

	mp = (t_map *)param;
	x_new = mp->p_x;
	y_new = mp->p_y;
	if (keycode == 119)
		y_new--;
	else if (keycode == 97)
		x_new--;
	else if (keycode == 115)
		y_new++;
	else if (keycode == 100)
		x_new++;
	else if (keycode == 65307)
		end_game(mp);
	else 
		return (0);
	move_player(x_new, y_new, mp);
	return (0);
}

void	move_player(int x_new, int y_new, t_map *mp)
{
	int		old_x;
	int		old_y;
	char	next_tile;

	old_x = mp->p_x;
	old_y = mp->p_y;
	next_tile = mp->map[y_new][x_new];
	if (next_tile == '1')
		return ;
	if (mp->c_count == 0 && next_tile == 'E')
		end_game(mp);
	mp->map[old_y][old_x] = mp->under_player;
	update_under_player(mp, next_tile);
	mp->map[y_new][x_new] = 'P';
	put_old_tile(mp, old_x, old_y);
	mlx_put_image_to_window(mp->mlx.con, mp->mlx.win, mp->mlx.player,
		x_new * 32, y_new * 32);
	mp->p_x = x_new;
	mp->p_y = y_new;
	mp->steps++;
	ft_printf("Steps: %d\n", mp->steps);
}

static void	update_under_player(t_map *mp, char next_tile)
{
	if (next_tile == 'C')
	{
		mp->c_count--;
		mp->under_player = '0';
	}
	else if (next_tile == 'E')
	{
		mp->under_player = 'E';
	}
	else
	{
		mp->under_player = next_tile;
	}
}

static void	put_old_tile(t_map *mp, int old_x, int old_y)
{
	if (mp->map[old_y][old_x] == 'E')
		mlx_put_image_to_window(mp->mlx.con, mp->mlx.win, mp->mlx.exit,
			old_x * 32, old_y * 32);
	else
		mlx_put_image_to_window(mp->mlx.con, mp->mlx.win, mp->mlx.floor,
			old_x * 32, old_y * 32);
}
