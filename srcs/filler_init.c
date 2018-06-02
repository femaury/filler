/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:16:47 by femaury           #+#    #+#             */
/*   Updated: 2018/06/02 16:43:49 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct(t_env *env)
{
	env->map_w = 0;
	env->map_h = 0;
	env->map = NULL;
	env->char_i = 0;
	env->char_u = 0;
	env->start_x = 0;
	env->start_y = 0;
	env->check_top = 1;
	env->p.w = 0;
	env->p.h = 0;
	env->p.extra_w = 0;
	env->p.extra_h = 0;
	env->p.true_w = 0;
	env->p.true_h = 0;
	env->p.tab = NULL;
	env->p.check = 0;
	env->p.posx = 0;
	env->p.posy = 0;
}
