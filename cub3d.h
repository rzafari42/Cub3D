/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:51:16 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/28 16:36:02 by marvin           ###   ########.fr       */
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
//# include <mlx.h>
# define mapWidth 24
# define mapHeight 24
# define textwidth 64
# define textheight 64

typedef struct s_save
{
    unsigned int size;
    unsigned int reservedid;
    unsigned int offset;
    unsigned int width;
    unsigned int height;
    unsigned int dibsizeheader;
    unsigned int dibmpwidth;
    unsigned int dibbmpheight;
    unsigned int dibcolorplanes;
    unsigned int dibbpp;
    unsigned char diboffset[24];

}               t_save;

typedef struct   s_parse
{
    unsigned long Fcolor;
    unsigned long Ccolor;
    unsigned int    red;
    unsigned int    blue;
    unsigned int    green;
    int Fcolorset;
    int Ccolorset;
    int resolutionset;
    int widthset;
    int heightset;
    int northset;
    int southset;
    int westset;
    int eastset;
    int spriteset;
    int pathset;
    int directionset;
    int positionset;
    int mapnbline;
    int mapbiggerline;
    int numsprites;
    char *files;
    char *resolution;
    char *northtext;
    char *southtext;
    char *easttext;
    char *westtext;
    char *sprite;
    char *path;
    char position;
    int positionx;
    int positiony;
    char direction;
    char *Widthcatch;
    char *Heightcatch;
    char **map;
    int fd[5];
    int Width;
    int Height;
    int save;
}                t_parse;

typedef struct   s_speed
{
    double moveSpeed;
    double rotSpeed;
}                 t_speed;

typedef struct   s_color
{
    unsigned int r;
    unsigned int b;
    unsigned int g;
    unsigned int color;
    unsigned int ceilcolor;
    unsigned int floorcolor;
}                 t_color;

typedef struct   s_keymove
{
    int mode;
    int keyUp;
    int keyDown;
    int keyRight;
    int keyLeft;
    int keyTurnRight;
    int keyTurnLeft;
    int killwindow;
}                t_keymove;

typedef struct   s_raycastvar
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double oldDirX;
    double oldPlaneX;
    double sideDistX;
    double sideDistY;
    double cameraX;
    double rayDirX;
    double rayDirY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int mapX;
    int mapY;
}               t_raycastvar;

typedef struct  s_sprite
{
  void *img_spriteptr0;
  char *img_spritedata0;
  char *img_spritedata_utils;
  double  x;
  double  y;
  double  *Zbuffer;
  double  *spriteDistance;
  double  spriteX;
  double  spriteY;
  double  invert;
  double  transfomrX;
  double  transformY;
  int     size_line;
  int     bpp;
  int     endian;
  int     width;
  int     height;
  int     *spriteOrder;
  int     sprite_screen;
  int     spriteHeight;
  int     spriteWidth;
  int     drawStart_spriteY;
  int     drawEnd_spriteY;
  int     drawStart_spriteX;
  int     drawEnd_spriteX;
  int     stripe;
  int     stripeX;
  int     stripeY;
  int     sprites_tabset;
  int     spriteDistanceset;
  int     spriteOrderset;
  int     Zbufferset;
}               t_sprite;

typedef struct  s_texture
{
    void *img_textptr0;
    void *img_textptr1;
    void *img_textptr2;
    void *img_textptr3;
    char *img_textdata0;
    char *img_textdata1;
    char *img_textdata2;
    char *img_textdata3;
    char *img_textdata_utils;
    int size_line;
    int bpp;
    int endian;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int width;
    int height;
    double wallx;
    double texPos;
    double  step;
    int x;
    int y;
    unsigned int color;
}             t_texture;

typedef struct   s_deflibx
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int size_line;
    int bpp;
    int endian;
    t_raycastvar  raycast;
    t_keymove     move;
    t_color       color;
    t_speed       speed;
    t_texture     text;
    t_sprite      sprites;
    t_sprite      *sprites_tab;
    t_parse       parse;
    t_save        bmp;
}               t_deflibx;

