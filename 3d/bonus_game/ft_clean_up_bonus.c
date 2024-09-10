/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_up_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 23:56:20 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/22 03:15:46 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

void	free_2d_arr(char **arr)
{
	int			i;

	i = -1;
	while (arr && arr[++i])
		free (arr[i]);
	free(arr);
}

void	free_lnkd_lst(t_face **lst)
{
	t_face		*tmp;

	while (lst && (*lst))
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free (tmp);
	}
}

void	delete_imgs(t_data *data)
{
	int			i;

	i = -1;
	while (++i < 13)
	{
		if (data->gun.arr[i])
			mlx_delete_image(data->mlx, data->gun.arr[i]);
	}
	if (data->proj_img)
		mlx_delete_image(data->mlx, data->proj_img);
	if (data->map_img)
		mlx_delete_image(data->mlx, data->map_img);
}

void	free_map_text(t_data *data)
{
	free(data->text[4].arr);
	free(data->text[0].path);
	free(data->text[0].arr);
	free(data->text[1].path);
	free(data->text[1].arr);
	free(data->text[2].path);
	free(data->text[2].arr);
	free(data->text[3].path);
	free(data->text[3].arr);
	free_2d_arr(data->map.arr);
}

void	clean_up(t_data *data, char *msg)
{
	delete_imgs(data);
	free_map_text(data);
	free(data->door_arr);
	free(data->inter_arr);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free_lnkd_lst(&data->face_lst);
	while (msg && *msg)
	{
		write(2, msg, 1);
		msg++;
	}
	exit(0);
}
