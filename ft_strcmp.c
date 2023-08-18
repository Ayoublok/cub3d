/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:44:04 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/17 15:18:30 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	char	*s3;
	char	*s4;

	i = 0;
	s3 = s1;
	s4 = s2;
	if (!s1 || !s2)
		return (1);
	while ((s3[i] != '\0' || s4[i] != '\0'))
	{
		if (s3[i] > s4[i])
			return (1);
		else if (s3[i] < s4[i])
			return (-1);
		i++;
	}
	return (0);
}
