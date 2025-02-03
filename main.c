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

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int			i = 0;
	int			fd;
	const char	*path = "text1.txt";
	char	*line;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%d --> %s\n", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
