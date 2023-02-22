/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:18:54 by fabou-za          #+#    #+#             */
/*   Updated: 2023/02/22 18:20:33 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	mlx;
	int if_error;

	if (argc != 2)
		printf("Too many or few arguments!\n");
	else
	{
		if ((if_error = check_file_extension(argv[1])) == 1)
			return (1);
		int fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (printf("ERROR\ncannot open the file"));
		mlx.lines = NULL;
		init_mlx(&mlx);
		read_file(fd, &mlx);
		if_error = parse_function(&mlx);
		display_message_error(if_error);
        /*if (if_error == -1 )//
        {
            free_mlx(&mlx);
            printf("byyyyyyyyyyyyyyyye\n");
            return (1);
        }
        int i = 0;
        while (mlx.map[i] != NULL)
        {
            printf("map line %d is '%s'\n", i, mlx.map[i]);
            i++;
        }*/
		free_mlx(&mlx);
		system("leaks Cub3d");
	}
}
