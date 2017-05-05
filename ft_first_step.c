/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 19:49:55 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/17 19:49:56 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_is_bn(char *str)
{
	int			cnt_bn;
	int			i;

	i = 0;
	cnt_bn = 0;
	if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n'
		&& str[19] == '\n' && (str[20] == '\n' || (str[20] == '\0')))
	{
		while (i < 20 && str[i] != '\0')
		{
			str[i] == '\n' ? cnt_bn++ : 0;
			i++;
		}
	}
	if (cnt_bn == 4)
		return (1);
	ft_error();
	return (0);
}

int				ft_is_symb(char *str)
{
	int			cnt_hs;
	int			cnt_dot;
	int			i;

	cnt_hs = 0;
	cnt_dot = 0;
	i = 0;
	while (i < 20 && (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	&& str[i] != '\0')
	{
		str[i] == '.' ? cnt_dot++ : 0;
		str[i] == '#' ? cnt_hs++ : 0;
		i++;
	}
	if (i == 20 && cnt_dot == 12 && cnt_hs == 4)
		return (1);
	ft_error();
	return (0);
}

void			ft_is_fgr_valid(char **array)
{
	int			i;
	int			j;
	int			cnt;

	i = 0;
	cnt = 0;
	while (array[i] != '\0')
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == '#')
			{
				(i > 0) && array[i - 1][j] == '#' ? cnt++ : 0;
				(i < 3) && array[i + 1][j] == '#' ? cnt++ : 0;
				(j < 3) && array[i][j + 1] == '#' ? cnt++ : 0;
				(j > 0) && array[i][j - 1] == '#' ? cnt++ : 0;
			}
			j++;
		}
		i++;
	}
	if (cnt < 6)
		(ft_error());
}

void			ft_first_step(char *ar, int len)
{
	int			fgrs;
	char		***array;
	t_fgr		**container;

	container = 0;
	fgrs = 0;
	array = (char***)(malloc(sizeof(char**) * (len)));
	container = (t_fgr**)(malloc(sizeof(t_fgr*) * (len)));
	if (!array || !container)
		ft_error();
	while (*ar != '\0' && ft_is_bn(ar) && ft_is_symb(ar))
	{
		array[fgrs] = ft_strsplit_fillit(ar);
		ft_is_fgr_valid(array[fgrs]);
		container[fgrs] = ft_push_data_to_str(array[fgrs], fgrs);
		ar = ar + 21;
		fgrs++;
	}
	container[fgrs] = NULL;
	ft_second_step(container, fgrs);
}
