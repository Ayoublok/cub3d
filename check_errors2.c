/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:57:51 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 18:24:44 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(char *line_content, char **wall_pos, t_picture *data, char *trim)
{
	char *ext;
	if(!ft_strcmp(wall_pos[0], "NO"))
		data->north_xpm = ft_strdup(line_content);
	if(!ft_strcmp(wall_pos[0], "SO"))
		data->south_xpm = ft_strdup(line_content);
	if(!ft_strcmp(wall_pos[0], "EA"))
		data->east_xpm = ft_strdup(line_content);
	if(!ft_strcmp(wall_pos[0], "WE"))
		data->west_xpm = ft_strdup(line_content);
	if (!line_content || !line_content[0])
	{
		free(trim);
		ft_free(wall_pos);
		return (1);
	}
	ext = ft_strrchr(line_content, '.');
	ext++;
	if (ft_strcmp(ext, "xpm"))
	{
		free(trim);
		ft_free(wall_pos);
		return (1);
	}
	return 0;
}

int check_text_ext(char **map, t_picture *data)
{
	int i;
	char *trim;
	char **wall_pos;
	char *line_content;

	i = 0;
	int j = 0;
	while (map[i])
	{
		trim = ft_strtrim(map[i], " ");
		wall_pos = ft_split(trim, ' ');
		if (!ft_strcmp(wall_pos[0], "NO") || !ft_strcmp(wall_pos[0], "WE") 
			|| !ft_strcmp(wall_pos[0], "SO") || !ft_strcmp(wall_pos[0], "EA"))
		{
			line_content = get_content(trim, ' ');
			check_textures(line_content, wall_pos, data, trim);
			free(line_content);
		}
		free(trim);
		ft_free(wall_pos);
		i++;
	}
	return (0);
}
