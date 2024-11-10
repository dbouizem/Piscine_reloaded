/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:12:44 by dbouizem          #+#    #+#             */
/*   Updated: 2024/11/10 20:00:38 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

void	ft_putstr_fd(int fd, int len, char *str)
{
	int	i;

	i = 0;
	if (len == -1)
	{
		while (str[i])
			write(fd, &str[i++], 1);
	}
	else
		write(fd, str, len);
}

void	ft_bf_print(int fd)
{
	char	buff[BUFFER_SIZE];
	int		b_readed;

	b_readed = 1;
	while (b_readed > 0)
	{
		b_readed = read(fd, buff, BUFFER_SIZE);
		if (b_readed == -1)
			break ;
		ft_putstr_fd(1, b_readed, buff);
	}
}

int	main(int ac, char **av)
{	
	int	fd;

	if (ac < 2)
		return (ft_putstr_fd(2, -1, "File name missing.\n"), 0);
	if (ac > 2)
		return (ft_putstr_fd(2, -1, "Too many arguments.\n"), 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(2, -1, "Cannot read file.\n"), 0);
	ft_bf_print(fd);
	close(fd);
	return (0);
}
