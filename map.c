/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:56:31 by fabou-za          #+#    #+#             */
/*   Updated: 2023/02/22 19:07:01 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_map_suite(char **str, int len_first, int j, int *flag)
{
    int i;

    i = 1;
	while (str[j][i] && i < len_first - 1)
	{
		if (ft_strchr("NSWE01 ", str[j][i]) == NULL)
			return (1);
		if (ft_strchr("NSWE", str[j][i]) != NULL)
		{
			if (*flag == 1)
				return (1);
			else
				(*flag) = 1;
		}
		if (str[j][i] != '1' && str[j][i] != ' ')
        {
			str[j + 1] = ft_strtrim(str[j + 1], " \n");
				if (!str[j + 1][i] || !str[j - 1][i] || str[j][i - 1] == ' ' || str[j][i + 1] == ' ' \
                || str[j - 1][i] == ' ' || str[j + 1][i] == ' ')
				{
					printf("the string is '%s'\n", str[j + 1]);
					printf("heeeeere he char is %c\n", str[j][i]);
					printf("the char left '%c'\n", str[j][i - 1]);
					printf("the char right '%c'\n", str[j][i + 1]);
					printf("the char top '%c'\n", str[j - 1][i]);
					printf("the char bottom '%c'\n", str[j + 1][i]);
					return (1);
				}
         }
        i++;

	}
	return (0);
}

int check_first_last_maplines(int len_first, int len_map, char **str)
{
	int j;
    int len_last;

    len_last = ft_strlenew(&str[len_map - 1]);
	j = 0;
	while ((str[0][j] && j <= len_first - 1))
	{
		if ((str[0][j] != '1' && str[0][j] != ' '))
			return (1);
		j++;
	}
	j = 0;
	while (str[len_map - 1][j] && j <= len_last - 1)
	{
		if (str[len_map - 1][j] != '1' && str[len_map - 1][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int check_map(char **str)
{
	int len_first;
	int len_map;
	int j;
	int flag;

	flag = 0;
	len_first = ft_strlenew(&str[0]);
	len_map = ft_maplen(str);
	if ((check_first_last_maplines(len_first, len_map, str) == 1) || len_map <= 2)
		return (1);
	j = 1;
	while (str[j] && (j <= len_map - 1))
	{
		len_first = ft_strlenew(&str[j]);
		str[j][len_first] = '\0';
		if (str[j][0] != '1' || str[j][len_first - 1] != '1')
			return (1);
		if (check_map_suite(&str[0], len_first, j, &flag) == 1)
		{
			//printf("the prob is in map with string '%s'\n", str[j]);
			return (1);
		}
		j++;
	}
	if (flag != 1)
	{
		//printf("here's the prob\n");
		return (1);
	}
	return (0);
}
