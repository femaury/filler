/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_set_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:11:16 by femaury           #+#    #+#             */
/*   Updated: 2018/06/03 14:45:34 by femaury          ###   ########.fr       */
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
		if (j || env->p.tab[i][j] == '*')
			max = j > max ? j : max;
		else if (env->p.tab[i][0] != '*')
			env->p.true_h--;
		i++;
	}
	env->p.true_w = env->p.w - (env->p.w - max) + 1;
}

static void	cut_piece(t_env *env)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	while (i < env->p.extra_h)
		ft_strdel(&env->p.tab[i++]);
	while (i < env->p.h)
	{
		env->p.tab[i - env->p.extra_h] = env->p.tab[i];
		i++;
	}
	i = 0;
	while (i < env->p.h - env->p.extra_h)
	{
		tmp = env->p.tab[i];
		env->p.tab[i] = ft_strdup(env->p.tab[i] + env->p.extra_w);
		ft_strdel(&tmp);
		i++;
	}
	env->p.w -= env->p.extra_w;
	env->p.h -= env->p.extra_h;
	get_true_values(env);
}

static int	create_piece(t_env *env, char *line, unsigned j, unsigned check)
{
	unsigned int	i;

	i = 0;
	env->p.extra_w = UINT_MAX;
	env->p.extra_h = 0;
	if (!(env->p.tab = (char **)malloc(sizeof(char *) * env->p.h)))
		filler_exit(0, NULL);
	while (!(j = 0) && i < env->p.h && get_next_line(0, &line) > 0)
	{
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
			filler_exit(1, line);
		env->p.tab[i++] = line;
	}
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
	j = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		filler_exit(1, line);
	if (!(!ft_strncmp(line, "Piece ", 6) && ft_isdigit(*(line + 6))))
		filler_exit(1, line);
	env->p.h = ft_atoi(line + 6);
	tmp = env->p.h;
	while (tmp > 9 && ++i)
		tmp /= 10;
	if (!ft_isdigit(*(line + i + 7)))
		filler_exit(1, line);
	env->p.w = ft_atoi(line + i + 7);
	ft_strdel(&line);
	create_piece(env, line, j, (check = 0));
	return (0);
}
