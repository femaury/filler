/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:22:01 by femaury           #+#    #+#             */
/*   Updated: 2018/05/28 17:39:02 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

# include "../libs/libft/includes/libft.h"
# include "../libs/ft_printf/includes/libftprintf.h"

typedef struct	s_piece
{
	unsigned int	width;
	unsigned int	height;
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

#endif
