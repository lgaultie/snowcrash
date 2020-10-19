#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
    //while (argv[1][i])
    //{
    //    ft_putchar(argv[1][i] - i);
    //    i++;
    //}
    printf("%s", "f");
    printf("%d", 3);
    printf("%s", "i");
    printf("%s", "j");
    printf("%s", "i");
    printf("%d", 1);
    printf("%s", "j");
    printf("%s", "u");
    printf("%d", 5);
    printf("%c", 130);
    printf("%c", 127);
    printf("%s", "g");
    printf("%c", 130);
    printf("%s", "d");
    printf("%c", 131);
    printf("%c", 130);
    printf("%d", 9);
    printf("%d", 6);
    printf("%c", 131);
    printf("%d", 7);
    printf("%s", "g");
    printf("%s", "l");
    printf("%c", 127);
    printf("%c", 140);
    printf("%c", 137);
    printf("%c", 10);
    return 0;
}