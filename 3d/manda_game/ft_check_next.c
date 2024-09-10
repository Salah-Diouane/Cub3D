/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:57:57 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 11:52:00 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

static int	check_dir(t_data *data, double angle)
{
	int			i;
	int			j;
	int			h;
	t_point		start;

	h = 0;
	start.x = data->plr.x;
	start.y = data->plr.y;
	while (++h < 13)
	{
		i = (start.x + (h * cos(angle))) / \
			data->grd[0];
		j = (start.y + (h * sin(angle) * -1)) / \
			data->grd[1];
		if (data->map.arr[j][i] == '1')
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
