int main(int argc, char **argv)//inter
{
	int used[255] = {0};
	int i = 2 ; int j = 0;

	if(argc == 3)
	{
		while(i > 0)
		{
			while(argv[i][j])
			{
				if(i == 2 && !used[(unsigned char)argv[i][j]])
					used[(unsigned char)argv[i][j]] = 1;
				if(i == 1 && used[(unsigned char)argv[i][j]] == 1)
				{
					used[(unsigned char)argv[i][j]] = 2;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i--;
		}
		write(1, "\n", 1);
		return(0);
	}
}

int main(int argc, char **argv)//union
{
	int used[255] = {0};
	int i = 1 ; int j = 0;

	if(argc == 3) 
	{
		while(i < 2)
		{
			while(argv[i][j])
			{
				if(!used[(unsigned char)argv[i][j]])
				{
					used[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
		write(1, "\n", 1);
		return(0);
	}
}

ft_strjoin(char *line, char c)
{
	char *tmp;
	int i;

	if(!line)
	{
		tmp = (char *)malloc(2);
		tmp[0] = c;
		tmp[1] = 0;
	}
	else
	{
		i = 0;
		while(line[i])
			i++;
		tmp = (char *)malloc(i + 2);
		i = 0;
		while(line[i])
			tmp[i] = line[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(line);
	}
	return(tmp);
}

char *get_next_line(int fd)
{
	char *line = 0;
	char c = 0;
	int		nbytes = 0;
	nbytes = read(fd, &c, (BUFFER_SIZE * 0) + 1);
	if(nbytes == 0)
		return(0);
	if(line == 0)
		line = ft_strjoin(line, '\0');
	while(nbytes > 0)
	{
		line = ft_strjoin(line, c);
		if(c == "\n" || c == "\0")
			break;
		nbytes = read(fd, &c, 1);
	}
	return(line);
}
