/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_grab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:07:59 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 17:11:03 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t			count_digits(long long n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char					*ft_itoa_long(long long n)
{
	size_t				len;
	char				*str;
	unsigned long long	u_nbr;

	len = count_digits(n);
	u_nbr = n;
	if (n < 0)
	{
		u_nbr = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = u_nbr % 10 + '0';
	while (u_nbr /= 10)
		str[--len] = u_nbr % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

char					*ft_filename(char *path)
{
	char	*found;

	found = ft_strrchr(path, '/');
	if (!found)
		return (ft_strdup(path));
	else
		return (ft_strdup(found));
	return (NULL);
}
