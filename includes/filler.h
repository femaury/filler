/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:22:01 by femaury           #+#    #+#             */
/*   Updated: 2018/05/29 20:56:54 by femaury          ###   ########.fr       */
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
# include "../libs/libft/includes/ft_gnl.h"
# include "../libs/ft_printf/includes/libftprintf.h"

typedef struct	s_piece
{
	unsigned int	w;
	unsigned int	h;
	unsigned int	extra_w;
	unsigned int	extra_h;
	char			**tab;
}				t_piece;

typedef struct	s_env
{
	unsigned int	map_w;
	unsigned int	map_h;
	char			**map;
	char			char_i;
	char			char_u;
	unsigned int	start_i;
	unsigned int	start_u;
	unsigned int	last_i;
	unsigned int	last_u;
	t_piece			p;
}				t_env;

int				set_piece(t_env *env);

#endif
