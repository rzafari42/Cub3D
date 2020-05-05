/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:51:16 by rzafari           #+#    #+#             */
/*   Updated: 2020/05/05 13:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# define TEXTWIDTH 64
# define TEXTHEIGHT 64

typedef struct	s_save
{
	unsigned short int	signature;
	unsigned int		size;
	unsigned int		reservedid;
	unsigned int		offset;
	int					fd;
}				t_save;

typedef struct	s_dibheader
{
	unsigned int		dibsizeheader;
	unsigned int		dibmpwidth;
	unsigned int		dibbmpheight;
	unsigned short int	dibcolorplanes;
	unsigned short int	dibbpp;
	unsigned char		diboffset[24];
}				t_dibheader;

typedef struct	s_parse
{
	unsigned long	fcolor;
	unsigned long	ccolor;
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	int				fcolorset;
	int				ccolorset;
	int				resolutionset;
	int				widthset;
	int				heightset;
	int				northset;
	int				southset;
	int				westset;
	int				eastset;
	int				spriteset;
	int				pathset;
	int				directionset;
	int				positionset;
	int				mapnbline;
	int				mapbiggerline;
	int				numsprites;
	char			*files;
	char			*resolution;
	char			*northtext;
	char			*southtext;
	char			*easttext;
	char			*westtext;
	char			*sprite;
	char			*path;
	char			position;
	int				positionx;
	int				positiony;
	char			direction;
	char			*widthcatch;
	char			*heightcatch;
	char			**map;
	int				fd[5];
	int				width;
	int				height;
	int				save;
}				t_parse;

typedef struct	s_speed
{
	double	movespeed;
	double	rotspeed;
}				t_speed;

typedef struct	s_color
{
	unsigned int	r;
	unsigned int	b;
	unsigned int	g;
	unsigned int	color;
	unsigned int	ceilcolor;
	unsigned int	effectccolor;
	unsigned int	floorcolor;
	unsigned int	effectfcolor;
}				t_color;

typedef struct	s_keymove
{
	int	mode;
	int	keyup;
	int	keydown;
	int	keyright;
	int	keyleft;
	int	keyturnright;
	int	keyturnleft;
	int	killwindow;
}				t_keymove;

typedef struct	s_raycastvar
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	olddirx;
	double	oldplanex;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		mapx;
	int		mapy;
	int		help;
}				t_raycastvar;

typedef struct	s_sprite
{
	void	*img_spriteptr0;
	char	*img_spritedata0;
	char	*img_spritedata_utils;
	double	x;
	double	y;
	double	*zbuffer;
	double	*spritedistance;
	double	spritex;
	double	spritey;
	double	invert;
	double	transformx;
	double	transformy;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
	int		*spriteorder;
	int		sprite_screen;
	int		spriteheight;
	int		spritewidth;
	int		drawstart_spritey;
	int		drawend_spritey;
	int		drawstart_spritex;
	int		drawend_spritex;
	int		stripe;
	int		stripex;
	int		stripey;
	int		sprites_tabset;
	int		spritedistanceset;
	int		spriteorderset;
	int		zbufferset;
}				t_sprite;

typedef struct	s_texture
{
	void			*img_textptr0;
	void			*img_textptr1;
	void			*img_textptr2;
	void			*img_textptr3;
	char			*img_textdata0;
	char			*img_textdata1;
	char			*img_textdata2;
	char			*img_textdata3;
	char			*img_textdata_utils;
	int				size_line;
	int				bpp;
	int				endian;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				width;
	int				height;
	int				x;
	int				y;
	double			wallx;
	double			step;
	unsigned int	color;
}				t_texture;

typedef struct	s_deflibx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
	t_raycastvar	raycast;
	t_keymove		move;
	t_color			color;
	t_speed			speed;
	t_texture		text;
	t_sprite		sprites;
	t_sprite		*sprites_tab;
	t_parse			parse;
	t_save			bmp;
	t_dibheader		bmpdib;
}				t_deflibx;

unsigned long	convertrgbtoint(unsigned int r, unsigned int g, unsigned int b);
void			*ft_memcpy_cub(void *dst, const void *src, int n);
void			ft_sort_sprites(t_deflibx *mlx);
void			ft_locate_sprites(t_deflibx *mlx);
void			ft_order_sprites(t_deflibx *mlx);
void			ft_project_sprites(t_deflibx *mlx);
void			ft_project_spritestwo(t_deflibx *mlx);
void			ft_project_spritesthree(t_deflibx *mlx, int y);
void			ft_normal_mode(t_deflibx *mlx);
void			ft_electro_mode(t_deflibx *mlx);
void			ft_dda(t_deflibx *mlx);
void			ft_drawtexturedwall(t_deflibx *mlx, int x);
void			ft_draw_ceil(t_deflibx *mlx, int x);
void			ft_draw_floor(t_deflibx *mlx, int x);
void			ft_launch_text(t_deflibx *mlx);
void			ft_destroy_textandsprites(t_deflibx *mlx);
void			ft_launch_sprites(t_deflibx *mlx);
void			color_initializatin(t_deflibx *mlx);
void			move_up(t_deflibx *mlx);
void			move_down(t_deflibx *mlx);
void			move_right(t_deflibx *mlx);
void			move_left(t_deflibx *mlx);
void			turn_right(t_deflibx *mlx);
void			turn_left(t_deflibx *mlx);
void			north_south_initialization(t_deflibx *mlx);
void			east_west_initialization(t_deflibx *mlx);
void			move_initialization(t_deflibx *mlx);
void			window_initialization(t_deflibx *mlx);
void			position_initialization(t_deflibx *mlx);
void			initialization(t_deflibx *mlx);
void			ft_parse_initialization(t_deflibx *mlx);
void			ft_parse_arguments(t_deflibx *mlx, int argc, char **argv);
void			ft_free(t_deflibx *mlx);
void			ft_free_map(t_deflibx *mlx);
void			ft_free_malloc(t_deflibx *mlx);
void			ft_line_map(t_deflibx *mlx);
void			ft_copy_map(t_deflibx *mlx);
void			ft_copy_maptwo(t_deflibx *mlx, int fd, char *line);
void			*ft_calloc_cub(size_t count, size_t size);
void			ft_check_firstandlast_line(t_deflibx *mlx, char *s);
void			ft_catch_positionandnumsprites(t_deflibx *mlx);
void			ft_catch_positionandnumspritestwo(t_deflibx *mlx, int i, int j);
void			ft_check_color(t_deflibx *mlx);
void			ft_savebmp(t_deflibx *mlx);
void			ft_linesize(char *line, t_deflibx *mlx);
void			ft_bmpinit(t_deflibx *mlx);
void			ft_savebmpheader(t_deflibx *mlx);
void			ft_savepixelarray(t_deflibx *mlx);
void			ft_return(char *s, t_deflibx *mlx);
void			ft_spritesheight(t_deflibx *mlx);
void			ft_spriteswidth(t_deflibx *mlx);
void			ft_freesprites(t_deflibx *mlx);
void			keypresstwo(int key, t_deflibx *mlx);
void			ft_check_map(t_deflibx *mlx);
void			ft_getheight_from_resolution(t_deflibx *mlx);
void			ft_getwidth_from_resolution(t_deflibx *mlx);
void			ft_transform_res_in_int(t_deflibx *mlx);
void			ft_get_texturespath_two(char *line, int i, t_deflibx *mlx);
void			ft_fillspace(t_deflibx *mlx);
void			ft_openpath(t_deflibx *mlx);
void			raycastingprojectcalcul(t_deflibx *mlx);
int				raycastingsprites(t_deflibx *mlx, int x);
void			raycastingtextures(t_deflibx *mlx, int x);
void			raycastingrayandstepcalcul(t_deflibx *mlx, int x);
void			ft_helpingbox(t_deflibx *mlx);
int				ft_get_texturespath(char *line, int i, t_deflibx *mlx);
int				keypress(int key, t_deflibx *mlx);
int				keyrelease(int key, t_deflibx *mlx);
int				killwindow(t_deflibx *mlx);
int				key_deal(t_deflibx *mlx);
int				ft_check_wall(char *s);
int				ft_get_color(char *line, int i, char c, t_deflibx *mlx);
int				ft_check_if_space(t_deflibx *mlx);
int				ft_line_to_resolution(char *line, int i, int j, t_deflibx *mlx);
int				ft_get_resolution(char *line, int i, t_deflibx *mlx);
int				ft_get_typecolor(char *line, int i, t_deflibx *mlx);
int				raycasting(t_deflibx *mlx);
int				ft_atoi_cub(const char *str);
int				ft_parsing(t_deflibx *mlx);
int				ft_check_args(char *line, t_deflibx *mlx);
int				ft_strncmp_cub(const char *s1, const char *s2, size_t n);
int				ft_checkspaces(t_deflibx *mlx, int x, int y);
int				ft_checkspacesnext(t_deflibx *mlx, int x, int y);
int				ft_checkcase(t_deflibx *mlx, int x, int y);
int				ft_checkupanddown(t_deflibx *mlx, int x, int y);
int				ft_checksides(t_deflibx *mlx, int x, int y);
char			*ft_strdup_cub(const char *s1);
size_t			ft_strlen_cub(const char *s);
void			ft_putstr_cub(char *s);
int				ft_isdigit_cub(int c);
void			ft_bzero_cub(void *s, size_t n);
char			*ft_strdup_zero(const char *s1, t_deflibx *mlx);

#endif
