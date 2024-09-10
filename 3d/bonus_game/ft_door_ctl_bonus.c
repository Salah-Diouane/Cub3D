/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_ctl_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:59:16 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/22 01:15:31 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

static void	open_door(t_door *door)
{
	if (2 < door->var)
	{
		door->var -= 2;
		door->state = 'M';
	}
	else
		door->state = 'O';
}

static void	close_door(t_door *door)
{
	if (door->var < 32)
	{
		door->state = 'M';
		door->var += 2;
	}
	else
		door->state = 'C';
}

static double	get_distance(t_data *data, int i)
{
	double		adja;
	double		oppo;
	t_point		center;

	center.x = (data->door_arr[i].i * \
		data->grd[0]) + 32;
	center.y = (data->door_arr[i].j * \
		data->grd[1]) + 32;
	adja = fabs(data->plr.x - center.x);
	oppo = fabs(data->plr.y - center.y);
	return (sqrt((adja * adja) + (oppo * oppo)));
}

t_door	*get_door(t_data *data, int i, int j)
{
	int			k;

	k = -1;
	if (data && data->map.arr && data->map.arr[j][i] == 'D')
	{
		while (++k < data->doors_nbr)
		{
			if (data->door_arr[k].i == i && \
				data->door_arr[k].j == j)
				return (&data->door_arr[k]);
		}
	}
	return (NULL);
}

int	ft_door_ctl(t_data *data)
{
	int			i;
	int			bl;
	double		dist;

	i = -1;
	bl = 0;
	while (data && data->door_arr && (++i < data->doors_nbr))
	{
		dist = get_distance(data, i);
		if ((dist < 90) && \
			(data->door_arr[i].state != 'O') && ++bl)
			open_door(&data->door_arr[i]);
		else if ((90 < dist) && \
			(data->door_arr[i].state != 'C') && ++bl)
			close_door(&data->door_arr[i]);
		if (bl)
		{
			ft_clear_image(data->proj_img);
			ft_clear_image(data->map_img);
			ft_cast_rays(data);
		}
	}
	return (0);
}
