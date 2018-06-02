/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:22:01 by femaury           #+#    #+#             */
/*   Updated: 2018/06/02 14:43:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <limits.h>

# include "../libs/libft/includes/libft.h"
# include "../libs/libft/includes/get_next_line.h"
# include "../libs/ft_printf/includes/libftprintf.h"

int				fd;
int				gnlcount;

typedef struct	s_piece
{
	unsigned int	w;
	unsigned int	h;
	unsigned int	extra_w;
	unsigned int	extra_h;
	unsigned int	true_w;
	unsigned int	true_h;
	char			**tab;
	unsigned int	check;
	unsigned int	posx;
	unsigned int	posy;
}				t_piece;

typedef struct	s_env
{
	unsigned int	map_w;
	unsigned int	map_h;
	char			**map;
	char			char_i;
	char			char_u;
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	check_top;
	t_piece			p;
}				t_env;

void			init_struct(t_env *env);
void			put_piece(t_env *env);
int				set_piece(t_env *env);

#endif
