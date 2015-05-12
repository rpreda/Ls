/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_do_stuff_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:27:45 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 17:28:30 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len		*ft_build_print_data(t_lista *lst, char *path)
{
	char	*temp_path;
	t_len	*lens;

	lens = (t_len *)ft_memalloc(sizeof(t_len));
	temp_path = path;
	path = ft_strjoin(path, "/");
	free(temp_path);
	while (lst)
	{
		temp_path = ft_strjoin(path, lst->content);
		lst->infos = grab_infos(temp_path);
		if (ft_strlen(lst->infos->filename) > lens->filename_len)
			lens->filename_len = ft_strlen(lst->infos->filename);
		if (ft_strlen(lst->infos->links) > lens->links_len)
			lens->links_len = ft_strlen(lst->infos->links);
		if (ft_strlen(lst->infos->usrname) > lens->username_len)
			lens->username_len = ft_strlen(lst->infos->usrname);
		if (ft_strlen(lst->infos->usrgrp) > lens->usrgrp_len)
			lens->usrgrp_len = ft_strlen(lst->infos->usrgrp);
		if (ft_strlen(lst->infos->bytesize) > lens->bytesize_len)
			lens->bytesize_len = ft_strlen(lst->infos->bytesize);
		lst = lst->next;
		free(temp_path);
	}
	return (lens);
}

void		ft_add_spaces(size_t max_len, char **string)
{
	char *free_help;

	while (ft_strlen(*string) < max_len)
	{
		free_help = *string;
		*string = ft_strjoin(" ", *string);
		free(free_help);
	}
}

char		*assemble_string(t_lista *elem, t_len *lens)
{
	char *ret_val;

	ret_val = ft_strjoin(elem->infos->acces, "  ");
	ft_add_spaces(lens->links_len, &(elem->infos->links));
	ret_val = ft_memconcat(ret_val, elem->infos->links);
	ret_val = ft_memconcat(ret_val, " ");
	ft_add_spaces(lens->username_len, &(elem->infos->usrname));
	ret_val = ft_memconcat(ret_val, elem->infos->usrname);
	ret_val = ft_memconcat(ret_val, "  ");
	ft_add_spaces(lens->usrgrp_len, &(elem->infos->usrgrp));
	ret_val = ft_memconcat(ret_val, elem->infos->usrgrp);
	ret_val = ft_memconcat(ret_val, "  ");
	ft_add_spaces(lens->bytesize_len, &(elem->infos->bytesize));
	ret_val = ft_memconcat(ret_val, elem->infos->bytesize);
	ret_val = ft_memconcat(ret_val, " ");
	ret_val = ft_memconcat(ret_val, elem->infos->date_formated);
	ret_val = ft_memconcat(ret_val, " ");
	ret_val = ft_memconcat(ret_val, elem->content);
	return (ret_val);
}

int			ft_add_blocksize(t_lista *list, char hidden)
{
	int ret;

	ret = 0;
	while (list)
	{
		if (*((char *)list->content) != hidden)
			ret = ret + (int)list->infos->blksize;
		list = list->next;
	}
	return (ret);
}
