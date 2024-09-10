/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiouane <sdiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:43:12 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/22 01:27:54 by sdiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDA_PARSER_H
# define MANDA_PARSER_H

# include <fcntl.h>
# include "manda.h"

char	**ft_split_ky_vl(char *line);
int		ft_parsing(t_data *data, char *file);
int		parse_map(t_data *data, char *s_map);
int		ft_check_around_elem(char **map);
int		is_other_elmts_set(t_data *data);
int		check_walls(char **map);
int		set_player_position(t_data *data);
int		only_spaces(char *line);
void	put_msg(char c, int nbr);
int		just_space(char *str);
int		add_element(t_data *data, char *id, char *value);
int		add_color(int32_t *color, char *value);
void	free_elements(t_data *data);
int		set_elements(t_data *data, char **s_map, char *line);

#endif