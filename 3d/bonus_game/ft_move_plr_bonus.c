/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:44:30 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 11:56:22 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	ft_clear_image(mlx_image_t *img)
{
	uint32_t		i;
	uint32_t		j;

	j = -1;
	while (img && (++j < img->height))
	{
		i = -1;
		while (++i < img->width)
			mlx_put_pixel(img, i, j, 0x00);
	}
}

static void	ft_for_back_ward(t_data *data, int keycode)
{
	double		x;
	double		y;
	double		angle;

	angle = 0.0;
	if (data && keycode == 87)
	{
		angle = data->plr.d;
		x = data->plr.x + (5 * cos(data->plr.d));
		y = data->plr.y + (5 * sin(data->plr.d) * -1);
	}
	if (data && keycode == 83)
	{
		angle = real_angle(data->plr.d + M_PI);
		x = data->plr.x + (5 * cos(data->plr.d) * -1);
		y = data->plr.y + (5 * sin(data->plr.d));
	}
	if (data && !ft_check_next(data, angle))
	{
		data->plr.x = x;
		data->plr.y = y;
	}
}

static void	ft_go_left_right(t_data *data, int keycode)
{
	double		x;
	double		y;
	double		angle;

	angle = 0.0;
	if (data && keycode == 65)
	{
		angle = real_angle(data->plr.d + \
			(M_PI / 2));
		x = data->plr.x + (double)(5 * cos(angle));
		y = data->plr.y + (double)(5 * sin(angle) * -1);
	}
	else if (data && keycode == 68)
	{
		angle = real_angle(data->plr.d + \
			(M_PI + (M_PI / 2)));
		x = data->plr.x + (double)(5 * cos(angle));
		y = data->plr.y + (double)(5 * sin(angle) * -1);
	}
	if (!ft_check_next(data, angle))
	{
		data->plr.x = x;
		data->plr.y = y;
	}
}

void	ft_move_plr(int key, t_data *data)
{
	if (data && key != -1)
	{
		if ((key == 65) || (key == 68))
			ft_go_left_right(data, key);
		else if (((key == 83) || (key == 87)))
			ft_for_back_ward(data, key);
		else if (key == 262)
			data->plr.d = real_angle(data->plr.d - \
				(double)(2 * (M_PI / 180)));
		else if (key == 263)
			data->plr.d = real_angle(data->plr.d + \
				(double)(2 * (M_PI / 180)));
		else if ((key == 264) && (0 < data->plr.h))
			data->plr.h -= 20;
		else if ((key == 265) && (data->plr.h < data->wnd[1]))
			data->plr.h += 20;
		ft_clear_image(data->proj_img);
		ft_clear_image(data->map_img);
		ft_cast_rays(data);
	}
}
