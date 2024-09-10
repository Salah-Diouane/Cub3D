/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:07 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/21 22:19:09 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

static void	get_dir(double angle, t_point *dir)
{
	dir->x = 1 - (2 * ((M_PI / 2) < angle && \
		angle < (M_PI + (M_PI / 2))));
	dir->y = 1 - (2 * (0 < angle && angle < M_PI));
}

static int	is_wall(t_data *dt, t_point *p, int x_d, int y_d)
{
	int			i;
	int			j;

	i = (p->x / dt->grd[0]) - (1 * (x_d < 0));
	j = (p->y / dt->grd[1]) - (1 * (y_d < 0));
	if ((i < 0) || (dt->map.wd <= i) || (j < 0) || \
		(dt->map.ht <= j))
		return (1);
	else if (dt->map.arr[j][i] == '1')
		return (1);
	return (0);
}

static double	hor_inter(t_data *data, t_point *inter, double angle)
{
	int			gd;
	t_point		dir;
	t_point		agle;

	get_dir(angle, &dir);
	gd = data->grd[1];
	inter->y = (int)(data->plr.y / gd) * gd;
	while ((0 < inter->y) && (inter->y < (gd * data->map.ht)))
	{
		if (((0 < dir.y) && (data->plr.y < inter->y)) || \
			((dir.y < 0) && (inter->y < data->plr.y)))
		{
			agle.y = fabs(data->plr.y - inter->y);
			agle.x = fabs(agle.y / tan(angle));
			inter->x = data->plr.x + (dir.x * agle.x);
			if (is_wall(data, inter, 0, dir.y))
				break ;
		}
		inter->y += (dir.y * gd);
	}
	return (sqrt((agle.x * agle.x) + (agle.y * agle.y)));
}

static double	ver_inter(t_data *data, t_point *inter, double angle)
{
	int			gd;
	t_point		dir;
	t_point		agle;

	get_dir(angle, &dir);
	gd = data->grd[0];
	inter->x = (int)(data->plr.x / gd) * gd;
	while ((0 < inter->x) && (inter->x < (gd * data->map.wd)))
	{
		if (((0 < dir.x) && (data->plr.x < inter->x)) || \
			((dir.x < 0) && (inter->x < data->plr.x)))
		{
			agle.x = fabs(data->plr.x - inter->x);
			agle.y = fabs(agle.x * tan(angle));
			inter->y = data->plr.y + (dir.y * agle.y);
			if (is_wall(data, inter, dir.x, 0))
				break ;
		}
		inter->x += (dir.x * gd);
	}
	return (sqrt((agle.x * agle.x) + (agle.y * agle.y)));
}

void	ft_inter(t_data *dt, t_point *inter, double angle)
{
	t_point		hypo;
	t_point		h_inter;
	t_point		v_inter;

	if (dt && inter && dt->map.arr)
	{
		hypo.x = hor_inter(dt, \
			&h_inter, angle);
		hypo.y = ver_inter(dt, \
			&v_inter, angle);
		if (hypo.x <= hypo.y)
		{
			inter->x = h_inter.x;
			inter->y = h_inter.y;
		}
		else
		{
			inter->x = v_inter.x;
			inter->y = v_inter.y;
		}
	}
}
