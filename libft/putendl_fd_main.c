void	ft_putendl_fd(char *s, int fd);

int		main(int ac, char **av)
{
	(void)ac;
	ft_putendl_fd(av[1], 1);
	return (0);
}