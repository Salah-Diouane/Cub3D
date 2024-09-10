/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:08:52 by sdiouane          #+#    #+#             */
/*   Updated: 2024/09/01 09:47:48 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_parser.h"

static	int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static	double	ft_get_dir(char **map, int *t)
{
	double	angle;

	angle = 0.0;
	if (map[t[0]][t[1]] == 'N')
		angle = 90 * (M_PI / 180.0);
	else if (map[t[0]][t[1]] == 'S')
		angle = 270 * (M_PI / 180.0);
	else if (map[t[0]][t[1]] == 'W')
		angle = 180 * (M_PI / 180.0);
	else if (map[t[0]][t[1]] == 'E')
		angle = 0 * (M_PI / 180.0);
	return (angle);
}

int	set_player_position(t_data *data)
{
	int		t[3];
	int		nbr_plyr;

	t[0] = -1;
	nbr_plyr = 0;
	while (data->map.arr && data->map.arr[++t[0]] != NULL)
	{
		t[1] = -1;
		while (data->map.arr[t[0]][++t[1]])
		{
			if (is_player_char(data->map.arr[t[0]][t[1]]))
			{
				nbr_plyr++;
				data->plr.x = (double)(t[1] * 64 + 32);
				data->plr.y = (double)(t[0] * 64 + 32);
				data->plr.d = ft_get_dir(data->map.arr, t);
			}
			else if (data->map.arr[t[0]][t[1]] == 'D')
				data->doors_nbr++;
		}
	}
	if (nbr_plyr != 1)
		return (write(2, "invalid nbr of player ! \n", 26));
	return (0);
}
