/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:59:37 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/04 15:15:07 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

char	betafunc(unsigned int pos, char c)
{
	return (ft_toupper(c));
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		len_chars;
	int		len_lines;
	int		input_fd;

	len_lines = 0;
	input_fd = open(argv[1], O_RDONLY);
	if (argc < 2 || read(input_fd, 0, 0) == -1)
		return (close(input_fd), ft_printf("\n\e[1;32mINVALID FILE\e[0m"));
	while ((str = get_next_line(input_fd)))
	{
		str = ft_strmapi(str, &betafunc);
		len_chars += _nsx_strlen(str);
		len_lines++;
		ft_putstr_fd(str, 1);
		free(str);
		str = 0;
	}
	ft_printf("\n\n\t\e[0;0m\e[1;42m(OUTPUT LENGTH : %d)\e[0;0m", len_chars);
	ft_printf("\n\n\t\e[1;42m(OUTPUT LINES : %d)\e[0;0m", len_lines);
}
