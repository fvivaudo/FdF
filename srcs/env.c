/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvivaudo <fvivaudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:34:36 by fvivaudo          #+#    #+#             */
/*   Updated: 2015/03/23 12:34:37 by fvivaudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		**envdealer2(int size, t_env *e, int **tab, char *line)
{
	++size;
	tab = (int**)malloc(sizeof(int*) * size);
	e->x_max = size;
	tab[e->x_max - size] = add_line(line, e);
	ft_strdel(&line);
	return (tab);
}

int		**envdealer(int fd, int i, int size, t_env *e)
{
	char	*line;
	int		**tab;

	tab = NULL;
	i = get_next_line(fd, &line);
	if (ft_strlen(line) == 0)
	{
		tab = (int**)malloc(sizeof(int*) * size);
		e->x_max = size;
		return (tab);
	}
	if (i == 1)
	{
		++size;
		tab = envdealer(fd, i, size, e);
		tab[e->x_max - size] = add_line(line, e);
		ft_strdel(&line);
	}
	else
		tab = envdealer2(size, e, tab, line);
	return (tab);
}

int		*add_line(char *line, t_env *e)
{
	char	**tab;
	int		i;
	int		*res;

	i = 0;
	tab = ft_strsplit(line, ' ');
	tab = add_line2(e, &i, tab);
	if (i == 0)
		return (NULL);
	res = (int*)malloc(sizeof(int) * (i));
	e->y_max = i;
	while (--i > -1)
	{
		res[i] = ft_atoi(tab[i]);
		if (res[i] > e->h_max || res[i] < e->h_max * (-1))
			e->h_max = res[i];
		ft_strdel(&tab[i]);
	}
	tab = NULL;
	free(tab);
	return (res);
}

char	**add_line2(t_env *e, int *i, char **tab)
{
	while (tab[*i])
	{
		if (ft_ldiff("-0123456789", tab[*i]) != -1)
			ft_error("invalid map");
		++(*i);
	}
	if (e->ref == 0)
		e->ref = *i;
	if (*i != e->ref)
		ft_error("invalid map");
	return (tab);
}
