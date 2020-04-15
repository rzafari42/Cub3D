/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:03:44 by rzafari           #+#    #+#             */
/*   Updated: 2020/04/15 02:07:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void ft_return(char *s, t_deflibx *mlx)
{
    ft_putstr_cub("Error");
    ft_putstr_cub(s);
    ft_free(mlx);
    exit (0);
}

int ft_check_if_space(t_deflibx *mlx)
{
    int i;

    i = 0;
    while(mlx->parse.resolution[i] != '\0')
    {
        if (mlx->parse.resolution[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

/*/////////////////////////////////////////////////////////////////
                        R E S O L U T I O N
/////////////////////////////////////////////////////////////////*/
void ft_transform_res_in_int(t_deflibx *mlx)
{
    int s = 0;
    int h = 0;

    mlx->parse.Width = ft_atoi_cub(mlx->parse.Widthcatch);
    mlx->parse.Height = ft_atoi_cub(mlx->parse.Heightcatch);
    if (mlx->parse.Width < 640)
        mlx->parse.Width = 640;
    else if (mlx->parse.Width > 2560)
        mlx->parse.Width = 2560;
    if (mlx->parse.Height < 480)
        mlx->parse.Height = 480;
    else if (mlx->parse.Height > 1440)
        mlx->parse.Height = 1440;
}

int    ft_line_to_resolution(char *line, int i, t_deflibx *mlx)
{
    int c;
    int j;
    int nspace;

    c = 0;
    nspace = 0; 
    while (!(ft_isdigit_cub(line[i])))
        i++;
    j = ft_strlen_cub(line) - i;
    if (!(mlx->parse.resolution = (char *)malloc(sizeof(char) * (j + 1))))
        ft_return("MALLOC ERROR :(", mlx);
    mlx->parse.resolutionset = 1;
    while (c < j)
    {
        if (!(ft_isdigit_cub(line[i])) && line[i] != '\0' && line[i] != ' ')
            ft_return("Resolution Error: NOT A DIGIT", mlx);
        nspace = (line[i] == ' ') ? (++nspace) : nspace;
        if (nspace > 1)
            ft_return("Invalid resolution: format", mlx);
        else
            mlx->parse.resolution[c++] = line[i++];
    }
    mlx->parse.resolution[c] = '\0';
    if ((c = ft_strlen_cub(mlx->parse.resolution)) > 9 || c < 7)
        ft_return("Resolution Error: TOO BIG or TOO SMALL", mlx);
    return (i);
}

void    ft_getwidth_from_resolution(t_deflibx *mlx)
{
    int j;
    int c;

    j = 0;
    c = 0;
    while(mlx->parse.resolution[j] != ' ')
        j++;
    if (!(mlx->parse.Widthcatch = (char *)malloc(sizeof(char) * (j + 1))))
        ft_return("MALLOC ERROR :(", mlx);
    mlx->parse.widthset = 1;
    j = 0;
    while(mlx->parse.resolution[j] != ' ')
    {   
        mlx->parse.Widthcatch[j] = mlx->parse.resolution[j];
        j++;
    }
    mlx->parse.Widthcatch[j] = '\0';
}

void    ft_getheight_from_resolution(t_deflibx *mlx)
{
    int j;
    int c;
    int l;

    j = 0;
    while(mlx->parse.resolution[j] != ' ')
        j++;
    j++;
    l = 0;
    c = j;
    while (mlx->parse.resolution[j] != '\0')
    {
        l++;
        j++;
    }
    if (!(mlx->parse.Heightcatch = (char *)malloc(sizeof(char) * (l + 1))))
        ft_return("MALLOC ERROR :(", mlx); 
    mlx->parse.heightset = 1;
    l = 0;
    while (mlx->parse.resolution[c] != '\0')
        mlx->parse.Heightcatch[l++] = mlx->parse.resolution[c++];
    mlx->parse.Heightcatch[l] = '\0';
}

