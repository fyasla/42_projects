void	ft_putstr_fd(char *s, int fd);

int		main(int ac, char **av)
{
	(void)ac;
	ft_putstr_fd(av[1], 1);
	return (0);
}