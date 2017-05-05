/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:38:49 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/10 17:55:35 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		fgrs;
	char	*buf;
	int		len;

	fgrs = 0;
	if (argc != 2)
		ft_usage(argv[0]);
	fd = open(argv[1], O_RDONLY);
	buf = ft_strnew(546);
	(fd == -1) ? ft_error() : read(fd, buf, 546);
	(close(fd) == -1) ? ft_error() : 0;
	ft_strlen(buf) >= 546 ? ft_error() : 0;
	((ft_strlen(buf) + 1) % 21 != 0) ? ft_error() : 0;
	len = ((ft_strlen(buf) + 1) / 21 + 1);
	ft_first_step(buf, len);
	return (0);
}
