/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:35:32 by sdiouane          #+#    #+#             */
/*   Updated: 2024/08/28 21:58:47 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PARSER_H
# define BONUS_PARSER_H

# include <fcntl.h>
# include "bonus.h"

char	**ft_split_ky_vl(char *line);
int		ft_parsing(t_data *data, char *file);
int		parse_map(t_data *data, char *s_map);
int		ft_check_around_elem(char **map);
int		is_other_elmts_set(t_data *data);
int		check_walls(char **map);
int		set_player_position(t_data *data);
int		only_spaces(char *line);
void	put_msg(char c, int nbr);
int		add_element(t_data *data, char *id, char *value);
int		add_color(int32_t *color, char *value);
int		set_elements(t_data *data, char **s_map, char *line);

#endif