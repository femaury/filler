/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_set_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:11:16 by femaury           #+#    #+#             */
/*   Updated: 2018/06/02 13:25:10 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_true_values(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	max;

	i = 0;
	max = 0;
	env->p.true_h = env->p.h;
	while ((j = env->p.w) && i < env->p.h)
	{
		while (env->p.tab[i][j] != '*')
		{
			if (!j)
				break ;
			j--;
		}
		dprintf(fd, "j: %u width: %u\n", j, env->p.w);
		if (j || env->p.tab[i][j] == '*')
			max = j > max ? j : max;
		else if (env->p.tab[i][0] != '*')
			env->p.true_h--;
		i++;
	}
	env->p.true_w = env->p.w - (env->p.w - max) + 1;
}

/*
 * 		DOUBLE FREE
 *
 *	  Inside cut_piece
 *	  Between 2 and 3
*/	

static void	cut_piece(t_env *env)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	while (i < env->p.h)
		dprintf(fd, "%s\n", env->p.tab[i++]);
	i = 0;
	while (i < env->p.extra_h)
		ft_strdel(&env->p.tab[i++]);
	dprintf(fd, "free i: %u extra: %u\n", i, env->p.extra_h);
	while (i < env->p.h)
	{
		dprintf(fd, "tab[%u]: %s\n", i, env->p.tab[i]);
		env->p.tab[i - env->p.extra_h] = env->p.tab[i];
//		if (i >= env->p.h - env->p.extra_h)
//			ft_strdel(&env->p.tab[i]);
		i++;
	}
	dprintf(fd, "free 2\n");
	i = 0;
	while (i < env->p.h - env->p.extra_h)
		dprintf(fd, "%s\n", env->p.tab[i++]);
	i = 0;
	while (i < env->p.h - env->p.extra_h)
	{
		dprintf(fd, "loop i: %u\n", i);
		tmp = env->p.tab[i];
		env->p.tab[i] = ft_strdup(env->p.tab[i] + env->p.extra_w);
		ft_strdel(&tmp);
		i++;
	}
	dprintf(fd, "free 3\n");
	env->p.w -= env->p.extra_w;
	env->p.h -= env->p.extra_h;
	get_true_values(env);
}

static int	create_piece(t_env *env, char *line, unsigned j, unsigned check)
{
	unsigned int	i;

	env->p.extra_w = UINT_MAX;
	env->p.extra_h = 0;
	if (!(i = 0) && !(env->p.tab = (char **)malloc(sizeof(char *) * env->p.h)))
		return (1);
	dprintf(fd, "--> BEFORE PIECE = %u <--\n", gnlcount);
	while (!(j = 0) && i < env->p.h && get_next_line(0, &line) > 0)
	{
		gnlcount++;
		while (line[j])
			if (line[j++] == '*')
			{
				env->p.extra_w = j - 1 > env->p.extra_w
					? env->p.extra_w : j - 1;
				check = 1;
				break ;
			}
		if (!line[j] && !check)
			env->p.extra_h++;
		if (ft_strlen(line) > env->p.w)
			return (1);
		env->p.tab[i++] = line;
	}
	dprintf(fd, "--> AFTER  PIECE = %u <--\n", gnlcount);
	cut_piece(env);
	return (0);
}

int			set_piece(t_env *env)
{
	int				tmp;
	char			*line;
	unsigned int	i;
	unsigned int	j;
	unsigned int	check;

	i = 1;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (1);
	gnlcount++;
	if (!(!ft_strncmp(line, "Piece ", 6) && ft_isdigit(*(line + 6))))
		return (1);
	env->p.h = ft_atoi(line + 6);
	tmp = env->p.h;
	while (tmp > 9 && ++i)
		tmp /= 10;
	if (!ft_isdigit(*(line + i + 7)))
		return (1);
	env->p.w = ft_atoi(line + i + 7);
	ft_strdel(&line);
	if (create_piece(env, line, (j = 0), (check = 0)))
		return (1);
	return (0);
}
