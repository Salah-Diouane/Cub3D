/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manda.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramzil <bramzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:19:20 by bramzil           #+#    #+#             */
/*   Updated: 2024/08/29 01:25:28 by bramzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDA_H
# define MANDA_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "stdint.h"
# include "../libs/.libft/libft.h"
# include "../libs/.MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_plr
{
	double	d;
	double	x;
	double	y;
}	t_plr;

typedef struct s_face
{
	char			dir;
	char			fix;
	int				rays;
	double			x_ref;
	double			y_ref;
	double			height;
	struct s_face	*next;
}	t_face;

typedef struct map
{
	int		wd;
	int		ht;
	char	**arr;
}	t_map;

typedef struct s_texture
{
	char	*path;
	int32_t	*arr;
}	t_texture;

typedef struct s_data
{
	int			wnd[2];
	int			grd[2];
	int32_t		clr[2];
	t_plr		plr;
	t_map		map;
	mlx_t		*mlx;
	t_texture	text[4];
	t_point		*inter_arr;
	t_face		*face_lst;
	mlx_image_t	*proj_img;
}	t_data;

/***************** ray casting animation functions *******************/

void		ft_move_plr(int key, t_data *arg);
void		free_lnkd_lst(t_face **lst);
void		free_map_text(t_data *data);
void		animate_plr(void *arg);
void		clean_up(t_data *data);
void		free_2d_arr(char **arr);
void		free_textures(t_data *data);
int			load_textures(t_data *data);
void		ft_cast_rays(t_data *data);
void		ft_clear_image(mlx_image_t *img);
double		get_height(t_data *data, int i);
void		face_list(t_data *data);
void		ft_render_wall(t_data *data);
double		real_angle(double angle);
int			ft_check_next(t_data *data, double angle);
void		ft_inter(t_data *data, t_point *inter, double angle);

#endif