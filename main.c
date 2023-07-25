/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:50:00 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/07/25 17:46:05 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_perror()
{
    write (2, "ERROR\n", 6);
    exit(1);
}

char    *get_content(char *str, char c)
{
    int     i;
    int     i2;
    char    *content;
    
    i = 0;
    i2 = 0;
    while (str[i] && str[i] != c) // skip object (C or F)
        i++;
    while(str[i] == '\t' || str[i] == ' ') // skip space
    {
        i++;
        i2++;
    }
    content = malloc(sizeof(char) * (i2 + 1)); 
    if (!content)
        return (NULL);
    i2 = 0;
    while (str[i])
        content[i2++] = str[i++];
    content[i2] = '\0';
    return (content);
}

int     check_text_ext(char **map)
{
    int     i;
    char    *trim;
    char    *ext;;
    char    **wall_pos;
    char    *line_content;
    
    i = 0;
    while (map[i])
    {
        trim = ft_strtrim(map[i], " ");
        wall_pos = ft_split(trim, ' ');
        if (!ft_strcmp(wall_pos[0], "NO") || !ft_strcmp(wall_pos[0], "WE") || !ft_strcmp(wall_pos[0], "SO") || !ft_strcmp(wall_pos[0], "EA"))
        {
            line_content = get_content(trim, ' ');
            if (!line_content || !line_content[0])
                return (1);
            ext = ft_strrchr(line_content, '.');
            ext++;
            if (ft_strcmp(ext, "xpm"))
                return (1);
        }
        i++;
    }
    return (0);
}

void    my_put_pixl(t_picture *test, int x, int y, int color)
{
    char *hold_pic_addr;
	if (x < 0 || x >= 640 || y < 0 || y >= 640)
		return ;
    hold_pic_addr = test->adrr + (y * test->len + x * (test->bit_pixl / 8));
    *(unsigned int *)hold_pic_addr = color;
}

void    draw_squar(t_picture *test, int old_x, int old_y, int color)
{
    int x;
    int y;

    x = old_x;

    while (x <= old_x + 64)
    {
        y = old_y;
        while (y <= old_y + 64)
            my_put_pixl(test, x, y++, color);
        x++;
    }
}

void    put_player(t_picture *test)
{
    float   rad;
    float   x;
    float   y;
    float   angl;

    angl = 0;
    while (angl < 360)
    {
        rad = angl * M_PI / 180;
        x = test->x_p;
        y = test->y_p;
        printf("x == %f, y == %f \n", x, test->x_p);
        while (sqrt(pow(test->x_p - x, 2) + pow(test->y_p - y, 2)) < 5)
        {
            my_put_pixl(test, x, y, test->color);
            x += cos(rad);
            y -= sin(rad);
        }
        angl++;
    }
}

void    draw_player(char **map, t_picture  *test)
{
    int         x;
    int         y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
            {
                test->x_p  = x * 64 + 32; // we add 32 to make player in centre
                test->y_p  = y * 64 + 32;
                test->color = 0x00FDFD55;
            }
            x++;
        }
        y++;
    }
    put_player(test);
}

void    draw_map(char **map, t_picture  *test)
{
    int         x;
    int         y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                draw_squar(test, x * 64, y * 64, 0x000000CD);
            x++;
        }
        y++;
    }
    draw_player(map, test);
    //printf ("------> x == %d, y == %d, color == %d\n", test->data->x, test->data->y, test->data->color);
    mlx_put_image_to_window(test->ptr, test->wind, test->image_adrr, 0, 0);
}

int     main(int ac, char **av)
{
    int     i;
    //int     j;
    int     fd;
    char    *map;
    char    **map_v2;
    char    **map_v3;
    char    *map_content;
    t_picture  *test;

    i = 0;
   // j = 0;
    test = malloc(sizeof(t_picture));
    // str = malloc(sizeof(t_data));
    // if (!str)
    // {
    //     printf ("Error\n");   
    //     return (1);
    // }
    map = ft_strdup(av[1]);
    fd = open(map, O_RDONLY);
    map_content = get_next_line (fd);
    map_v2 = ft_split(map_content, '\n');
    map_v3 = map_v2 + 6;
    // while (map_v3[i])
    //     printf ("%s\n", map_v3[i++]);
    if (ac != 2)
        ft_perror();
    if (check_map_extantion(map) || check_character(map_v2) || check_wall_text(map_v2) || check_double_element(map_v2))
        ft_perror();
    test->ptr = mlx_init();
    test->wind = mlx_new_window(test->ptr, 640, 640, "cub3d");
    test->image_adrr = mlx_new_image(test->ptr, 640, 640);
    test->adrr = mlx_get_data_addr(test->image_adrr, &test->bit_pixl, &test->len, &test->end);
    draw_map(map_v3, test);
    //draw_player(map_v3, test);
    mlx_loop(test->ptr);
}