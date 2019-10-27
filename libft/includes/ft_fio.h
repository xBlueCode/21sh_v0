/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:12:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:12:18 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIO_H
# define FT_FIO_H

# include <unistd.h>
# include "ft_dstr.h"

# define FT_READ_BUFF_SIZE 128

# define FT_FILENAME_MAX 255
# define FT_PATHNAME_MAX 1023

int		ft_dup2(int fildes, int fildes2, int op);
int		ft_dup_stdioe_copy(int stdioe[3], int op);
int		ft_dup_stdioe_set(int stdioe[3], int op);
int		ft_stat_is(char *fname, int type);

t_dstr	*ft_read_file(char *filename);
t_dstr	*ft_read_fd(int fd);
int		ft_read_fd_in(int fd, t_dstr *dstr);

char	*ft_getcwd(void);

#endif