int    ft_get_Resolution(char *line, int i, t_deflibx *mlx)
{
    i = ft_line_to_resolution(line, i, mlx);
    if (!ft_check_if_space(mlx))
        ft_return("Resolution Error: syntax error", mlx);
    ft_getwidth_from_resolution(mlx);
    ft_getheight_from_resolution(mlx);
    ft_transform_res_in_int(mlx);
    return (i);
}

/*/////////////////////////////////////////////////////////////////
                        C O L O R
/////////////////////////////////////////////////////////////////*/

void    ft_check_Color(t_deflibx *mlx)
{
    if (mlx->parse.red > 255 || mlx->parse.blue > 255 || mlx->parse.green > 255)
        ft_return("Color is over than 255", mlx);
}

int ft_get_Color(char *line, int i, char c, t_deflibx *mlx)
{
    int d;
    char res[4];

    d = 0;
    ft_bzero_cub(res, 4);
    while(line[i] != ',' && line[i] != '\0')
    {
        if (d >= 3)
            ft_return("Color is invalid", mlx);
        if (line[i] == ' ')
            ft_return("Space in the color declaration", mlx);
        if (ft_isdigit_cub(line[i]))
            res[d++] = line[i++];
        else
            ft_return("Color Invalid: not a digit", mlx);
    }
    if (c == 'r')
        mlx->parse.red = ft_atoi_cub(res);
    if (c == 'g')
        mlx->parse.green = ft_atoi_cub(res);
    if (c == 'b')
        mlx->parse.blue = ft_atoi_cub(res);
    ft_check_Color(mlx);
    return (i);
}

int    ft_get_floor_color(char *line, int i, t_deflibx *mlx)
{
    while (!(ft_isdigit_cub(line[i])))
        i++;
    i = ft_get_Color(line, i, 'r', mlx);
    i++;
    i = ft_get_Color(line, i, 'g', mlx);
    i++;
    i = ft_get_Color(line, i, 'b', mlx);
    mlx->color.floorcolor = convertrgbtoint(mlx->parse.red, mlx->parse.green, mlx->parse.blue);
    return (i);
} 

int    ft_get_ceil_color(char *line, int i, t_deflibx *mlx)
{
    while (!(ft_isdigit_cub(line[i])))
        i++;
    i = ft_get_Color(line, i, 'r', mlx);
    i++;
    i = ft_get_Color(line, i, 'g', mlx);
    i++;
    i = ft_get_Color(line, i, 'b', mlx);
    mlx->color.ceilcolor = convertrgbtoint(mlx->parse.red, mlx->parse.green, mlx->parse.blue);
    return (i);
}

int    ft_get_typecolor(char *line, int i, t_deflibx *mlx)
{
    mlx->parse.blue = 0;
    mlx->parse.green = 0;
    mlx->parse.red = 0;
    if (line[i] == 'F')
    {
        i = ft_get_floor_color(line, i, mlx);
        mlx->parse.Fcolorset = 1;
    }
    else if (line[i] == 'C')
    {
        i = ft_get_ceil_color(line, i, mlx);
        mlx->parse.Ccolorset = 1;
    }
    return (i);
}

