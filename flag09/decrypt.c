void	ft_putstr(char const *s)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	if (s == NULL)
		return ;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        ft_putstr("put one argument");
        return -1; 
    }
    i = 0;
    while (argv[1][i])
    {
        ft_putstr(argv[1][i] - 1);
        i++;
    }
    ft_putstr("\n");
    return 0;
}