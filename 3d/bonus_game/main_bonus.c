/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:55:29 by bramzil           #+#    #+#             */
/*   Updated: 2024/09/01 10:10:39 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"
#include "../include/bonus_parser.h"

static void	close_game(void *arg)
{
	clean_up(arg, NULL);
}

static void	intiate_images(t_data *data)
{
	int			i;

	i = -1;
	data->grd[0] = 64;
	data->clr[1] = -1;
	data->wnd[0] = 1100;
	data->doors_nbr = 0;
	while (++i < 13)
		data->gun.arr[i] = NULL;
	data->proj_img = NULL;
	data->map_img = NULL;
	data->wnd[1] = 700;
	data->clr[0] = -1;
	data->grd[1] = 64;
	data->fact = 4.0;
}

static int	init_struct_data(t_data *data)
{
	intiate_images(data);
	data->text[0].path = NULL;
	data->text[1].path = NULL;
	data->text[0].arr = NULL;
	data->text[1].arr = NULL;
	data->face_lst = NULL;
	data->map.arr = NULL;
	data->inter_arr = malloc(sizeof(t_point) * data->wnd[0]);
	if (!data->inter_arr)
		return (write(2, "malloc failed in init struct " \
				"data!!\n", 37), -1);
	data->mlx = NULL;
	data->door_arr = NULL;
	data->text[2].arr = NULL;
	data->text[4].arr = NULL;
	data->text[3].arr = NULL;
	data->text[2].path = NULL;
	data->text[3].path = NULL;
	data->text[4].path = "textures/d1.png";
	return (0);
}

int	ft_create_window(t_data *data)
{
	data->mlx = mlx_init(data->wnd[0], data->wnd[1], "cub3D", 0);
	if (!data->mlx)
		return (write(2, "init mlx fails!!\n", 18), -1);
	data->proj_img = mlx_new_image(data->mlx, data->wnd[0], \
		data->wnd[1]);
	if (!data->proj_img || (mlx_image_to_window(data->mlx, \
		data->proj_img, 0, 0) == -1))
		return (write(2, "init proj_img fails!!\n", 23), -1);
	data->map_img = mlx_new_image(data->mlx, 120, 120);
	if (!data->map_img || (mlx_image_to_window(data->mlx, \
		data->map_img, 10, 10) == -1))
		return (write(2, "init map_img fails!!\n", 22), -1);
	return (init_gun(data), 0);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
		return (write(2, "Progrma must " \
			"takes map only as arg!!\n", 38), 1);
	if (init_struct_data(&data))
		return (1);
	if (ft_parsing(&data, av[1]))
		return (clean_up(&data, NULL), 1);
	if (ft_create_window(&data))
		return (clean_up(&data, NULL), 1);
	if (load_textures(&data) || (data.doors_nbr && \
		fill_door_array(&data)))
		return (clean_up(&data, NULL), 1);
	ft_cast_rays(&data);
	mlx_close_hook(data.mlx, close_game, &data);
	mlx_loop_hook(data.mlx, animation, &data);
	mlx_loop(data.mlx);
	return (0);
}
