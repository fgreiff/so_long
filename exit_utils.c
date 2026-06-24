/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:11:34 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/02 16:31:30 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cleanup_exit(t_map *mp)
{
	if (mp->mlx.exit)
		mlx_destroy_image(mp->mlx.con, mp->mlx.exit);
	if (mp->mlx.player)
		mlx_destroy_image(mp->mlx.con, mp->mlx.player);
	if (mp->mlx.collect)
		mlx_destroy_image(mp->mlx.con, mp->mlx.collect);
	if (mp->mlx.wall)
		mlx_destroy_image(mp->mlx.con, mp->mlx.wall);
	if (mp->mlx.floor)
		mlx_destroy_image(mp->mlx.con, mp->mlx.floor);
	if (mp->mlx.win)
		mlx_destroy_window(mp->mlx.con, mp->mlx.win);
	if (mp->mlx.con)
	{
		mlx_destroy_display(mp->mlx.con);
		free(mp->mlx.con);
	}
	array_free(mp->map);
	return (0);
}

void	array_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	close_handler(void *param)
{
	t_map	*mp;

	mp = (t_map *)param;
	cleanup_exit(mp);
	exit(0);
	return (0);
}

void	end_game(t_map *mp)
{
	cleanup_exit(mp);
	exit (0);
}
