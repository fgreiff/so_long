/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:57:04 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/05 10:27:23 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "printf/ft_printf.h" 
# include "libft/get_next_line/get_next_line.h"

typedef struct s_mlx
{
	void	*con;
	void	*win;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_map
{
	int		map_height;
	int		map_width;
	char	**map;
	int		c_count;
	int		e_count;
	int		p_count;
	int		p_x;
	int		p_y;
	int		steps;
	char	under_player;
	t_mlx	mlx;
}	t_map;

//main
int		main(int argc, char **argv);

//map_parsing
int		check_map(t_map *mp);
int		check_shape(t_map *mp);
int		check_walls(t_map *mp);
int		check_tiles(t_map *mp);
void	count_tiles(t_map *mp);
int		check_tile_count(t_map *mp);
void	fill_map(t_map *mp, char **map, int row, int col);
int		floodfill_map(t_map *mp);

//error handeling
void	print_error(int nbr);

void	mp_init(t_map *mp);

//creating map
void	open_window(t_map *mp);
void	load_xpm(t_map *mp);
void	draw_map(t_map *mp);
void	draw_items(t_map *mp);

//game logic
void	play_game(t_map *mp);
int		key_hook(int keycode, void *param);
void	move_player(int x_new, int y_new, t_map *mp);
void	end_game(t_map *mp);
int		close_handler(void *param);

//clean up
int		cleanup_exit(t_map *mp);
void	array_free(char **str);

#endif