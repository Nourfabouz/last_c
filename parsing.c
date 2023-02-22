/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:37:26 by fabou-za          #+#    #+#             */
/*   Updated: 2023/02/22 17:41:17 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_dup(bool *exist)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (exist[i++] == 0)
		{
			free(exist);
			return (-1);
		}
	}
	return (0);
}

int	parse_function(t_data *mlx)
{
	int j;
	int	 if_error;
	bool *exist;
	int if_dup;

	exist = ft_calloc(6, 1);
	if_dup = 0;
	j = 0;
	if_error = check_function(mlx->lines, &j, &exist[0], mlx);
	if (if_error == -1)
		return (-1);
	if ((if_dup = check_dup(&exist[0])) == -1)
		return (-1);
	free(exist);
	if (if_error == 2)
	{
        //printf("j before check is %d and the string is %s\n", j, mlx->lines[j]);
		if (check_map(&mlx->lines[j]) == 1)
			return (-1);
        //printf("j after check is %d and the string is %s\n", j, mlx->lines[j]);
		mlx->map = &mlx->lines[j];
	}
	else
		return (3);
	return (0);
}

void read_file(int fd, t_data *mlx)
{
	char *s;
	char **temp;
	int i;
	int j;

	i = 1;
	temp = NULL;
	while((s = get_next_line(fd)))
	{
		temp = mlx->lines;
		mlx->lines = malloc((i + 1) * sizeof(char *));
		j = 0;
		if (temp)
		{
			while (temp[j])
			{
				mlx->lines[j] = temp[j];
				j++;
			}
		}
		free(temp);
		mlx->lines[j++] = s;
		mlx->lines[j] = 0;
		i++;
	}
}

void	init_mlx(t_data *mlx)
{
	mlx->north_texture = NULL;
	mlx->west_texture = NULL;
	mlx->east_texture = NULL;
	mlx->south_texture = NULL;
	mlx->map = NULL;
	mlx->floor_color = 0;
	mlx->ceiling_color = 0;
}

int check_file_extension(char *s)
{
	char *pt;

	pt = NULL;
	if (ft_strchr(s, '.') == ft_strchr(s, '.'))
	{
		pt = ft_strchr(s, '.');
		if (!pt || ft_strcmp(pt, ".cub"))
		{
			printf("ERROR\nWrong extension!");
			return (1);
		}
	}
	else
	{
		printf("ERROR\nWrong extension!");
		return (1);
	}
	return (0);
}
