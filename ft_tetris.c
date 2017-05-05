/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 02:01:04 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/24 02:01:05 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char **map, int i, int j, t_fgr *fg)
{
	if (map[i + fg->cord[1][0]][j + fg->cord[1][1]] == '.')
		if (map[i + fg->cord[2][0]][j + fg->cord[2][1]] == '.')
			if (map[i + fg->cord[3][0]][j + fg->cord[3][1]] == '.')
				return (1);
	return (0);
}

int		ft_place(int i, int j, int a, t_fgr *fg)
{
	if (((i + fg->cord[1][0]) < a)
		&& (0 <= (j + fg->cord[1][1]) && j + fg->cord[1][1] < a))
		if (((i + fg->cord[2][0]) < a)
		&& (0 <= (j + fg->cord[2][1]) && j + fg->cord[2][1] < a))
			if (((i + fg->cord[3][0]) < a)
			&& (0 <= (j + fg->cord[3][1]) && j + fg->cord[3][1] < a))
				return (1);
	return (0);
}

void	ft_push(char **map, int i, int j, t_fgr *fgr)
{
	map[i + fgr->cord[0][0]][j + fgr->cord[0][1]] = fgr->i;
	map[i + fgr->cord[1][0]][j + fgr->cord[1][1]] = fgr->i;
	map[i + fgr->cord[2][0]][j + fgr->cord[2][1]] = fgr->i;
	map[i + fgr->cord[3][0]][j + fgr->cord[3][1]] = fgr->i;
}

void	ft_delete(char **map, int i, int j, t_fgr *fgr)
{
	map[i + fgr->cord[0][0]][j + fgr->cord[0][1]] = '.';
	map[i + fgr->cord[1][0]][j + fgr->cord[1][1]] = '.';
	map[i + fgr->cord[2][0]][j + fgr->cord[2][1]] = '.';
	map[i + fgr->cord[3][0]][j + fgr->cord[3][1]] = '.';
}

int		ft_tetris(char **map, t_fgr **contr, int a)
{
	int i;
	int j;

	if (*contr == NULL)
		return (1);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '.')
			{
				if (ft_place(i, j, a, *contr) && ft_check(map, i, j, *contr))
				{
					ft_push(map, i, j, *contr);
					if (ft_tetris(map, &contr[1], a))
						return (1);
					ft_delete(map, i, j, *contr);
				}
			}
			j++;
		}
	}
	return (0);
}
