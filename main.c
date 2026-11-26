#include "ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
close(1);
dprintf(2, "%d\n", ft_putchar('a'));
    // ft_putunbr(5);
    // ft_printf("\n");
    // ft_putnbr(-1);

}