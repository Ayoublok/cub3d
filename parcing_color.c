/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:18:47 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/17 23:44:37 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     check_number(char *str)
{
    int     i;
    char    **number;

    i = 0;
    number = ft_split(str, ',');
    if (!ft_isdigit(number[0]) || !ft_isdigit(number[1]) || !ft_isdigit(number[2]))
        ft_perror("invalid color character\n");
    if (atoi(number[0]) <= 0 || atoi(number[1]) <= 0 || atoi(number[2]) <= 0)
        return (1);
    while (i < 3)
    {
        if (!(atoi(number[i]) >= 0 && atoi(number[i]) <= 255))
            ft_perror("Is Not Valid RGB\n");
        i++;
    }
    return (0);
}

int     comma(char *str)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    if (count != 2)
        return (1);
    return (0);
}

int     check_color(char **map)
{
    int     i;
    int     j;
    char    *trim;
    char    *line_content;
    char    ch;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == 'C' || trim[0] == 'F')
        {
            ch = trim[0];
            line_content = get_content(trim, ' ');
            if (comma(line_content))
                ft_perror ("more than comma in RGB\n");  
            if (check_number(line_content))
                return (1);
        }
        i++;
    } 
    return (0);
}
