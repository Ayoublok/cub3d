/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:50:21 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 00:38:39 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_put_pixl(t_picture *test, int x, int y, int color)
{
	char	*hold_pic_addr;

	if (x < 0 || x >= 640 || y < 0 || y >= 640)
		return ;
	hold_pic_addr = test->adrr + (y * test->len + x * (test->bit_pixl / 8));
	*(unsigned int *)hold_pic_addr = color;
}

unsigned int get_color(t_imgs *imgs, int x, int y)
{
	char		*color;

	if (x < 0 || x >= imgs->width || y < 0 || y >= imgs->height)
		return (0);
	color = (imgs->add + (y * imgs->line + x * (imgs->bits / 8)));
	return (*(unsigned int *)color);
}

void	draw_walls(t_picture *data)
{
	int	s;

	s = (data->ray_distance_hor > data->ray_distance_ver);
	if (data->ray_distance_hor == data->ray_distance_ver)
		s = data->old_s;
	data->old_s = s;
	if (data->dir_v == 'E' && s)
		draw_wall(data, &data->imgs[1], 1);
	if (data->dir_v == 'W' && s)
		draw_wall(data, &data->imgs[2], 1);
	if (data->dir_h == 'N' && !s)
		draw_wall(data, &data->imgs[0], 0);
	if (data->dir_h == 'S' && !s)
		draw_wall(data, &data->imgs[3], 0);
}

void	draw_wall(t_picture * data, t_imgs *imgs, int s)
{
	int		end;
	float		grid;
	int		x = 0;
	float	y = 0;
	int i = 0;

	grid = imgs->height / data->wall_tall;
	if (data->wall_tall > 640)
	{
		y = grid * ((data->wall_tall - 640) / 2);
		data->wall_tall = 640;
	}
	data->start = 320 - (data->wall_tall / 2);
	data->begin = data->start;
	end = data->start + data->wall_tall;
	if (!s)
		x = (int)(imgs->width * (data->tx_hor / 64)) % imgs->width;
	if (s)
		x = (int)(imgs->width * (data->ty_ver / 64)) % imgs->width;
	i = 0;
	while(i < data->start)
	{
		my_put_pixl(data, data->f , i , data->c_color);
		i++;
	}
	while (data->start < end && data->start < 640)
	{
		my_put_pixl(data, data->f , data->start , get_color(imgs,x,y));
		data->start++;
		y += grid;
	}
	i = end;
	while(i < 640)
	{
		my_put_pixl(data, data->f , i , data->f_color);
		i++;
	}
}
