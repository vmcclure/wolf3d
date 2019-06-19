/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:35:35 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/04 16:41:34 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	chek_read_str(char *str)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') &&
			(str[i] < 'a' || str[i] > 'z') && str[i] != '\n' && str[i] != ' ')
			return (0);
		if (str[i] == 'p')
			j++;
	}
	if (j != 1)
		return (0);
	return (1);
}

static int	chek_split_map(char **map)
{
	int	j;

	j = 0;
	while (map[++j] != 0)
		if (ft_strlen(map[0]) != ft_strlen(map[j]))
			return (0);
	return (1);
}

static int	chek_walls(char **map)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (map[0][++i] != '\0')
		if (map[0][i] != '1')
			return (0);
	i = 0;
	while (map[++i] != 0)
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
	i--;
	while (map[i][++j] != '\0')
		if (map[i][j] != '1')
			return (0);
	return (1);
}

int			get_map(int fd, char ***map)
{
	char	str[1000];
	int		i;

	ft_bzero(str, 1000);
	i = read(fd, str, 1000);
	if (i <= 0)
		return (-2);
	if (!chek_read_str(str))
		return (0);
	if (!(*map = ft_strsplit(str, '\n')))
		return (-1);
	if (!(chek_split_map(*map)))
		return (0);
	if (!(chek_walls(*map)))
		return (0);
	return (1);
}
