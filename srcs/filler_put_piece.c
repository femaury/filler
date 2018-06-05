/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_put_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:46:52 by femaury           #+#    #+#             */
/*   Updated: 2018/06/05 21:25:13 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static float	check_distance(t_env *env, int x, int y)
{
	int		i;
	int		j;
	float	dist;
	float	min;

	i = 0;
	dist = 0;
	min = 0;
	while (i < (int)env->map_h)
	{
		j = 0;
		while (j < (int)env->map_w)
		{
			if (env->map[i][j] == env->char_u)
			{
				dist = ft_sqrt((float)(ft_pow(j - x, 2) + ft_pow(i - y, 2)));
				if (!min)
					min = dist;
				else
					min = dist < min ? dist : min;
			}
			j++;
		}
		i++;
	}
	return (min);
}

static void		get_closest_piece(t_env *env, unsigned x, unsigned y)
{
	float	dist;

	dist = 0;
	if (env->p.check)
	{
		dist = check_distance(env, x, y);
		if (env->p.dist > dist)
		{
			env->p.dist = dist;
			env->p.posx = x;
			env->p.posy = y;
		}
	}
	else
	{
		env->p.dist = check_distance(env, x, y);
		env->p.posx = x;
		env->p.posy = y;
		env->p.check = 1;
	}
}

static int		check_piece(t_env *env, unsigned i, unsigned j)
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
		get_closest_piece(env, j, i);
	return (check ? (1) : (0));
}

void			put_piece(t_env *env)
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
