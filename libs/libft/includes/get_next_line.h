/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:13:33 by cholm             #+#    #+#             */
/*   Updated: 2018/06/02 16:50:08 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

# define BUFF_SIZE 42

typedef struct	s_vars
{
	int		i;
	int		end;
	int		read_val;
	char	readbuf[BUFF_SIZE + 1];
}				t_vars;

int				get_next_line(const int fd, char **line);

#endif
