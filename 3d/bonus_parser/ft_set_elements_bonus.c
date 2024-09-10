/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_elements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:11:16 by sdiouane          #+#    #+#             */
/*   Updated: 2024/09/01 09:19:24 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_parser.h"

int	is_other_elmts_set(t_data *data)
{
	if (!data->text[0].path || \
		!data->text[2].path || \
		!data->text[3].path || \
		!data->text[1].path || \
		(data->clr[1] == -1) || \
		(data->clr[0] == -1))
		return (-1);
	return (0);
}

static	int	collect_map(t_data *data, char **s_map, char *line)
{
	static int	rmd;
	char		*tmp;

	if (!only_spaces(line))
	{
		((*s_map) && rmd++);
		return (0);
	}
	else if (rmd)
		return (write(2, "the map dose not surrounded " \
			"by wall!!\n", 39), free(*s_map), -1);
	else if (is_other_elmts_set(data))
		return (write(2, "an element missed or " \
			"map misordered!!\n", 39), -1);
	tmp = *s_map;
	*s_map = ft_strjoin(*s_map, line);
	if (!*s_map)
		return (free(tmp), write(2, "collect map" \
			" failed!!\n", 22), -1);
	return (free(tmp), 0);
}

static	int	is_there_an_ident(char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (1);
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (1);
	return (0);
}

int	set_elements(t_data *data, char **s_map, char *line)
{
	int		t[2];
	char	*ptr;
	char	**pair;

	pair = NULL;
	(1) && (t[0] = 0, t[1] = 0);
	ptr = ft_strtrim(line, "\n");
	if (!ptr)
		return (write(2, "ft_strtrim failed in " \
			"set_elements!!\n", 37), -1);
	if (is_there_an_ident(ptr))
	{
		pair = ft_split_ky_vl(ptr);
		if (!pair)
			return (free(ptr), -1);
		if (add_element(data, pair[0], pair[1]))
			return (free_2d_arr(pair), free(ptr), -1);
	}
	else if (collect_map(data, s_map, line))
		return (free(ptr), -1);
	return (free_2d_arr(pair), free(ptr), 0);
}
