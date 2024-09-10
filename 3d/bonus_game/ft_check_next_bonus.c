/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:57:57 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 11:57:01 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

static int	check_dir(t_data *data, double angle)
{
	int			ijh[3];
	t_door		*door;
	t_point		start;

	ijh[2] = 0;
	start.x = data->plr.x;
	start.y = data->plr.y;
	while (++ijh[2] < 13)
	{
		ijh[0] = (start.x + (ijh[2] * cos(angle))) / \
			data->grd[0];
		ijh[1] = (start.y + (ijh[2] * sin(angle) * -1)) / \
			data->grd[1];
		door = get_door(data, ijh[0], ijh[1]);
		if ((data->map.arr[ijh[1]][ijh[0]] == '1') || (door && \
			(door->state != 'O')))
			return (1);
	}
	return (0);
}

int	ft_check_next(t_data *data, double angle)
{
	double		rad;

	rad = (M_PI / 180);
	if (check_dir(data, angle))
		return (1);
	if (check_dir(data, real_angle(angle + (30 * rad))) && \
		check_dir(data, real_angle(angle - (30 * rad))))
		return (1);
	return (0);
}
