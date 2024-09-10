/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:07:07 by sdiouane          #+#    #+#             */
/*   Updated: 2024/08/29 04:56:23 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda_parser.h"

static int	is_valid_wall(char *line, int nbr)
{
	while (line && *line)
	{
		if (ft_strchar("1 \t", *line) < 0)
			return (put_msg(*line, nbr), -1);
		line++;
	}
	return (0);
}

static int	ft_get_first_index(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if ((line[i] != ' ') && (line[i] != '\t'))
			return (i);
		i++;
	}
	return (i);
}

static int	ft_get_last_index(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (line && (0 <= i))
	{
		if ((line[i] != ' ') && (line[i] != '\t'))
			return (i);
		i--;
	}
	return (i);
}

int	check_walls(char **map)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	if (is_valid_wall(map[i], 1))
		return (-1);
	while (map[i] && map[++i])
	{
		start = ft_get_first_index(map[i]);
		end = ft_get_last_index(map[i]);
		if (map[i][start] != '1')
			return (put_msg(map[i][start], (i + 1)), -1);
		else if (map[i][end] != '1')
			return (put_msg(map[i][end], (i + 1)), -1);
	}
	if (is_valid_wall(map[i - 1], (i)))
		return (-1);
	return (0);
}
