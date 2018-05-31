/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_put_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:46:52 by femaury           #+#    #+#             */
/*   Updated: 2018/05/31 13:47:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_distance(t_env *env, unsigned x, unsigned y)
{
	if (env->p.check)
	{
		if (ft_sqrt(ft_pow(x - env->start_x, 2) + ft_pow(y - env->start_y, 2))
				< ft_sqrt(ft_pow(env->p.posx - env->start_x, 2)
				+ ft_pow(env->p.posy - env->start_y, 2)))
		{
			env->p.posx = x;
			env->p.posy = y;
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
	unsigned int	i;
	unsigned int	j;
	unsigned int	stop;

	i = 0;
	stop = 0;
	while (!(j = 0) && !stop && i < env->map_h)
	{
		while (!stop && j < env->map_w)
		{
			if (env->map[i][j] == env->char_u + 32)
			{
				env->start_x = j;
				env->start_y = i;
				stop = 1;
			}
			j++;
		}
		i++;
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
	while (!(l = 0) && k < env->p.true_h)
	{
		while (l < env->p.true_w)
		{
			if (k == env->p.h || l == env->p.w)
				return (0);
			if (env->p.tab[k][l] == '*')
			{
				if (env->map[i + k][j + l] == env->char_u ||
						env->map[i + k][j + l] == env->char_u + 32)
					return (0);
				if (env->map[i + k][j + l] == env->char_i)
					if (check++ > 1)
						return (0);
			}
			l++;
		}
		k++;
	}
	if (!check)
		return (0);
	check_position(env, j, i);
	return (1);
}

void		put_piece(t_env *env)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	env->p.check = 0;
	ft_printf("biz\n");
	while (i + env->p.true_h < env->map_h)
	{
		j = 0;
		while (j + env->p.true_w < env->map_w)
			check_piece(env, i, j++);
		i++;
	}
	ft_printf("yolo?\n");
	if (env->p.check)
		ft_printf("%d %d\n", (int)(env->p.posx - env->p.extra_w),
				(int)(env->p.posy - env->p.extra_h + 1));	
}
