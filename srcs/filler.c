/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:48:12 by femaury           #+#    #+#             */
/*   Updated: 2018/05/28 20:09:29 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_player(t_env *env)
{
	char	*line;

	line = NULL;
	if ((ft_gnl(0, &line)) <= 0)
		return (1);
	env->char_i = ft_strncmp(line, "$$$ exec p1", 11) ? 'X' : 'O';
	env->char_u = env->char_i == 'X' ? 'O' : 'X';
	ft_strdel(&line);
	return (0);
}

static int	create_map(t_env *env, char *line)
{
	unsigned int	i;

	if (!(env->map = (char **)malloc(sizeof(char *) * (env->map_h + 1))))
		return (1);
	if (!(env->map[env->map_h] = (char *)ft_memalloc(env->map_w)))
		return (1);
	while (ft_gnl(0, &line) > 0 && !(i = 0) && i > env->map_h)
	{
		if (!ft_strisonly(line, ".OX") || ft_strlen(line) > env->map_w + 4)
			return (1);
		env->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

static int	set_map(t_env *env)
{
	int		i;
	int		tmp;
	char	*line;

	i = 1;
	line = NULL;
	if ((ft_gnl(0, &line)) <= 0)
		return (1);
	if (ft_strncmp(line, "Plateau ", 8) && ft_isdigit(*(line + 8)))
		env->map_h = ft_atoi(line + 8);
	else
		return (1);
	tmp = env->map_h;
	while (tmp > 0 && ++i)
		tmp /= 10;
	if (ft_isdigit(*(line + i + 9)))
		env->map_w = ft_atoi(line + i + 9);
	else
		return (1);
	ft_strdel(&line);
	if (create_map(env, line))
		return (1);
	return (0);
}

int			main(void)
{
	t_env	env;

	if (set_player(&env) && set_map(&env))
		return (1);
	return (0);
}
