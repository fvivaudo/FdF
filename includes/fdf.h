/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 14:10:15 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/01/03 14:10:17 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>
# include <get_next_line.h>

typedef struct		s_coord
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				sx;
	int				sy;
	int				dx;
	int				dy;
	int				err;
	int				e2;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*ima;
	int				ref;
	int				sc;
	int				gapy;
	int				gapx;
	int				iso1;
	int				iso2;
	int				x;
	int				y;
	int				**map;
	int				x_max;
	int				y_max;
	int				hgt;
	int				h_max;
	int				max;
	t_coord			coord;
	char			key[256];
}					t_env;

void				deal_coord(t_coord coord, t_env e);
void				draw_line(t_coord c, t_env e);
void				draw_line2(t_coord c, t_env e);
void				draw(t_env e);
int					**envdealer(int fd, int i, int size, t_env *e);
int					**envdealer2(int size, t_env *e, int **tab, char *line);
int					*add_line(char *line, t_env *e);
char				**add_line2(t_env *e, int *i, char **tab);
int					key_released(int keycode, t_env *e);
int					key_pressed(int keycode, t_env *e);
int					env_change(t_env *e);
t_env				ft_init(void);
int					gere_expose_wait(t_env *e);
void				set_param(t_env *e);
void				ft_error(char *str);
int					event(t_env *e);

#endif