void    ft_set_path_to_one(char *line, int i, t_deflibx *mlx)
{
    if (line[i] == 'N' && line[i + 1] == 'O')
        mlx->parse.northset = 1;
    if (line[i] == 'S' && line[i + 1] == 'O')
        mlx->parse.southset = 1;
    if (line[i] == 'W' && line[i + 1] == 'E')
        mlx->parse.westset = 1;
    if (line[i] == 'E' && line[i + 1] == 'A')
        mlx->parse.eastset = 1;
    if (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O')
        mlx->parse.spriteset = 1;
}

int     ft_check_path_set(char *line, int i, t_deflibx *mlx)
{
        if ((line[i] == 'N' && line[i + 1] == 'O' && mlx->parse.northset == 1)
        || (line[i] == 'S' && line[i + 1] == 'O' && mlx->parse.southset == 1)
        || (line[i] == 'W' && line[i + 1] == 'E' && mlx->parse.westset == 1)
        || (line[i] == 'E' && line[i + 1] == 'A' && mlx->parse.eastset == 1)
        || (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O' && mlx->parse.spriteset == 1))
            return (1);
        else
            return (0);
}

void    ft_put_to_right_path(char *line, int i, t_deflibx *mlx)
{
    if (line[i] == 'N' && line[i + 1] == 'O')
        mlx->parse.northtext = ft_strdup_cub(mlx->parse.path);
    if (line[i] == 'S' && line[i + 1] == 'O')
         mlx->parse.southtext = ft_strdup_cub(mlx->parse.path);
    if (line[i] == 'W' && line[i + 1] == 'E')
         mlx->parse.westtext = ft_strdup_cub(mlx->parse.path);
    if (line[i] == 'E' && line[i + 1] == 'A')
         mlx->parse.easttext = ft_strdup_cub(mlx->parse.path);
    if (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O')
         mlx->parse.sprite = ft_strdup_cub(mlx->parse.path);
}

void   ft_get_Texturespath_two(char *line, int i, t_deflibx *mlx)
{
    int j;
    int z;
    int l;

    j = 0;
    z = 0;
    while (line[i] != '.')
        i++;
    if (line[i] == '.')
    {
        l = i;
        while (line[l] != '\0')
        {
            j++;
            l++;
        }
        if (!(mlx->parse.path = (char*)malloc(sizeof(char) * (j + 3))))
            ft_return("MALLOC ERROR :(", mlx);
        mlx->parse.path[z++] = '"';
        while (z < j + 1)
            mlx->parse.path[z++] = line[i++];
        mlx->parse.path[z++] = '"';
        mlx->parse.path[z] = '\0';
    }
}

int    ft_get_Texturespath(char *line, int i, t_deflibx *mlx)
{
    int ret;

    if(ft_check_path_set(line, i, mlx) == 1)
    {
        while (line[i] != '\0')
            i++;
        return(i);
    }
    ft_set_path_to_one(line, i, mlx);
    ret = i;
    ft_get_Texturespath_two(line, i, mlx);
    ft_put_to_right_path(line, ret, mlx);
    free(mlx->parse.path);
   return (i);
}

int ft_check_args(char *line, t_deflibx *mlx)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if ((line[i] == 'N' && line[i + 1] == 'O')
        || (line[i] == 'S' && line[i + 1] == 'O')
        || (line[i] == 'W' && line[i + 1] == 'E')
        || (line[i] == 'E' && line[i + 1] == 'A')
        || (line[i] == 'S' && line[i + 1] == ' ' && line[i + 1] != 'O'))  
            i = ft_get_Texturespath(line, i, mlx);     
        else if ((line[i] == 'F' && mlx->parse.Fcolorset == 0) || (line[i] == 'C' && mlx->parse.Ccolorset == 0))
            i = ft_get_typecolor(line, i, mlx);
        else if (line[i] == 'R' && mlx->parse.resolutionset == 0)
            i = ft_get_Resolution(line, i, mlx);
        else if (ft_isdigit_cub(line[i]))
            return (2);
        else
            i++;
    }
    return (1);
}


int     ft_check_wall(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] == ' ')
        i++;
    if (s[i] == '1')
        return (1);
    return(0);
}

void ft_linesize(char *line, int linesize, t_deflibx *mlx)
{
    int j;
    j = 0;
    if (line[0] != '\0')
    { 
        printf("lineee = %s\n", line);
        while(line[j] != '\0')
        {   
            if (line[0] != ' ' && line[0] != '1')
                ft_return("Error in Map declaration", mlx);
            if (j != 0)
            {
                if (line[j] != ' ' && line[j] != '0' && line[j] != '1' && line[j] != '2' && line[j] != 'N'
                && line[j] != 'S' && line[j] != 'E' && line[j] != 'W')
                    ft_return("Error in Map declaration", mlx);
            }
            j++;
        }
        if (j > linesize)
            linesize = j;
        if (linesize > mlx->parse.mapbiggerline)
            mlx->parse.mapbiggerline = linesize; 
        mlx->parse.mapnbline++;
    }
}

