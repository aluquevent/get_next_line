/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:54:48 by aluque-v          #+#    #+#             */
/*   Updated: 2025/02/03 14:43:18 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int			fd1, fd2, fd3;
	const char	*path1 = "text1.txt";
	const char	*path2 = "text2.txt";
	const char	*path3 = "text3.txt";
	char		*line1, *line2, *line3;

	fd1 = open(path1, O_RDONLY);
	fd2 = open(path2, O_RDONLY);
	fd3 = open(path3, O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("Error al abrir los archivos.\n");
		return (1);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		if (!line1 && !line2 && !line3)
			break;
		if (line1)
		{
			printf("Archivo 1: %s\n", line1);
			free(line1);
		}
		if (line2)
		{
			printf("Archivo 2: %s\n", line2);
			free(line2);
		}
		if (line3)
		{
			printf("Archivo 3: %s\n", line3);
			free(line3);
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
