void	ft_putchar_fd(char c, int fd);

int		main(int ac, char **av)
{
	(void)ac;
	ft_putchar_fd(av[1][0], 1);
	return (0);
}