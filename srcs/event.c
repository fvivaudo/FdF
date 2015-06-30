/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:36:32 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/03/23 12:36:33 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		event(t_env *e)
{
	int		change;

	change = 0;
	if (e->key[24] == 1)
		++(e->sc), ++change;
	if (e->key[27] == 1)
		--(e->sc), ++change;
	if (e->key[69] == 1)
		++(e->hgt), ++change;
	if (e->key[78] == 1)
		--(e->hgt), ++change;
	if (e->key[126] == 1)
		(e->gapy) -= 5, ++change;
	if (e->key[125] == 1)
		(e->gapy) += 5, ++change;
	if (e->key[123] == 1)
		(e->gapx) -= 5, ++change;
	if (e->key[124] == 1)
		(e->gapx) += 5, ++change;
	return (change);
}

int		key_released(int keycode, t_env *e)
{
	e->key[keycode] = 0;
	return (0);
}

int		key_pressed(int keycode, t_env *e)
{
	e->key[keycode] = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		env_change(t_env *e)
{
	static	t_env	cmpenv;

	if (ft_memcmp(&cmpenv, e, 120) != 0)
	{
		ft_memcpy(&cmpenv, e, 120);
		return (1);
	}
	ft_memcpy(&cmpenv, e, 120);
	return (0);
}