unsigned long   convertrgbtoint(unsigned int r, unsigned int g, unsigned int b);
void    *ft_memcpy_cub(void *dst, const void *src, int n);
void    ft_sort_sprites(int *order, double *distance, int num);
void    ft_locate_sprites(t_deflibx *mlx);
void    ft_order_sprites(t_deflibx *mlx);
void    ft_project_sprites(t_deflibx *mlx);
void    ft_normal_mode(t_deflibx *mlx);
void    ft_electro_mode(t_deflibx *mlx);
void    ft_DDA(t_deflibx *mlx);
void    ft_drawtexturedwall(t_deflibx *mlx, int x);
void    ft_draw_ceil(t_deflibx *mlx, int x);
void    ft_draw_floor(t_deflibx *mlx, int x);
void    ft_launch_text(t_deflibx *mlx);
void    ft_destroy_text(t_deflibx *mlx);
void    ft_launch_sprites(t_deflibx *mlx);
void    ft_destroy_sprites(t_deflibx *mlx);
void    color_initializatin(t_deflibx *mlx);
void    move_up(t_deflibx *mlx);
void    move_down(t_deflibx *mlx);
void    move_right(t_deflibx *mlx);
void    move_left(t_deflibx *mlx);
void    turn_right(t_deflibx *mlx);
void    turn_left(t_deflibx *mlx);
void    north_south_initialization(t_deflibx *mlx);
void    east_west_initialization(t_deflibx *mlx);
void    move_initialization(t_deflibx *mlx);
void    window_initialization(t_deflibx *mlx);
void    position_initialization(t_deflibx *mlx);
void    initialization(t_deflibx *mlx);
void    ft_parse_initialization(t_deflibx *mlx);
void    ft_parse_arguments(t_deflibx *mlx, int argc, char **argv);
void    ft_free(t_deflibx *mlx);
void    ft_free_map(t_deflibx *mlx);
void    ft_free_malloc(t_deflibx *mlx);
void    ft_line_map(t_deflibx *mlx);
void    ft_copy_map(t_deflibx *mlx);
void    ft_copy_maptwo(t_deflibx *mlx, int fd, char *line);
void    *ft_calloc_cub(size_t count, size_t size);
void    ft_check_firstandlast_line(t_deflibx *mlx, char *s);
void    ft_catch_positionandnumsprites(t_deflibx *mlx);
void	ft_check_color(t_deflibx *mlx);
void	ft_savebmp(t_deflibx *mlx);
void    ft_linesize(char *line, t_deflibx *mlx);
void	ft_bmpinit(t_deflibx *mlx);
void	ft_savebmpheader(t_deflibx *mlx, int fd);
void	ft_savedibheader(t_deflibx *mlx, int fd);
void    ft_savepixelarray(t_deflibx *mlx, int fd);
void	ft_return(char *s, t_deflibx *mlx);
void    ft_spritesheight(t_deflibx *mlx);
void    ft_spriteswidth(t_deflibx *mlx);
void    ft_freesprites(t_deflibx *mlx);
void	keypresstwo(int key, t_deflibx *mlx);
void    ft_check_map(t_deflibx *mlx);
void    ft_check_maptwo(t_deflibx *mlx);
void    ft_cehck_mapthree(t_deflibx *mlx);
void    ft_cehck_mapfour(t_deflibx *mlx);
void    ft_getheight_from_resolution(t_deflibx *mlx);
void    ft_getwidth_from_resolution(t_deflibx *mlx);
void    ft_transform_res_in_int(t_deflibx *mlx);
void    ft_get_texturespath_two(char *line, int i, t_deflibx *mlx);
void    ft_fillspace(t_deflibx *mlx);
void    ft_openpath(t_deflibx *mlx);
void    raycastingprojectcalcul(t_deflibx *mlx);
void    raycastingsprites(t_deflibx *mlx);
void    raycastingtextures(t_deflibx *mlx, int x);
void    raycastingrayandstepcalcul(t_deflibx *mlx, int x);
int     ft_get_texturespath(char *line, int i, t_deflibx *mlx);
int     keypress(int key, t_deflibx *mlx);
int     keyrelease(int key, t_deflibx *mlx);
int     killwindow(t_deflibx *mlx);
int     key_deal(t_deflibx *mlx);
int     ft_check_wall(char *s);
int     ft_get_color(char *line, int i, char c, t_deflibx *mlx);
int     ft_check_if_space(t_deflibx *mlx);
int     ft_line_to_resolution(char *line, int i, t_deflibx *mlx);
int     ft_get_resolution(char *line, int i, t_deflibx *mlx);
int     ft_get_typecolor(char *line, int i, t_deflibx *mlx);
int     raycasting(t_deflibx *mlx);
int     ft_atoi_cub(const char *str);
int     ft_parsing(t_deflibx *mlx);
int     ft_check_args(char *line, t_deflibx *mlx);
int     ft_strncmp_cub(const char *s1, const char *s2, size_t n);
char	*ft_strdup_cub(const char *s1);
//int     main(int argc, char **argv);
size_t	ft_strlen_cub(const char *s);
void	ft_putstr_cub(char *s);
int     ft_isdigit_cub(int c);
void    ft_bzero_cub(void *s, size_t n);
char	*ft_strdup_zero(const char *s1, t_deflibx *mlx);

#endif