void    ft_line_map(t_deflibx *mlx)
{
    int i;
    int j;
    int linesize;
    int ret;
    int fd;
    char *line;

    i = 1;
    mlx->parse.mapnbline = 0;
    //linesize = 0;
    ret = 0;
    if (!(line = (char*)malloc(sizeof(char))))
        ft_return("MALLOC ERROR :(", mlx);
    line[0] = 1;
    if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
    {
        free(line);
        ft_return("fd error in ft_line_map", mlx);
    }
    while (!ft_check_wall(line))
    {
        free(line);
        ret = get_next_line(fd, &line);
    }
    ft_linesize(line, linesize, mlx);
    free(line);
    while ((ret = get_next_line(fd, &line)) > -1)
    {
        ft_linesize(line, linesize, mlx);
        free(line);
        if (ret == 0) 
            break;
    }
    close(fd);
}

char	*ft_strdup_zero(const char *s1, t_deflibx *mlx)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;

	if (!(s2 = (char*)malloc(sizeof(char) * (mlx->parse.mapbiggerline + 1))))
		ft_return ("MALLOC ERROR :(", mlx);
	while (s1[j] != '\0')
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
    while (j <= mlx->parse.mapbiggerline)
        s2[j++] = '\0';
	return (s2);
}

void    ft_free_map(t_deflibx *mlx)
{
    int i;

    i = 0;
    while(i <= mlx->parse.mapnbline)
    {
        free(mlx->parse.map[i]);
        i++;
    }
    free(mlx->parse.map);
}

void ft_copy_map(t_deflibx *mlx)
{
    int ret;
    int fd;
    int i;
    int j;
    char *line;
    char *temp;

    ret = 0;
    i = 0;
    temp = NULL;
    if (!(line = (char*)malloc(sizeof(char))))
    {
        ft_free_map(mlx);
        ft_return("MALLOC ERROR :(", mlx);
    }
    line[0] = 1;
    if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
    {
        free(line);
        ft_free_map(mlx);
        ft_return("fd error in ft_copy_map", mlx);
    }
    while (!ft_check_wall(line))
    {
        free(line);
        ret = get_next_line(fd, &line);
        printf("line = %s\n", line);
    }
    temp = mlx->parse.map[i];
    mlx->parse.map[i] = ft_strdup_zero(line, mlx);
    free(temp);
    i++;
    printf("\n");
    printf("line = %s\n", line);
    free(line);
    while ((ret = get_next_line(fd, &line)) > -1)
    {
        printf("line = %s\n", line);
        if (line[0] != '\0')
        {
            temp = mlx->parse.map[i];
            mlx->parse.map[i] = ft_strdup_zero(line, mlx);
            free (temp);
            i++;
        }
        free(line);
        if (ret == 0)
            break;
    }
    i = 0;
    while(i <= mlx->parse.mapnbline)
    {
        printf("map %.2d  = %s\n", i, mlx->parse.map[i]);
        i++;
    }
    close(fd);
}

void ft_check_firstandlast_line(t_deflibx *mlx, char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        while (s[i] != '1' && s[i] != '\0')
        {
            if (s[i] != ' ')
            {
                printf("error is |%s|%c|%d\n", s,s[i], i);
                ft_free_map(mlx);
                ft_return("Map not closed: first line or last", mlx);
            }
            i++;
        }
        i++;
    }    
}

