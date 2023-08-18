/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_player_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:44:57 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/17 23:46:42 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     check_map_extantion(char *map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    while (i >= 0)
    {
        if (map[i] == '.' && map[i])
        {
            if (map[i + 1] == 'c' && map[i + 2] == 'u' && map[i + 3] == 'b' && !map[i + 4])
                return (0);
        }
        i--;
    }
    return (1);
}

int     check_double_element(char **map)
{
    int     i;
    int     count;
    int     count1;
    int     count2;
    int     count3;
    int     count4;
    int     all;
    char    **a;
    char    *trim;

    i = 0;
    count = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    while (map[i])
    {
        trim = ft_strtrim(map[i], " ");
        if (trim[0] != '1')
        {
            a = ft_split(map[i], ' ');
            if (!ft_strcmp(a[0], "NO"))
                count++;
            else if (!ft_strcmp(a[0], "SO"))
                count1++;
            else if (!ft_strcmp(a[0], "EA"))
                count2++;
            else if (!ft_strcmp(a[0], "WE"))
            {
                printf("here\n");
                count3++;
            }
            else if (!ft_strcmp(a[0], "F") || !ft_strcmp(a[0], "C"))
                count4++;
        }
        i++;
    }
   // all = count + count1 + count2 + count3;
    if (count + count1 + count2 + count3 != 4 || count4 != 2)
        return (1);
    return (0);
}

int     check_wall_text(char **src)
{
    int i;
    int count;
    int count1;
    int count2;
    int count3;
    int count4;
    int count5;
    char    *trim;

    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    count  = 0;
    i = 0;
    while (src[i])
    {
        trim = ft_strtrim(src[i], " ");
        if (trim[0] != '1')
        {
            if (trim[0] == 'N' && trim[1] == 'O')
                count++;
            else if (trim[0] == 'W' && trim[1] == 'E')
                count1++;
            else if (trim[0] == 'E' && trim[1] == 'A')
                count2++;
            else if (trim[0] == 'S' && trim[1] == 'O')
                count3++;
            else if (trim[0] == 'S' && trim[1] == 'O')
                count3++;
            else if (trim[0] == 'C')
                count4++;
            else if (trim[0] == 'F')
                count5++;
        }
        i++;
    }
    if (count != 1 || count1 != 1 || count2 != 1 || count3 != 1 || count4 != 1 || count5 != 1)
        return (1);
    return (0);
}