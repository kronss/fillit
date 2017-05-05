/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 20:16:17 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/23 20:16:18 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_take_a_side(int *a, int fgrs)
{
	int		s;

	*a = 2;
	s = 4 * fgrs;
	while (*a * *a < s)
		(*a)++;
}

void		ft_strdot(char *s, int a)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (i < a)
		{
			s[i] = '.';
			i++;
		}
		s[i] = '\0';
	}
}

char		**ft_create_map(int a)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (a + 1));
	if (!map)
		ft_error();
	i = 0;
	while (i < a)
	{
		map[i] = (char *)malloc(sizeof(char) * (a + 1));
		(!map[i]) ? ft_error() : ft_strdot(map[i], a);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void		ft_second_step(t_fgr **container, int fgrs)
{
	int		i;
	int		a;
	char	**map;

	ft_take_a_side(&a, fgrs);
	map = ft_create_map(a);
	while (!ft_tetris(map, container, a))
	{
		i = 0;
		while (i <= a)
		{
			free(map[i]);
			i++;
		}
		free(map);
		a++;
		map = ft_create_map(a);
	}
	ft_print_map(map);
}
