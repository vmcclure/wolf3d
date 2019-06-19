/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:03:38 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/08 14:32:15 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	int		i;
	t_mlx	mlx;
	int		fd;

	mlx.secret = 1;
	fd = open("maps/map1", O_RDONLY);
	i = get_map(fd, &mlx.map);
	close(fd);
	if (i <= 0)
	{
		if (i == 0)
			ft_putstr("error valid map file\n");
		else if (i == -1)
			ft_putstr("error malloc\n");
		else if (i == -2)
			ft_putstr("error read file\n");
		return (0);
	}
	wolf3d(&mlx);
	return (0);
}
