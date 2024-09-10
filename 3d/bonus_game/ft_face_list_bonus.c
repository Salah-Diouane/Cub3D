/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:22:54 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 17:05:08 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

static void	set_fix(t_face *tmp, t_point *arr, int i)
{
	if (arr[i].y != tmp->y_ref)
		tmp->fix = 'X';
	else if (arr[i].x != tmp->x_ref)
		tmp->fix = 'Y';
}

static t_face	*new_node(t_point *arr, int i)
{
	t_face		*node;

	node = malloc(sizeof(t_face));
	if (!node)
		return (write(2, "malloc failed "
				"in new_node!!\n", 29), NULL);
	node->rays = 0;
	node->fix = 'U';
	node->dir = 'U';
	node->x_ref = arr[i].x;
	node->y_ref = arr[i].y;
	node->next = NULL;
	return (node);
}

static void	set_dir(t_data *data, t_face *tmp, int i)
{
	if (tmp->fix == 'Y')
	{
		if (data->inter_arr[i].y < data->plr.y)
			tmp->dir = 'N';
		else if (data->plr.y < data->inter_arr[i].y)
			tmp->dir = 'S';
	}
	else
	{
		if (data->plr.x < data->inter_arr[i].x)
			tmp->dir = 'E';
		else if (data->inter_arr[i].x < data->plr.x)
			tmp->dir = 'W';
	}
}

static void	add_back(t_data *dt, t_face **tp, int i)
{
	t_face		*new;

	new = new_node(dt->inter_arr, i);
	if (!new)
		clean_up(dt, NULL);
	else if ((*tp) == NULL)
		(*tp) = new;
	else
	{
		(*tp)->next = new;
		(*tp) = (*tp)->next;
	}
}

void	face_list(t_data *data)
{
	int			i;
	t_point		*arr;
	t_face		*tmp;

	i = -1;
	arr = data->inter_arr;
	free_lnkd_lst(&data->face_lst);
	add_back(data, &data->face_lst, 0);
	tmp = data->face_lst;
	while (++i < data->wnd[0])
	{
		if (tmp->fix == 'U')
			set_fix(tmp, arr, i);
		if (((tmp->fix == 'X') && (arr[i].x != tmp->x_ref)) || \
			((tmp->fix == 'Y') && (arr[i].y != tmp->y_ref)))
			add_back(data, &tmp, i);
		if ((tmp->dir == 'U') && ((tmp->fix != 'U')))
			set_dir(data, tmp, i);
		tmp->rays++;
	}
	ft_render_wall(data);
}