void ft_check_line(t_deflibx *mlx, int i, int j)
{
    int z;

    while (mlx->parse.map[i][j] != '\0')
    {
        z = 0;
        if (mlx->parse.map[i][j] == ' ' || mlx->parse.map[i][j] == '0')
        {
            z = i - 1;
            while (z > 0)
            {
                if (mlx->parse.map[z][j] == '1')
                    break;
                z--;
            }
            if (mlx->parse.map[z][j] != '1')
            {
                printf("line = %d error at [%d][%d]\n", i, z, j);
                ft_return("Map not closed for sure1", mlx);
                ft_free_map(mlx);                 
            }
            z = i + 1;
            while (z < mlx->parse.mapnbline)
            {
                if (mlx->parse.map[z][j] == '1')
                    break;
                z++;
            }
            if (z == mlx->parse.mapnbline)
                z = mlx->parse.mapnbline - 1;
            if (mlx->parse.map[z][j] != '1')
            {
                printf("line = %d error at [%d][%d]\n", i, z, j);
                ft_return("Map not closed for sure2", mlx);
                ft_free_map(mlx);                 
            }
        } 
        j++;
    }
    
    while (mlx->parse.map[i][j] != '\0'  )
    {
        if (mlx->parse.map[i][j] == '0' || mlx->parse.map[i][j] == ' ')
        {
            z = 1;
            while (mlx->parse.map[z][j] != '1')
                z++;
            if (mlx->parse.map[z][j] != '1')
            {
                printf("linefalse = %s i = %d j = %d z = %d\n", mlx->parse.map[i], i ,j, z);
                ft_return("Map not closed for sure1", mlx);
                ft_free_map(mlx); 
            }
            z = i + 1;
            printf("z = %d\n",z);
            while (mlx->parse.map[z][j] != '1' && z < mlx->parse.mapnbline - 2)
                z++;
            if (mlx->parse.map[z][j] == '\0' || mlx->parse.map[z][j] != '1')
            {
                printf("linefalse = %s i=%d j = %d z = %d\n", mlx->parse.map[i],i, j, z);
                ft_return("Map not closed for sure", mlx);
                ft_free_map(mlx);
            }
        }   
        j++;
    }
}

void ft_fillfirstandlast_line(t_deflibx *mlx)
{
    int i;
    int j;
    int n;

    i = 0;
    while(mlx->parse.map[0][i] != '\0')
    {
        if (mlx->parse.map[0][i] == ' ')
        {
            j = 1;
            printf("firstline =%s \n",mlx->parse.map[0]);
            while(j < mlx->parse.mapnbline - 1)
            {
                if (mlx->parse.map[j][i] == '1')
                {
                    n = 0;
                    while (mlx->parse.map[0][n] != '\0')
                    {
                        mlx->parse.map[0][n] = '1';
                        n++;
                    }
                }
                j++;
            }
        }
        i++;
    }
    printf("firstline =%s \n",mlx->parse.map[0]);
    i = 0;
    printf("lastline =%s \n",mlx->parse.map[mlx->parse.mapnbline - 1]);
    while(mlx->parse.map[mlx->parse.mapnbline - 1][i] != '\0')
    {
        if (mlx->parse.map[mlx->parse.mapnbline - 1][i] == ' ')
        {
            j = mlx->parse.mapnbline - 2;
            while(j > 0)
            {
                if (mlx->parse.map[j][i] == '1')
                {
                    n = 0;
                    while (mlx->parse.map[mlx->parse.mapnbline - 1][n] != '\0')
                    {
                        mlx->parse.map[mlx->parse.mapnbline - 1][n] = '1';
                        n++;
                    }
                }
                j--;
            }
        }
        i++;
    }
    printf("lastline =%s \n",mlx->parse.map[mlx->parse.mapnbline - 1]);
}

