/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgreiff <fgreiff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:18:19 by fgreiff           #+#    #+#             */
/*   Updated: 2025/10/05 11:40:25 by fgreiff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_size(t_map *mp, int map_fd);
static void	fill_map_array(t_map *mp, int map_fd);

int	main(int argc, char **argv)
{
	t_map	mp;
	int		fd;

	mp_init(&mp);
	if (argc != 2)
		return (write (2, "Error\nUsage: ./so_long map.ber", 35), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("could not open"), 1);
	get_map_size(&mp, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("could not open"), 1);
	fill_map_array(&mp, fd);
	close(fd);
	if (check_map(&mp) != 0)
		return (cleanup_exit(&mp), 1);
	open_window(&mp);
	play_game(&mp);
	mlx_loop(mp.mlx.con);
	return (cleanup_exit(&mp), 0);
}

static void	get_map_size(t_map *mp, int map_fd)
{
	int		i;
	char	*line;

	line = get_next_line(map_fd);
	if (!line)
		exit(EXIT_FAILURE);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		i++;
	}
	mp->map_height = i;
}

static void	fill_map_array(t_map *mp, int map_fd)
{
	int		i;
	char	*temp;

	i = 0;
	mp->map = malloc(sizeof(char *) * (mp->map_height + 1));
	if (!mp->map)
		exit(EXIT_FAILURE);
	while (i < mp->map_height)
	{
		mp->map[i] = get_next_line(map_fd);
		i++;
	}
	mp->map[mp->map_height] = NULL;
	i = 0;
	while (mp->map[i] != NULL)
	{
		temp = mp->map[i];
		mp->map[i] = ft_strtrim(temp, "\n");
		free(temp);
		i++;
	}
}
