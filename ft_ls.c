/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:02:23 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 16:28:07 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int g_sargs;
int g_pargs;
int g_oargs;
int g_hargs;

void		arg_interpret(char *s)
{
	while (*s++)
	{
		if (*s == 'l')
			g_pargs = 1;
		if (*s == 'a')
			g_hargs = 1;
		if (*s == 'R')
			g_sargs = 1;
		if (*s == 'r')
			g_oargs = 1;
		if (*s == 't')
			g_oargs = 2;
	}
}

char		**interpret_args(int argc, char **argv)
{
	int		i;
	char	**ret;
	int		k;

	i = 1;
	k = 0;
	ret = (char **)malloc(sizeof(char *) * 100);
	while (i < argc)
	{
		if (argv[i][0] == '-')
			arg_interpret(argv[i]);
		else
		{
			ret[k] = ft_strdup(argv[i]);
			k++;
		}
		i++;
	}
	if (!k)
	{
		ret[k] = ".";
		k = 1;
	}
	ret[k] = NULL;
	return (ret);
}

int			main(int argc, char **argv)
{
	char	**paths;
	int		d_names;

	paths = interpret_args(argc, argv);
	sort_matrix(paths);
	if (paths[1])
		d_names = 1;
	else
		d_names = 0;
	paths_now_what(paths, d_names);
	return (0);
}
