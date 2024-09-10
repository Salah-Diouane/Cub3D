/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 08:29:18 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/22 03:54:19 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	animate_plr(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
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

void	animation(void *arg)
{
	t_data		*data;
	static int	counter;

	data = (t_data *)arg;
	if (mlx_is_key_down(data->mlx, 32))
		data->gun.sht = 'S';
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		clean_up(data, NULL);
	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
		ft_mouse(data);
	if (counter == 0)
	{
		shot(data);
		ft_door_ctl(data);
		counter = 5;
	}
	animate_plr(data);
	counter--;
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
	result = ((300.0 * 100.0) / dst);
	return (result);
}

static void	init_door(t_data *data, int *ind)
{
	data->door_arr[ind[2]].i = ind[0];
	data->door_arr[ind[2]].j = ind[1];
	data->door_arr[ind[2]].var = 32;
	data->door_arr[ind[2]].state = 'C';
	ind[2]++;
}

int	fill_door_array(t_data *data)
{
	int		ind[3];
	char	**map;

	ind[2] = 0;
	ind[1] = 0;
	ind[0] = -1;
	map = data->map.arr;
	data->door_arr = malloc(sizeof(t_door) * \
		data->doors_nbr);
	if (!data->door_arr)
		return (write(2, "malloc failed in fill "\
			"door array!!\n", 36), -1);
	while (map && map[ind[1]])
	{
		ind[0]++;
		if (map[ind[1]][ind[0]] == 'D')
			init_door(data, ind);
		if (!map[ind[1]][ind[0] + 1] && ++ind[1])
			ind[0] = -1;
	}
	return (0);
}
