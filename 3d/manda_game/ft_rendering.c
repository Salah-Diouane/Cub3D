/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:54:21 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/28 21:41:42 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

static int	get_x_offset(t_data *data, t_face *tmp, double x)
{
	int		x_offset;

	x_offset = 0;
	if (tmp->fix == 'X')
		x_offset = ((int)((int)data->inter_arr[(int)x].y % \
			data->grd[1]));
	else
		x_offset = ((int)((int)data->inter_arr[(int)x].x % \
			data->grd[0]));
	return (x_offset);
}

static int	indices(t_data *data, t_face *tmp, int *tab, int x)
{
	if (tmp && tmp->fix == 'X')
	{
		tab[1] = (data->inter_arr[x].y / data->grd[1]);
		tab[0] = (data->inter_arr[x].x / data->grd[0]) - \
			1 * (data->inter_arr[x].x < data->plr.x);
	}
	else if (tmp && tmp->fix == 'Y')
	{
		tab[0] = (data->inter_arr[x].x / data->grd[0]);
		tab[1] = (data->inter_arr[x].y / data->grd[1]) - \
			1 * (data->inter_arr[x].y < data->plr.y);
	}
	else
		return (1);
	return (0);
}

static void	put_pixel(t_data *dt, t_face *tp, int *xytx_o)
{
	int			y_off;
	int			ind[3];

	if (indices(dt, tp, ind, xytx_o[0]))
		return ;
	y_off = ((xytx_o[1] - xytx_o[2]) * (dt->grd[1] / \
		tp->height));
	ind[2] = (dt->grd[0] * y_off) + xytx_o[3];
	if (tp->dir == 'N')
		mlx_put_pixel(dt->proj_img, xytx_o[0], xytx_o[1], \
			dt->text[0].arr[ind[2]]);
	else if (tp->dir == 'S')
		mlx_put_pixel(dt->proj_img, xytx_o[0], xytx_o[1], \
			dt->text[1].arr[ind[2]]);
	else if (tp->dir == 'W')
		mlx_put_pixel(dt->proj_img, xytx_o[0], xytx_o[1], \
			dt->text[2].arr[ind[2]]);
	else if (tp->dir == 'E')
		mlx_put_pixel(dt->proj_img, xytx_o[0], xytx_o[1], \
			dt->text[3].arr[ind[2]]);
}

static void	colum(t_data *data, t_face *tmp, int x_of, int x)
{
	int			y;
	int			hb[2];
	int			xytx_o[4];

	y = -1;
	xytx_o[0] = x;
	xytx_o[3] = x_of;
	hb[0] = data->wnd[1] / 2;
	hb[1] = hb[0] + (tmp->height / 2.0);
	xytx_o[2] = hb[0] - (tmp->height / 2.0);
	while (++y < data->wnd[1])
	{
		xytx_o[1] = y;
		if (y < xytx_o[2])
			mlx_put_pixel(data->proj_img, \
				x, y, data->clr[0]);
		else if (xytx_o[2] <= y && y < hb[1])
			put_pixel(data, tmp, xytx_o);
		else
			mlx_put_pixel(data->proj_img, \
				x, y, data->clr[1]);
	}
}

void	ft_render_wall(t_data *data)
{
	int			i;
	int			x;
	t_face		*tmp;
	int			x_off;

	x = 0;
	tmp = data->face_lst;
	while (tmp)
	{
		i = -1;
		while ((++i < tmp->rays) && \
			(x < data->wnd[0]))
		{
			x_off = get_x_offset(data, tmp, x);
			tmp->height = get_height(data, x);
			colum(data, tmp, x_off, x);
			x++;
		}
		tmp = tmp->next;
	}
}
