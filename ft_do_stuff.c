/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:00:39 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 17:29:09 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int g_sargs;
int g_pargs;
int g_oargs;
int g_hargs;

void		ft_print(t_lista *list, t_len *lens)
{
	char	hidden;

	hidden = 0;
	if (!g_hargs)
		hidden = '.';
	if (g_pargs)
	{
		ft_putstr("total ");
		ft_putnbr(ft_add_blocksize(list, hidden));
		ft_putendl("");
	}
	while (list)
	{
		if (*((char *)list->content) != hidden)
		{
			if (!g_pargs)
				ft_putendl(list->content);
			else
			{
				ft_putendl(assemble_string(list, lens));
			}
		}
		list = list->next;
	}
}

void		print_dir(DIR *directory, char *dir_path)
{
	t_lista			*list;
	struct dirent	*temp;

	list = NULL;
	while ((temp = readdir(directory)) != NULL)
		lst_add(&list, temp);
	ft_print(list, ft_build_print_data(list, dir_path));
}

void		paths_now_what(char **paths, int put_dirnames)
{
	int			i;
	struct stat	*s_stat;
	DIR			*directory;

	directory = NULL;
	s_stat = (struct stat *)malloc(sizeof(struct stat));
	i = 0;
	while (paths[i])
	{
		if (lstat(paths[i], s_stat) == 0)
		{
			if (!(S_ISDIR(s_stat->st_mode)))
			{
				ft_putendl(paths[i]);
				free(s_stat);
				s_stat = (struct stat *)malloc(sizeof(struct stat));
			}
		}
		i++;
	}
	i = 0;
	ft_while_one(paths, s_stat, directory, put_dirnames);
}

void		ft_while_one(char **paths, struct stat *s_stat, DIR *directory,
		int put_dirnames)
{
	int i;

	i = 0;
	while (paths[i])
	{
		if (lstat(paths[i], s_stat) == 0)
		{
			if (S_ISDIR(s_stat->st_mode))
			{
				free(s_stat);
				s_stat = (struct stat *)malloc(sizeof(struct stat));
				if ((directory = opendir(paths[i])) != NULL)
					if_in_the_while(paths, directory, put_dirnames, i);
				else
					perror("ft_ls ");
			}
		}
		else
			perror("ft_ls ");
		i++;
	}
}

void		if_in_the_while(char **paths, DIR *directory, int put_dirnames,
		int i)
{
	if (put_dirnames)
	{
		ft_putstr(paths[i]);
		ft_putendl(":");
	}
	print_dir(directory, ft_strdup(paths[i]));
	if (paths[i + 1])
		ft_putendl("");
	closedir(directory);
}
