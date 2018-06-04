/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_check_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:37:21 by femaury           #+#    #+#             */
/*   Updated: 2018/06/04 20:17:09 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_pos_botleft(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	stop;

	i = env->map_h - 1;
	stop = 0;
	while (!(j = 0) && !stop)
	{
		while (!stop && j < env->map_w)
		{
			if (env->map[i][j] == env->char_u)
			{
				env->start_x = j;
				env->start_y = i;
				stop = 1;
			}
			j++;
		}
		if (!i)
			break ;
		i--;
	}
}

void	check_pos_botright(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	stop;

	i = env->map_h;
	stop = 0;
	while (!(j = env->map_w) && !stop)
	{
		while (!stop)
		{
			if (env->map[i][j] == env->char_u)
			{
				env->start_x = j;
				env->start_y = i;
				stop = 1;
			}
			if (!j)
				break ;
			j--;
		}
		if (!i)
			break ;
		i--;
	}
}

void	check_pos_topright(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	stop;

	i = 0;
	stop = 0;
	while (!(j = env->map_w) && !stop && i < env->map_h)
	{
		while (!stop)
		{
			if (env->map[i][j] == env->char_u)
			{
				env->start_x = j;
				env->start_y = i;
				stop = 1;
			}
			if (!j)
				break ;
			j--;
		}
		i++;
	}
}

void	check_pos_topleft(t_env *env)
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
			if (env->map[i][j] == env->char_u)
			{
				env->start_x = j;
				env->start_y = i;
				stop = 1;
			}
			j++;
		}
		i++;
	}
}
