#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char *ft_strjoin(char *line, char c)
{
	char *tmp;
	int		i = 0;

	if (!line)
	{
		tmp = malloc(2);
		tmp[0] = c;
		tmp[1] = 0;
	}
	else
	{
		while (line[i])
			i++;
		tmp = malloc(i + 2);
		i = 0;
		while (line[i])
		{
			tmp[i] = line[i];
			i++;
		}
		free(line);
		tmp[i] = c;
		tmp[ i + 1] = 0;
	}
	return (tmp);
}

char *ft_get_next_line(int fd)
{
	char	*line = 0;
	char	c = 0;
	int		nbytes = 0;

	nbytes = read(fd, &c, (200 * 0) + 1);
	if (nbytes <= 0)
		return (0);
	if (!line)
		line = ft_strjoin(line, '\0');
	while (nbytes > 0)
	{
		line = ft_strjoin(line, c);
		nbytes = read(fd, &c, (200 * 0) + 1);
	}
	return (line);
}
int	main()
{
	int 	fd;
	fd = open("/Users/agallipo/Desktop/exam/hey",O_RDONLY);
	char	*line;

    while ((line = ft_get_next_line(fd)) != 0)
    {
        printf("My line [%s]\n", line);
        free(line);
    }
	return (0);
}
