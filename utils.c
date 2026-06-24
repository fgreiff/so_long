/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:20:19 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/03 15:50:04 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mp_init(t_map *mp)
{
	mp->map_height = 0;
	mp->map_width = 0;
	mp->map = NULL;
	mp->c_count = 0;
	mp->e_count = 0;
	mp->p_count = 0;
	mp->p_x = 0;
	mp->p_y = 0;
	mp->under_player = '0';
	mp->steps = 0;
	mp->mlx.con = NULL;
	mp->mlx.win = NULL;
	mp->mlx.floor = NULL;
	mp->mlx.wall = NULL;
	mp->mlx.player = NULL;
	mp->mlx.collect = NULL;
	mp->mlx.exit = NULL;
	mp->mlx.win_width = 0;
	mp->mlx.win_height = 0;
}
