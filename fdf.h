/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssallami <ssallami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:00:32 by ssallami          #+#    #+#             */
/*   Updated: 2025/04/07 11:03:08 by ssallami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// get_next_line
# define BUFFER_SIZE 32
# define FD_MAX 8192

# include "minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// mlx
# define WIDTH 1920
# define HEIGHT 1080

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 53

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			reverse;
}				t_point;

typedef struct s_map
{
	int			height;
	int			width;
	int			***array;
	int			z_max;
	int			z_min;
}				t_map;

typedef struct s_camera
{
	int			zoom;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	float		z_height;
	int			x_offset;
	int			y_offset;
	int			iso;
}				t_camera;

typedef struct s_mouse
{
	int			button;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}				t_fdf;

void			ft_check_valid(char *filename, t_map *map);
void			ft_draw(t_map *map, t_fdf *env);
void			ft_put_pixel(t_fdf *env, int x, int y, int color);
void			ft_draw_line(t_point s, t_point e, t_fdf *env);
t_point			project(int x, int y, t_fdf *env);
int				ft_min(int a, int b);
int				get_default_color(int z, t_map *map);
void			ft_putendl_fd(const char *err_msg, int system_function);
double			ft_reset_angles(double angle);

// Xiaolin Wu line algorithm utils
float			ft_abs(float n);
int				ft_ipart(float n);
float			ft_fpart(float n);
float			ft_rfpart(float n);
void			ft_return_error(const char *err_msg, int system_function);

// Controls
void			ft_hook_controls(t_fdf *env);
int				ft_key_press(int keycode, void *params);
int				ft_mouse_down(int button, int x, int y, void *params);
int				ft_close_win(void *params);

// get_next_line
int				get_next_line(int fd, char **line);

// libft
char			*ft_strjoin(const char *s1, const char *s2);
void			ft_bzero(void *s, size_t n);
char			**ft_split(const char *s, char c);
int				ft_atoi(const char *nptr);
void			ft_putendl_fd(const char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar_fd(char c, int fd);
unsigned int	ft_atoi_base(const char *str, const char *base);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);

#endif