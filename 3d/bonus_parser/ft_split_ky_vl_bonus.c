/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ky_vl_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:11:13 by sdiouane          #+#    #+#             */
/*   Updated: 2024/09/01 09:26:49 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_parser.h"

static	char	*get_ident(char *line, int *t)
{
	char	*ident;

	ident = NULL;
	while (line[t[1]] && (-1 < ft_strchar(" \t", line[t[1]])))
		t[0] = ++t[1];
	while (line[t[1]] && (ft_strchar(" \t", line[t[1]]) < 0))
		t[1]++;
	ident = ft_substr(line, t[0], t[1] - t[0]);
	if (!ident)
		return (write(2, "substr fails in split key " \
			"value!!\n", 35), NULL);
	return (ident);
}

static	char	*get_value(char *line, int i)
{
	char	*tmp;
	char	*value;

	value = NULL;
	while (line[i] && (-1 < ft_strchar(" \t", line[i])))
		i++;
	value = ft_substr(line, i, ft_strlen(line) - i);
	if (!value)
		return (write(2, "substr failed in split key " \
			"value!!\n", 36), NULL);
	tmp = value;
	value = ft_strtrim(value, " \t");
	if (!value)
		return (write(2, "strtrim failed in split key " \
			"value!!\n", 37), free(tmp), NULL);
	return (free(tmp), value);
}

char	**ft_split_ky_vl(char *line)
{
	int		t[2];
	char	**pair;

	pair = NULL;
	(1) && (t[0] = 0, t[1] = 0);
	pair = malloc(sizeof(char *) * 3);
	if (!pair)
		return (write(2, "malloc failed in split " \
			"key value!!\n", 36), NULL);
	pair[0] = get_ident(line, t);
	pair[1] = get_value(line, t[1]);
	if (!pair[0])
		return (free_2d_arr(pair), NULL);
	else if (!pair[1])
		return (free_2d_arr(pair), NULL);
	pair[2] = NULL;
	return (pair);
}
