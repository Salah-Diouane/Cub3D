/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:12:32 by sdiouane          #+#    #+#             */
/*   Updated: 2024/09/01 09:19:46 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_parser.h"

int	only_spaces(char *line)
{
	int	i;

	i = -1;
	while (line && line[++i])
		if ((line[i] != ' ') && (line[i] != '\t') && (line[i] != '\n'))
			return (1);
	return (0);
}

static	int	is_valid_id(char *id)
{
	if (!ft_strnstr("NO SO WE EA C F", id, 15))
		return (write(2, \
			"Invalid elemt id!!!\n", 21), -1);
	return (0);
}

static	int	add_texture(char **texture, char *value)
{
	if (!(*texture))
		*texture = ft_strdup(value);
	else
		return (write(2, "A texture is " \
			"duplicated!!\n", 27), -1);
	return (0);
}

int	add_element(t_data *data, char *id, char *value)
{
	if (is_valid_id(id))
		return (-1);
	else if (!ft_strncmp("NO", id, 2) && \
		add_texture(&data->text[0].path, value))
		return (-1);
	else if (!ft_strncmp("SO", id, 2) && \
		add_texture(&data->text[1].path, value))
		return (-1);
	else if (!ft_strncmp("C", id, 2) && \
		add_color(&data->clr[0], value))
		return (-1);
	else if (!ft_strncmp("F", id, 2) && \
		add_color(&data->clr[1], value))
		return (-1);
	else if (!ft_strncmp("WE", id, 2) && \
		add_texture(&data->text[2].path, value))
		return (-1);
	else if (!ft_strncmp("EA", id, 2) && \
		add_texture(&data->text[3].path, value))
		return (-1);
	return (0);
}
