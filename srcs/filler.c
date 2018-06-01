/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:48:12 by femaury           #+#    #+#             */
/*   Updated: 2018/06/01 21:11:27 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	set_player(t_env *env, char *line)
{
	env->char_i = ft_strncmp(line, "$$$ exec p1", 11) ? 'X' : 'O';
	env->char_u = env->char_i == 'X' ? 'O' : 'X';
	ft_strdel(&line);
	dprintf(fd, "Set player\n");
	fflush(NULL);
	return (0);
}

static int	create_map(t_env *env, char *line)
{
	unsigned int	i;
	unsigned int	j;

	if (!(env->map = (char **)malloc(sizeof(char *) * (env->map_h + 1))))
		return (1);
	if (!(i = 0) && get_next_line(0, &line) <= 0)
		return (1);
	gnlcount++;
	ft_strdel(&line);
	while ((j = 4) && i < env->map_h && get_next_line(0, &line) > 0)
	{
		gnlcount++;
		while (line[j] && line[j] != env->char_u)
			j++;
		if (line[j])
		{
			env->start_y = i;
			env->start_x = j - 4;
		}
		if (!ft_strisonly(line + 4, ".OXox") || ft_strlen(line) > env->map_w + 4)
			return (1);
		env->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	dprintf(fd, "Created map\n");
	fflush(NULL);
	return (0);
}

static int	set_map(t_env *env)
{
	int		i;
	int		tmp;
	char	*line;

	i = 1;
	line = NULL;
	if (!(get_next_line(0, &line) > 0 && line && !ft_strncmp(line, "Plateau ", 8)))
		return (1);
	gnlcount++;
	if (!ft_isdigit(*(line + 8)))
		return (1);
	env->map_h = ft_atoi(line + 8);
	tmp = env->map_h;
	while (tmp > 0 && ++i)
		tmp /= 10;
	if (!ft_isdigit(*(line + i + 8)))
		return (1);
	env->map_w = ft_atoi(line + i + 8);
	ft_strdel(&line);
	if (create_map(env, line))
		return (1);
	dprintf(fd, "Set map\n");
	fflush(NULL);
	return (0);
}

int			main(void)
{
	char				*line;
	t_env				env;

	line = NULL;
	fd = open("/dev/ttys002", O_WRONLY);
	init_struct(&env);
	while (1)
	{
		gnlcount = 0;
		get_next_line(0, &line);
		gnlcount++;
		if (line)
		{
			dprintf(fd, "%s\n", line);
			fflush(NULL);
			if (!ft_strncmp(line, "$$$ exec p", 9))
			{
				if (set_player(&env, line) || set_map(&env) || set_piece(&env))
					return (1);
			}
			else 
			{
				ft_tabdel((void **)env.map, env.map_h);
				ft_tabdel((void **)env.p.tab, env.p.h);
				if (create_map(&env, line) || set_piece(&env))
					return (1);
			}
			dprintf(fd, "---- GNL COUNTS = %d ----\n", gnlcount);
			fflush(NULL);
			put_piece(&env);
		}
	}
	close(fd);
	return (0);
}
