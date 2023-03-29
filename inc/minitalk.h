/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:13 by nimai             #+#    #+#             */
/*   Updated: 2023/03/29 08:10:42 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
//ato de kesu
#include <stdio.h>
//






typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			center_x;
	int			center_y;
	int			width;
	int			height;
	double		scale;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
}	t_vars;

typedef struct s_nmbs
{
//	long	value;
	char	*colour;
/* 	int		rgb(R, G, B);
	int		r;
	int		g;
	int		b; */
	int		x;
	int		y;
	int		z;
	int		x_mod;
	int		y_mod;
}	t_nmbs;

typedef struct s_line
{
	void			*content;
	struct s_line	*next;
//	long			id_row[1024];
//	long			id_column[1024];
}	t_line;

typedef struct s_pipex
{
	int	count;
	int	value;
	int	fd_out;
	int	fd_in;
/* 	void			*content;
	struct s_line	*row;//kore de ii ki ga suru no se // kesu kamo
//	struct s_line	*column[ARGLIMIT];
    int				row_len;//length of the first row
//	long			clm_len;
//	t_nmbs			n[ARGLIMIT][ARGLIMIT];
	int				column;
	char			**strs;
	int				is_first;
	int				height;
	int				width;
	int				w_cell; */
}	t_pipex;

typedef struct s_map
{
	t_vars	vars;
	t_data	data;
}	t_map;

//functions
void	check_argument(int ac, char **av);
void	read_file(int fd);

#endif
