/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:55:19 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 11:47:32 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"

void	free_2d_arr(char **arr)
{
	int		i;

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

void	free_map_text(t_data *data)
{
	free(data->text[0].path);
	free(data->text[1].path);
	free(data->text[2].path);
	free(data->text[3].path);
	free_2d_arr(data->map.arr);
}

void	clean_up(t_data *data)
{
	free_map_text(data);
	free(data->inter_arr);
	free_textures(data);
	free_lnkd_lst(&data->face_lst);
	if (data->proj_img)
		mlx_delete_image(data->mlx, data->proj_img);
	if (data->mlx)
		mlx_terminate(data->mlx);
	exit(0);
}
