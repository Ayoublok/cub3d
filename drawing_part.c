/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:33:33 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 00:53:40 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_picture *test, int color)
{
	double	rad;
	double	x;
	double	y;
	double	angle;
	double	cur_angl;

	test->color = 0x0ff0000; //red;
	angle = test->deta + 30;
	int i = 0;
	test->f = 0;
	
	while (test->f < 640)
	{
			hor_int(test, angle, x, y); // just to get distance horizontal
			ver_int(test, angle, x, y); // just to get distance vertical
			if (test->ray_distance_hor <= test->ray_distance_ver)
				i = 1;
			else if (test->ray_distance_ver <= test->ray_distance_hor)
				i = 0;
			cur_angl = (test->deta - angle);
			if (!i)
				test->new_ray_distance = test->ray_distance_ver * cos(((cur_angl) * M_PI / 180));
			else 
				test->new_ray_distance = test->ray_distance_hor * cos(((cur_angl) * M_PI / 180));
			test->dist_p_screen	= 320 / tan(30 * M_PI / 180);
			test->wall_tall	= ((64 / test->new_ray_distance) * test->dist_p_screen);
			draw_walls(test);
			test->f++;
			angle -= 64.0 / 640.0;
	}
}

void	draw_map(char **map, t_picture *test)
{
	put_player(test, 0x00FDFD55);
	mlx_put_image_to_window(test->ptr, test->wind, test->image_adrr, 0, 0);
}

void	draw_squar(t_picture *test, int old_x, int old_y, int color)
{
	int	x;
	int	y;

	x = old_x;
	while (x <= old_x + 62)
	{
		y = old_y;
		while (y <= old_y + 62)
			my_put_pixl(test, x, y++, color);
		x++;
	}
}