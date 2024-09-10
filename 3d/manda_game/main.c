/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:53:44 by bramzil           #+#    #+#             */
/*   Updated: 2024/09/01 10:10:53 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/manda.h"
#include "../include/manda_parser.h"

static void	close_game(void *arg)
{
	clean_up(arg);
}

static int	init_struct_data(t_data *data)
{
	data->text[0].path = NULL;
	data->text[0].arr = NULL;
	data->text[1].path = NULL;
	data->text[1].arr = NULL;
	data->map.arr = NULL;
	data->wnd[0] = 1100;
	data->clr[0] = -1;
	data->grd[1] = 64;
	data->inter_arr = malloc(sizeof(t_point) * data->wnd[0]);
	if (!(data->inter_arr))
		return (write(2, "malloc failed in init struct " \
				"data!!\n", 37), -1);
	data->mlx = NULL;
	data->grd[0] = 64;
	data->clr[1] = -1;
	data->wnd[1] = 700;
	data->face_lst = NULL;
	data->proj_img = NULL;
	data->text[2].path = NULL;
	data->text[2].arr = NULL;
	data->text[3].path = NULL;
	data->text[3].arr = NULL;
	return (0);
}

int	ft_create_window(t_data *data)
{
	data->mlx = mlx_init(data->wnd[0], data->wnd[1], "cube", 0);
	if (!data->mlx)
		return (write(2, "mlx_init failed!!\n", 19), -1);
	data->proj_img = mlx_new_image(data->mlx, data->wnd[0], \
		data->wnd[1]);
	if (!data->proj_img || (mlx_image_to_window(data->mlx, \
		data->proj_img, 0, 0) == -1))
		return (write(2, "init proj_img failed!!\n", 24), -1);
	return (0);
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
		return (clean_up(&data), 1);
	if (ft_create_window(&data))
		return (clean_up(&data), 1);
	if (load_textures(&data))
		return (clean_up(&data), 1);
	ft_cast_rays(&data);
	mlx_close_hook(data.mlx, close_game, &data);
	mlx_loop_hook(data.mlx, animate_plr, &data);
	mlx_loop(data.mlx);
	return (0);
}
