#include "../ft_printf_bonus.h"
#include <limits.h>

int	main()
{
    //printf("%d\n", printf("real:%05d\n", -14));
    //printf("%d\n", ft_printf("mine:%05d\n", -14));
    //printf("real %d\n", printf("real: %.1s %.2s %.3s %.4s \n", " - ", "", "4", ""));
    //printf("mine %d\n", ft_printf("mine: %.1s %.2s %.3s %.4s \n", " - ", "", "4", ""));
	ft_printf("mine=% d\n", LONG_MIN);
	//printf("real=% d\n", LONG_MIN);
}

/*
flag 0:
Le - doit s'afficher avant les zero, il faut donc print le - non pas dans les fonctions de print classique mais comme un left flag dans le cas ou les nombres sont signes il faut sans doute un nouveau booleen dans la structure.
*/
