/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_collection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:08:02 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 16:10:08 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void sort_matrix(char **matrix)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[j])
		{
			if (ft_strcmp(matrix[i], matrix[j]) < 0)
			{
				temp = ft_strdup(matrix[i]);
				free(matrix[i]);
				matrix[i] = ft_strdup(matrix[j]);
				free(matrix[j]);
				matrix[j] = temp;
			}
			j++;
		}
		i++;
	}
}
