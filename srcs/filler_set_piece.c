/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_set_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:11:16 by femaury           #+#    #+#             */
/*   Updated: 2018/05/29 21:32:08 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
		if (i > env->p.h - env->p.extra_h + 1)
			ft_strdel(&env->p.tab[i]);
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
}

static int	create_piece(t_env *env, char *line, unsigned j, unsigned check)
{
	unsigned int	i;

	env->p.extra_w = UINT_MAX;
	if (!(i = 0) && !(env->p.tab = (char **)malloc(sizeof(char *) * env->p.h)))
		return (1);
	while (i < env->p.h && ft_gnl(0, &line) > 0 && !(j = 0))
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
			return (1);
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
	line = NULL;
	if (ft_gnl(0, &line) <= 0)
		return (1);
	if (!(!ft_strncmp(line, "Piece ", 6) && ft_isdigit(*(line + 6))))
		return (1);
	env->p.h = ft_atoi(line + 6);
	tmp = env->p.h;
	while (tmp > 0 && ++i)
		tmp /= 10;
	if (!ft_isdigit(*(line + i + 6)))
		return (1);
	env->p.w = ft_atoi(line + i + 6);
	ft_strdel(&line);
	if (create_piece(env, line, (j = 0), (check = 0)))
		return (1);
	return (0);
}
