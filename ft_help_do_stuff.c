/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_do_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:14:16 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 17:26:12 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			g_pargs;
int			g_oargs;
int			g_hargs;

char		*ft_memconcat(char *s1, char *s2)
{
	char *ret_str;

	ret_str = NULL;
	ret_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
	{
		ft_strcpy(ret_str, s1);
		free(s1);
	}
	if (s2)
		ft_strcat(ret_str, s2);
	if (!s1 && !s2)
		return (NULL);
	else
		return (ret_str);
}

void		ft_new_r(t_lista **n, t_lista **list, t_lista **first,
		struct dirent *dp)
{
	t_lista *aux;

	aux = (*list);
	while ((*list))
	{
		if (ft_strcmp(dp->d_name, (*list)->content) > 0)
		{
			if (aux == (*list))
			{
				(*n)->next = (*list);
				(*first) = (*n);
			}
			else
			{
				(*n)->next = aux->next;
				aux->next = (*n);
			}
			break ;
		}
		aux = (*list);
		(*list) = (*list)->next;
	}
	ft_the_if(list, &aux, n);
}

void		ft_new(t_lista **n, t_lista **list, t_lista **first,
		struct dirent *dp)
{
	t_lista *aux;

	aux = (*list);
	while ((*list))
	{
		if (ft_strcmp(dp->d_name, (*list)->content) < 0)
		{
			if (aux == (*list))
			{
				(*n)->next = (*list);
				(*first) = (*n);
			}
			else
			{
				(*n)->next = aux->next;
				aux->next = (*n);
			}
			break ;
		}
		aux = (*list);
		(*list) = (*list)->next;
	}
	ft_the_if(list, &aux, n);
}

void		ft_the_if(t_lista **list, t_lista **aux, t_lista **n)
{
	if (!(*list))
	{
		(*n)->next = 0;
		(*aux)->next = (*n);
	}
}

void		lst_add(t_lista **list, struct dirent *dp)
{
	t_lista *new;
	t_lista *first;

	if (!(*list))
	{
		(*list) = (t_lista *)ft_memalloc(sizeof(t_lista));
		(*list)->content = ft_strdup(dp->d_name);
		(*list)->content_size = dp->d_reclen;
		(*list)->content_type = dp->d_type;
	}
	else
	{
		new = (t_lista *)ft_memalloc(sizeof(t_lista));
		first = (*list);
		new->content = ft_strdup(dp->d_name);
		new->content_size = dp->d_reclen;
		new->content_type = dp->d_type;
		if (g_oargs == 0)
			ft_new(&new, list, &first, dp);
		if (g_oargs == 1)
			ft_new_r(&new, list, &first, dp);
		(*list) = first;
	}
}
