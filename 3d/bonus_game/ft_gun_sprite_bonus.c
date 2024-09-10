/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gun_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:22:31 by bramzil           #+#    #+#             */
/*   Updated: 2024/09/10 16:32:32 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	reload(t_data *data)
{
	static int		i;
	static int		counter;

	if (!data->gun.nbr_sht && !counter)
	{
		((i == 0) && (data->gun.arr[0]->enabled = 0));
		((i) && (data->gun.arr[(i + 3)]->enabled = 0));
		i++;
		if (i == 8)
		{
			i = 0;
			data->gun.nbr_sht = 10;
			data->gun.arr[0]->enabled = 1;
		}
		else
			data->gun.arr[(i + 3)]->enabled = 1;
		counter = 2;
	}
	counter--;
}

void	shot(t_data *data)
{
	if (data && (data->gun.sht == 'S'))
	{
		if (data->gun.nbr_sht == 0)
			reload(data);
		else
		{
			data->gun.arr[data->gun.i]->enabled = 0;
			data->gun.i++;
			if (data->gun.i == 4)
			{
				data->gun.i = 0;
				data->gun.nbr_sht--;
				data->gun.sht = 'N';
				data->gun.arr[0]->enabled = 1;
			}
			else
				data->gun.arr[data->gun.i]->enabled = 1;
		}
	}
}

static void	push_image(t_data *data, char **names)
{
	int		i;
	int		pos[2];

	i = -1;
	while (++i < 13 && names)
	{
		data->gun.arr[i] = load_image(data, names[i]);
		if (!data->gun.arr[i])
			(free_2d_arr(names), clean_up(data, NULL));
		data->gun.arr[i]->enabled = 0;
		pos[1] = (data->wnd[1] - data->gun.arr[i]->height);
		pos[0] = ((data->wnd[0] / 2) - (data->gun.arr[i]->width / 2));
		if (mlx_image_to_window(data->mlx, data->gun.arr[i], \
			pos[0], pos[1]) == -1)
			clean_up(data, "push gun image failed!!\n");
	}
	(data->gun.arr[0]->enabled = 1);
}

void	init_gun(t_data *data)
{
	char	*tmp;
	char	**names;

	data->gun.i = 0;
	data->gun.sht = 'N';
	data->gun.nbr_sht = 10;
	tmp = "gun/0.png gun/1.png gun/2.png " \
		"gun/3.png gun/4.png gun/5.png gun/6.png " \
		"gun/7.png gun/8.png gun/9.png gun/10.png " \
		"gun/11.png gun/12.png";
	names = ft_split(tmp, ' ');
	if (!names)
		clean_up(data, "malloc failed in init gun!!\n");
	push_image(data, names);
	free_2d_arr(names);
	data->gun.arr[0]->enabled = 1;
}
