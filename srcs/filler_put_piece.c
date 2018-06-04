/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_put_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:46:52 by femaury           #+#    #+#             */
/*   Updated: 2018/06/04 21:23:31 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_distance(t_env *env, unsigned x, unsigned y)
{
	if (env->p.check)
	{
		if (ft_sqrt((float)(ft_pow(x - env->start_x, 2) +
				ft_pow(y - env->start_y, 2)))
				< ft_sqrt((float)(ft_pow(env->p.posx - env->start_x, 2)
				+ ft_pow(env->p.posy - env->start_y, 2))))
		{
			env->p.posx = x;
			env->p.posy = y;
			if (ft_strhasc(env->map[0], env->char_i)
						|| ft_strisonlyc(env->map[0], env->char_u))
				env->check_top = 0;
			if (env->start_top
					&& (ft_strhasc(env->map[env->map_h - 1], env->char_i)))
				env->check_top = 0;

		}
	}
	else
	{
		env->p.posx = x;
		env->p.posy = y;
		env->p.check = 1;
	}
}

static void	check_position(t_env *env, unsigned x, unsigned y)
{
	if (!env->start_top)
	{
		if (env->check_top)
			check_pos_topleft(env);
		else
			check_pos_botright(env);
	}
	else
	{
		if (!env->check_top)
			check_pos_topright(env);
		else
			check_pos_botleft(env);
	}
	check_distance(env, x, y);
}

static int	check_piece(t_env *env, unsigned i, unsigned j)
{
	unsigned int	k;
	unsigned int	l;
	unsigned int	check;

	k = 0;
	check = 0;
	while (!(l = 0) && i + k <= env->map_h && k < env->p.true_h)
	{
		while (j + l <= env->map_w && l < env->p.true_w)
		{
			if (env->p.tab[k][l] == '*')
			{
				if (env->map[i + k][j + l] == env->char_u)
					return (0);
				if (env->map[i + k][j + l] == env->char_i)
					if (++check > 1)
						return (0);
			}
			l++;
		}
		k++;
	}
	if (check)
		check_position(env, j, i);
	return (check ? (1) : (0));
}

void		put_piece(t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	env->p.check = 0;
	while (i + env->p.true_h <= env->map_h)
	{
		j = 0;
		while (j + env->p.true_w <= env->map_w)
			check_piece(env, i, j++);
		i++;
	}
	if (env->p.check)
		ft_printf("%d %d\n", (int)env->p.posy - (int)env->p.extra_h,
				(int)env->p.posx - (int)env->p.extra_w);
	else
		ft_printf("0 0\n");
}
