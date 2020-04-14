/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:51:16 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/14 21:20:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx.h"
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
# define screenWidth 640 
# define screenHeight 480
# define mapWidth 24
# define mapHeight 24
# define textwidth 64
# define textheight 64
# define numsprites 2
# define N 0
# define S 1
# define W 0
# define E 0


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
    char *files;
    char *resolution;
    char *northtext;
    char *southtext;
    char *easttext;
    char *westtext;
    char *sprite;
    char *path;
    char position;
    char direction;
    char *Widthcatch;
    char *Heightcatch;
    char **map;
    int Width;
    int Height;
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
    int killWindow;
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
  void *img_spriteptr1;
  void *img_spriteptr2;
  void *img_spriteptr3;
  char *img_spritedata0;
  char *img_spritedata1;
  char *img_spritedata2;
  char *img_spritedata3;
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
}               t_deflibx;

unsigned long   convertrgbtoint(unsigned int r, unsigned int g, unsigned int b);
void    *ft_memcpy(void *dst, const void *src, int n);
void    ft_sort_sprites(int *Order, double *Distance, int num);
void    ft_locate_sprites(t_deflibx *mlx);
void    ft_Order_sprites(t_deflibx *mlx);
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
void    Color_initializatin(t_deflibx *mlx);
void    move_up(t_deflibx *mlx);
void    move_down(t_deflibx *mlx);
void    move_right(t_deflibx *mlx);
void    move_left(t_deflibx *mlx);
void    turn_right(t_deflibx *mlx);
void    turn_left(t_deflibx *mlx);
void    North_South_initialization(t_deflibx *mlx);
void    East_West_initialization(t_deflibx *mlx);
void    Move_initialization(t_deflibx *mlx);
void    Window_initialization(t_deflibx *mlx);
void    position_initialization(t_deflibx *mlx);
void    initialization(t_deflibx *mlx);
void    ft_parse_initialization(t_deflibx *mlx);
void    ft_free(t_deflibx *mlx);
void    ft_free_map(t_deflibx *mlx);
void    ft_free_malloc(t_deflibx *mlx);
void    ft_line_map(t_deflibx *mlx);
void    ft_copy_map(t_deflibx *mlx);
void    *ft_calloc(size_t count, size_t size);
void    ft_check_firstandlast_line(t_deflibx *mlx, char *s);
void    ft_sprites_init(t_deflibx *mlx);
int     keyPress(int key, t_deflibx *mlx);
int     keyRelease(int key, t_deflibx *mlx);
int     KillWindow(t_deflibx *mlx);
int     key_deal(t_deflibx *mlx);
int     ft_check_wall(char *s);
int     raycasting(t_deflibx *mlx);
int     ft_atoi(const char *str);
int     ft_parsing(t_deflibx *mlx);
//int     main(int argc, char **argv);
size_t	ft_strlen(const char *s);
int     ft_isdigit(int c);
void    ft_bzero(void *s, size_t n);
char	*ft_strdup_zero(const char *s1, t_deflibx *mlx);

#endif