/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:52:22 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/25 11:54:55 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus.h"

mlx_image_t	*load_image(t_data *data, char *path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return (write(2, "load png failed!!\n", 19), NULL);
	if ((texture->width < 64) || (texture->height < 64))
		return (write(2, "Invalide texture dim!!\n", 24), \
			NULL);
	image = mlx_texture_to_image(data->mlx, texture);
	if (!image)
		write(2, "mlx text to png failed!!\n", 26);
	mlx_delete_texture(texture);
	return (image);
}

static void	fill_clr_arr(mlx_image_t *image, int32_t *clr_arr)
{
	int			b[4];
	uint32_t	t[2];

	t[1] = 0;
	t[0] = -1;
	while (++t[0] < (image->width * image->height * 4))
	{
		b[0] = image->pixels[t[0]];
		b[1] = image->pixels[t[0]++];
		b[2] = image->pixels[t[0]++];
		b[3] = image->pixels[t[0]++];
		clr_arr[t[1]++] = ((b[1] << 24) | (b[2] << 16) | \
			(b[3] << 8) | b[0]);
	}
}

static int32_t	*get_texture_arr(t_data *data, char *path)
{
	int32_t		*clr_arr;
	mlx_image_t	*image;

	image = load_image(data, path);
	if (!image)
		return (NULL);
	clr_arr = malloc(sizeof(int32_t) * image->width * \
		image->height);
	if (!clr_arr)
		return (write(2, "malloc fail in get "
				"textures_arr!!\n", 35), NULL);
	fill_clr_arr(image, clr_arr);
	mlx_delete_image(data->mlx, image);
	return (clr_arr);
}

int	load_textures(t_data *data)
{
	data->text[0].arr = get_texture_arr(data, \
		data->text[0].path);
	if (!data->text[0].arr)
		return (-1);
	data->text[1].arr = get_texture_arr(data, \
		data->text[1].path);
	if (!data->text[1].arr)
		return (-1);
	data->text[2].arr = get_texture_arr(data, \
		data->text[2].path);
	if (!data->text[2].arr)
		return (-1);
	data->text[3].arr = get_texture_arr(data, \
		data->text[3].path);
	if (!data->text[3].arr)
		return (-1);
	data->text[4].arr = get_texture_arr(data, \
		data->text[4].path);
	if (!data->text[4].arr)
		return (-1);
	return (0);
}
