/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_around_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:05:28 by sdiouane          #+#    #+#             */
/*   Updated: 2024/09/01 09:19:43 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bonus_parser.h"

void	put_msg(char c, int nbr)
{
	char	*l_nbr;

	l_nbr = ft_itoa(nbr);
	if (!l_nbr)
		write(2, "ft_itoa failed in put_msg", 26);
	if (!l_nbr)
		return ;
	write(2, "this char '", 12);
	write(2, &c, 1);
	write(2, "' in line'", 11);
	write(2, l_nbr, ft_strlen(l_nbr));
	write(2, "', breaks map's rules\n", 23);
	free(l_nbr);
}

static	int	ft_check_elmt_pos(char **map, int i, int j)
{
	if (-1 < ft_strchar(" \t\0", map[i + 1][j]))
		return (put_msg(map[i][j], (i + 1)), -1);
	if (i && (-1 < ft_strchar(" \t\0", map[i - 1][j])))
		return (put_msg(map[i][j], (i + 1)), -1);
	if (-1 < ft_strchar(" \t\0", map[i][j + 1]))
		return (put_msg(map[i][j], (i + 1)), -1);
	if (j && (-1 < ft_strchar(" \t\0", map[i][j - 1])))
		return (put_msg(map[i][j], (i + 1)), -1);
	return (0);
}

int	ft_check_around_elem(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map && map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((-1 < ft_strchar("0NSWED", map[i][j])) && \
				(ft_check_elmt_pos(map, i, j) != 0))
				return (-1);
			j++;
		}
	}
	return (0);
}
