#include "../ft_printf_bonus.h"

int	main()
{
    printf("real:%04d\n", -14);
    ft_printf("mine:%04d\n", -14);
}

/*
flag 0:
Le - doit s'afficher avant les zero, il faut donc print le - non pas dans les fonctions de print classique mais comme un left flag dans le cas ou les nombres sont signes il faut sans doute un nouveau booleen dans la structure.
*/
