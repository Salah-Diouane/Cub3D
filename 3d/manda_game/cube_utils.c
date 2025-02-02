/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:29:18 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/21 22:05:04 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

void	animate_plr(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		clean_up(data);
	if (mlx_is_key_down(data->mlx, 65))
		ft_move_plr(65, data);
	if (mlx_is_key_down(data->mlx, 68))
		ft_move_plr(68, data);
	if (mlx_is_key_down(data->mlx, 83))
		ft_move_plr(83, data);
	if (mlx_is_key_down(data->mlx, 87))
		ft_move_plr(87, data);
	if (mlx_is_key_down(data->mlx, 262))
		ft_move_plr(262, data);
	if (mlx_is_key_down(data->mlx, 263))
		ft_move_plr(263, data);
	if (mlx_is_key_down(data->mlx, 264))
		ft_move_plr(264, data);
	if (mlx_is_key_down(data->mlx, 265))
		ft_move_plr(265, data);
}

double	get_height(t_data *data, int i)
{
	double		dst;
	double		unit;
	double		opad[2];
	double		ray_angle;
	double		result;

	unit = (60.0 * (M_PI / 180.0)) / data->wnd[0];
	ray_angle = real_angle(fabs((data->wnd[0] / \
		2.0) - i) * unit);
	opad[1] = fabs(data->plr.x - data->inter_arr[i].x);
	opad[0] = fabs(data->plr.y - data->inter_arr[i].y);
	dst = sqrt((opad[0] * opad[0]) + (opad[1] * opad[1])) * \
		cos(ray_angle);
	result = ((350.0 * 64.0) / dst);
	return (result);
}
