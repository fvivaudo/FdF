/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:32:16 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/03/23 12:32:17 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_line2(t_coord c, t_env e)
{
	while (1)
	{
		mlx_pixel_put(e.mlx, e.win, c.x0, c.y0, 0xFF0000);
		if (c.x0 == c.x1 && c.y0 == c.y1)
			break ;
		c.e2 = c.err;
		if (c.e2 > -c.dx)
		{
			c.err -= c.dy;
			c.x0 += c.sx;
		}
		if (c.e2 < c.dy)
		{
			c.err += c.dx;
			c.y0 += c.sy;
		}
	}
}

void	draw_line(t_coord c, t_env e)
{
	c.dx = c.x1 - c.x0;
	if (c.dx < 0)
		c.dx = c.dx * (-1);
	c.sx = c.x0 < c.x1 ? 1 : -1;
	c.dy = c.y1 - c.y0;
	if (c.dy < 0)
		c.dy = c.dy * (-1);
	c.sy = c.y0 < c.y1 ? 1 : -1;
	c.err = (c.dx > c.dy ? c.dx : -c.dy) / 2;
	draw_line2(c, e);
}

void	draw(t_env e)
{
	e.coord.x0 = 0;
	e.coord.y0 = 0;
	e.coord.x1 = 0;
	e.coord.y1 = 0;
	e.x = 0;
	e.y = 0;
	e.iso1 = 0;
	e.iso2 = 0;
	while (e.x < e.x_max)
	{
		e.iso2 += e.sc;
		while (e.y < e.y_max)
		{
			e.iso1 += e.sc;
			deal_coord(e.coord, e);
			e.y++;
		}
		e.iso1 = 0;
		e.y = 0;
		e.x++;
	}
}

void	deal_coord(t_coord coord, t_env e)
{
	coord.x0 = e.x * e.sc + e.gapx + e.iso1 - e.sc;
	coord.y0 = e.y * e.sc + e.gapy - e.iso2 - e.map[e.x][e.y] * e.hgt;
	coord.x1 = coord.x0 + e.sc;
	if (e.y + 1 < e.y_max)
	{
		coord.y1 = coord.y0 + e.sc - e.map[e.x][e.y + 1] *
		e.hgt + e.map[e.x][e.y] * e.hgt;
		draw_line(coord, e);
	}
	coord.x0 = e.x * e.sc + e.gapx + e.iso1 - e.sc;
	coord.y0 = e.y * e.sc + e.gapy - e.iso2 - e.map[e.x][e.y] * e.hgt;
	if (e.x + 1 < e.x_max)
	{
		coord.y1 = coord.y0 - e.sc - e.map[e.x + 1][e.y] *
		e.hgt + e.map[e.x][e.y] * e.hgt;
		coord.x1 = coord.x0 + e.sc;
		draw_line(coord, e);
	}
}
