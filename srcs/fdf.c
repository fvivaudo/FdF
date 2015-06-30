/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:11:18 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/01/03 11:11:20 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	set_param(t_env *e)
{
	e->sc = 1;
	while (e->sc * 2 * e->max < 1000)
		e->sc++;
	e->hgt = (e->sc / 2 > 0) ? e->sc / 2 : 1;
	e->gapy = e->sc * e->x_max;
}

int		gere_expose_wait(t_env *e)
{
	int change;

	change = event(e);
	if (change > 0 || (change += env_change(e) == 1))
	{
		mlx_clear_window(e->mlx, e->win);
		draw(*e);
		mlx_do_sync(e->mlx);
	}
	return (0);
}

t_env	ft_init(void)
{
	t_env	e;

	ft_bzero((char*)&e, sizeof(t_env));
	return (e);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		fd;

	e = ft_init();
	e.x_max = 1;
	if (((fd = open(av[1], O_RDONLY)) == (-1)) || ac != 2)
		ft_error("invalid parameter");
	e.map = envdealer(fd, 1, 0, &e);
	if (e.h_max > 100000 || e.h_max < -100000)
		ft_error("invalid map");
	e.max = e.x_max > e.y_max ? e.x_max : e.y_max;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "42");
	set_param(&e);
	draw(e);
	mlx_hook(e.win, 2, (1L << 0), key_pressed, &e);
	mlx_hook(e.win, 3, (1L << 1), key_released, &e);
	mlx_expose_hook(e.win, gere_expose_wait, &e);
	mlx_loop_hook(e.mlx, gere_expose_wait, &e);
	mlx_loop(e.mlx);
	return (0);
}
