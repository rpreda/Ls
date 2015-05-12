/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpreda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:02:43 by rpreda            #+#    #+#             */
/*   Updated: 2014/11/28 17:25:22 by rpreda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include "libft.h"

typedef struct		s_infos
{
	char			*path;
	char			*filename;
	char			*acces;
	char			*links;
	char			*usrname;
	char			*usrgrp;
	char			*bytesize;
	char			*date_formated;
	time_t			epoch_time;
	u_long			blksize;
}					t_infos;

typedef struct		s_lens
{
	size_t			filename_len;
	size_t			links_len;
	size_t			username_len;
	size_t			usrgrp_len;
	size_t			bytesize_len;
}					t_len;

typedef struct		s_pque
{
	void			*content;
	size_t			content_size;
	int				content_type;
	t_infos			*infos;
	struct s_pque	*next;
}					t_lista;

t_infos				*build_data(struct stat *s_stat, char *usr, char *grp,
		char *path);
t_infos				*grab_infos(char *path);
void				ft_the_while(char *a, mode_t m, int i);
char				*ft_itoa_long(long long n);
char				*ft_filename(char *path);

char				*ft_build_acces(mode_t mode);
char				type_helper(mode_t mode);

char				**interpret_args(int argc, char **argv);
void				sort_matrix(char **matrix);

char				*ft_memconcat(char *s1, char *s2);
void				ft_new_r(t_lista **n, t_lista **list, t_lista **first,
				struct dirent *dp);
void				ft_new(t_lista **n, t_lista **list, t_lista **first,
				struct dirent *dp);
void				ft_the_if(t_lista **list, t_lista **aux, t_lista **n);
void				lst_add(t_lista **list, struct dirent *dp);
t_len				*ft_build_print_data(t_lista *lst, char *path);
void				ft_add_spaces(size_t max_len, char **string);
char				*assemble_string(t_lista *elem, t_len *lens);
int					ft_add_blocksize(t_lista *list, char hidden);
void				ft_print(t_lista *list, t_len *lens);
void				print_dir(DIR *directory, char *dir_path);
void				paths_now_what(char **paths, int put_dirnames);
void				ft_while_one(char **paths, struct stat *s_stat,
		DIR *directory, int put_dirnames);
void				if_in_the_while(char **paths, DIR *directory,
		int put_dirnames, int i);
#endif