void    ft_check_map(t_deflibx *mlx)
{
    int i;
    int j;

    printf("first\n");
    ft_check_firstandlast_line(mlx, mlx->parse.map[0]);
    printf("Last\n");
    ft_check_firstandlast_line(mlx, mlx->parse.map[mlx->parse.mapnbline - 1]);
    //ft_fillfirstandlast_line(mlx);
    i = 0;
    while (i < mlx->parse.mapnbline - 1)
    {
        j = 0;
        while (mlx->parse.map[i][j] != '1' && mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] != ' ' && mlx->parse.map[i][j] != '\0')
            {
                ft_free_map(mlx);
                ft_return("Map not closed", mlx);
            }
            j++;
        }
        //printf("line %.2d 1 i at %d\n", i, j);
        //ft_check_line(mlx, i, j);
        i++;
    }
    i = 0;
    while (i < mlx->parse.mapnbline - 1)
    {
        j = mlx->parse.mapbiggerline - 1;
        while (mlx->parse.map[i][j] == '\0')
            j--;
        while (mlx->parse.map[i][j] != '1')// && mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] != ' ')
            {
                ft_free_map(mlx);
                ft_return("Map not closed", mlx);
            }
            j--;
        }
        //printf("line %.2d 1 i at %d\n", i, j);
        //ft_check_line(mlx, i, j);
        i++;
    }
    j = 0;
    while (j < mlx->parse.mapbiggerline)
    {
        i = 0;
        while (mlx->parse.map[i][j] != '1' && i < mlx->parse.mapnbline - 1 && mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] != ' ')
            {
                ft_free_map(mlx);
                ft_return("Map not closeds", mlx);
            }
            i++;
        }
        j++;
    }
    j = 0;
    while (j < mlx->parse.mapbiggerline)
    {
        i = mlx->parse.mapnbline - 1;
        while (mlx->parse.map[i][j] != '1' && i > 0)
        {
            if (mlx->parse.map[i][j] != ' ' && mlx->parse.map[i][j] != '\0')
            {
                ft_free_map(mlx);
                ft_return("Map not closed", mlx);
            }
            i--;
        }
        j++;
    }
}

void    ft_catch_position(t_deflibx *mlx)
{
    int i;
    int j;

    i = 0;
    while(i < mlx->parse.mapnbline - 1)
    {
        j = 0;
        while (mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] == 'N' || mlx->parse.map[i][j] == 'S' || mlx->parse.map[i][j] == 'E' || 
            mlx->parse.map[i][j] == 'W')
            {
                if (mlx->parse.positionset == 1)
                {
                    ft_return("More than one position declared", mlx);
                    free(mlx);
                }
                mlx->parse.position = mlx->parse.map[i][j];
                mlx->parse.positionset = 1;
                mlx->parse.directionset = 1;
            }
            j++;
        }
        i++;
    }
    printf("pos = %c\n", mlx->parse.position);
}

void ft_fillspace(t_deflibx *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(mlx->parse.map[i][j] != '\0')
    {
        if (mlx->parse.map[i][j] == '1')
        {
            j++;
            while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '1';
                    j++;
                }
        }
        if (mlx->parse.map[i][j] == '\0')
                break;
        j++;
    }
    i = mlx->parse.mapnbline - 1;
    j = 0;
    while(mlx->parse.map[i][j] != '\0')
    {
        if (mlx->parse.map[i][j] == '1')
        {
            j++;
            while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '1';
                    j++;
                }
        }
        if (mlx->parse.map[i][j] == '\0')
                break;
        j++;
    }
    i = 1;
    while (i < mlx->parse.mapnbline - 1)
    {
        j = 0;
        while (mlx->parse.map[i][j] != '\0')
        {
            if (mlx->parse.map[i][j] == '1')
            {
                j++;
                while(mlx->parse.map[i][j] != '\0')
                {
                    if (mlx->parse.map[i][j] == ' ')
                        mlx->parse.map[i][j] = '0';
                    j++;
                }
            }
            if (mlx->parse.map[i][j] == '\0')
                break;
            j++;
        }
        i++;
    }
    i = 0;
    while (i <= mlx->parse.mapnbline - 1)
    {
        printf("lineee %.2d = |%s|\n", i, mlx->parse.map[i]);
        i++;
    }
}

