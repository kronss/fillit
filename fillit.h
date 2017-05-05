/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:13:54 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/12 10:13:55 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_fgr
{
	int			cord[4][2];
	char		i;
}				t_fgr;

void			ft_error(void);
void			ft_first_step(char *ar, int len);
void			ft_second_step(t_fgr **container, int fgrs);
char			**ft_strsplit_fillit(char *s);
void			ft_usage(char *argv);
void			ft_print_map(char **s);
t_fgr			*ft_push_data_to_str(char **array, int fgrs);
void			print_map(char **s);
int				ft_tetris(char **map, t_fgr **container, int a);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putchar(char c);
void			ft_bzero(void *s, size_t n);

#endif
