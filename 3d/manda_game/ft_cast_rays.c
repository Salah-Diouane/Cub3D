/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:29 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/21 22:08:59 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

double	real_angle(double angle)
{
	double		two_pi;

	two_pi = 2 * M_PI;
	if (angle < 0)
		angle += two_pi;
	else if (two_pi <= angle)
		angle -= two_pi;
	return (angle);
}

void	ft_cast_rays(t_data *data)
{
	int			x;
	double		ria[3];
	t_point		inter;

	if (data && data->map.arr && data->inter_arr)
	{
		x = data->wnd[0];
		ria[0] = (M_PI / 180);
		ria[1] = ((60 * ria[0]) / data->wnd[0]);
		ria[2] = real_angle(data->plr.d - (30 * ria[0]));
		while (x--)
		{
			ria[2] = real_angle(ria[2]);
			ft_inter(data, &inter, ria[2]);
			data->inter_arr[x].x = inter.x;
			data->inter_arr[x].y = inter.y;
			ria[2] += ria[1];
		}
		face_list(data);
	}
}
