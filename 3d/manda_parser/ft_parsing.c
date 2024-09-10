/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:28:59 by sdiouane          #+#    #+#             */
/*   Updated: 2024/08/25 16:49:14 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda_parser.h"

static	void	set_map_dimenssions(t_data *data)
{
	int	i;

	i = 0;
	data->map.wd = ft_strlen(data->map.arr[0]);
	while (data->map.arr[i])
		i++;
	data->map.ht = i;
}

static	int	check_extention(char *file)
{
	int		len;
	char	*tmp;

	len = ft_strlen(file);
	tmp = ft_substr(file, (len - 4), 4);
	if (!tmp || ft_strncmp(tmp, ".cub", 4))
		return (free(tmp), write(2, "Invalid " \
			"map file's extention!!\n", 32), -1);
	return (free(tmp), 0);
}

static int	read_map(t_data *data, char **s_map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0222);
	if (fd < 0)
		return (write(2, "open failed in " \
			"read_map!!\n", 27), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (set_elements(data, s_map, line))
			return (free(line), -1);
		free(line);
	}
	close(fd);
	return (0);
}

int	ft_parsing(t_data *data, char *file)
{
	char	*s_map;

	s_map = NULL;
	if (check_extention(file))
		return (-1);
	if (read_map(data, &s_map, file))
		return (-1);
	if (is_other_elmts_set(data) || !s_map)
		return (write(2, "An element is missed!!\n", 24), -1);
	if (parse_map(data, s_map))
		return (free(s_map), -1);
	if (set_player_position(data))
		return (free(s_map), -1);
	set_map_dimenssions(data);
	return (free(s_map), 0);
}
