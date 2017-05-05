/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_fillit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 21:08:16 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/17 21:08:17 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_strsplit_fillit(char *s)
{
	size_t	i;
	char	**array;

	i = 0;
	array = (char**)malloc(sizeof(char*) * 5);
	if (!array)
	{
		ft_error();
		return (NULL);
	}
	while (i < 4)
	{
		array[i] = ft_strsub(s, 0, 4);
		s = s + 5;
		i++;
	}
	array[4] = 0;
	return (array);
}