void ft_map(t_deflibx *mlx, char *line, int fd)
{
    int j;
    int i;

    j = 0;
    i = 0;
    ft_line_map(mlx);
    if (!(mlx->parse.map = (char**)malloc(sizeof(char*) * (mlx->parse.mapnbline + 1))))
        ft_return ("MALLOC ERROR :(", mlx);
    printf("nbline = %d biggerline = %d\n\n\n",mlx->parse.mapnbline, mlx->parse.mapbiggerline);
    while (j <= mlx->parse.mapnbline)
    {
        if (!(mlx->parse.map[j] = (char*)malloc(sizeof(char) * (mlx->parse.mapbiggerline + 1))))
        {
            while (i < j)
            {
                free(mlx->parse.map[i]);
                i++;
            }
            free(mlx->parse.map);
            ft_return ("MALLOC ERROR :(", mlx);
        }
        ft_bzero_cub(mlx->parse.map[j], mlx->parse.mapbiggerline);
        j++;
    }
    ft_copy_map(mlx);
    ft_check_map(mlx);
    ft_fillspace(mlx);
    ft_catch_position(mlx);
    ft_free_map(mlx);
}

int ft_read0(int fd, t_deflibx *mlx)
{
    char *line;
    int ret;
    int map;

    while((ret = get_next_line(fd, &line)) > -1 && !(map = ft_check_wall(line)))
    {
        if (!(ft_check_args(line, mlx)))
            return (0);
        free(line);
        if (ret == 0)
            break;
    }
    if (map == 0)
       ft_return("Map Missing", mlx);
    free(line);
    ft_map(mlx, line, fd);
    return (1);
}

int     ft_parsing(t_deflibx *mlx)
{
    int fd;

    if ((fd = open(mlx->parse.files, O_RDONLY)) < 0)
        return (0);
    if (!(ft_read0(fd, mlx)))
        return(0);
    close(fd);
    return (1);
}

void ft_parse_initialization(t_deflibx *mlx)
{
    mlx->text.width = 64;
    mlx->text.height = 64;
    mlx->sprites.width = 64;
    mlx->sprites.height = 64;
    mlx->parse.Fcolorset = 0;
    mlx->parse.Ccolorset = 0;
    mlx->parse.resolutionset = 0;
    mlx->parse.widthset = 0;
    mlx->parse.heightset = 0;
    mlx->parse.northset = 0;
    mlx->parse.southset = 0;
    mlx->parse.westset = 0;
    mlx->parse.eastset = 0;
    mlx->parse.blue = 0;
    mlx->parse.green = 0;
    mlx->parse.red = 0;
    mlx->parse.spriteset = 0;
    mlx->parse.positionset = 0;
    /*mlx->parse.pathset = 0; UNNECESSARY*/
    mlx->parse.mapnbline = 0;
    mlx->parse.mapbiggerline = 0;
}

/*int main(void)
{
    t_deflibx mlx;

    mlx.parse.files = "./map.cub";
    ft_parse_initialization(&mlx);
    ft_parsing(&mlx);
    printf("resolution = [%d %d]\n", mlx.parse.Width, mlx.parse.Height);
    printf("Floor color = %d\n", mlx.color.floorcolor);
    printf("Ceil color = %d\n", mlx.color.ceilcolor);
    printf("north = %s\n", mlx.parse.northtext);
    printf("south = %s\n", mlx.parse.southtext);
    printf("east = %s\n", mlx.parse.easttext);
    printf("west = %s\n", mlx.parse.westtext);
    printf("sprite = %s\n", mlx.parse.sprite);
    printf("WIDTH = %d\n", mlx.parse.Width);
    printf("HEIGHT = %d\n", mlx.parse.Height);
    ft_free(&mlx);
}*/



