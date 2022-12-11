
#include "../include/push_swap.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	push_swap(char **av)
{
	t_piles		pile;
	int			size;
	int			i;

	i = -1;
	size = push_swap_strlen(av);
	pile.a = malloc(size * sizeof(int));
	if (!pile.a)
		return ;
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	pile.size_b = 0;
	while (++i < size)
		pile.a[i] = push_swap_atoi(av[i], pile.a);
	check_doubles(pile.a, size);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		return (0);
	}
	return (0);
}
