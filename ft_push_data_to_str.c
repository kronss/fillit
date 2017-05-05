/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_data_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:12:02 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/22 17:12:03 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lookf_firstcord(int *x, int *y, char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == '#')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_fgr		*ft_fgr_creat_new_fgr(char **array, int fgrs, int x, int y)
{
	t_fgr	*new_fgr;
	int		i;
	int		j;
	int		k;

	new_fgr = (t_fgr *)malloc(sizeof(t_fgr) * 1);
	(!new_fgr) ? ft_error() : 0;
	k = -1;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == '#')
			{
				new_fgr->cord[++k][0] = i - y;
				new_fgr->cord[k][1] = j - x;
			}
			j++;
		}
		i++;
	}
	new_fgr->i = ('A' + fgrs);
	return (new_fgr);
}

t_fgr		*ft_push_data_to_str(char **array, int fgrs)
{
	int		x;
	int		y;

	ft_lookf_firstcord(&x, &y, array);
	return (ft_fgr_creat_new_fgr(array, fgrs, x, y));
}
