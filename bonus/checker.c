#include "../include/push_swap.h"
#include "../printf/ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

void free_error(t_piles *pile, int choix)
{
	free(pile->a);
	free(pile->b);
	if (choix)
		ft_printf("Error\n");
	exit(1);
}

void	exec_instruction(t_piles *pile, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		swap_a(pile, 1);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_b(pile, 1);
	else if (!ft_strcmp(instruction, "ss\n"))
		swap_s(pile, 1);
	else if (!ft_strcmp(instruction, "ra\n"))
		rotate_a(pile, 1);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_b(pile, 1);
	else if (!ft_strcmp(instruction, "rr\n"))
		rotate_r(pile, 1);
	else if (!ft_strcmp(instruction, "rra\n"))
		reverse_rotate_a(pile, 1);
	else if (!ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_b(pile, 1);
	else if (!ft_strcmp(instruction, "rrr\n"))
		reverse_rotate_r(pile, 1);
	else if (!ft_strcmp(instruction, "pa\n"))
		push_a(pile, 1);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_b(pile, 1);
	else
		free_error(pile, 1);
}

void	read_from_stdin(t_piles *pile)
{
	char		*instruction;

		instruction = get_next_line(0);
		while (instruction)
		{
			exec_instruction(pile, instruction);
			free(instruction);
			instruction = get_next_line(0);
		}
		if (check_sorted(pile->a, pile->size_a, 0) && pile->size_b == 0)
			ft_printf("OK\n");
		else
			ft_printf("K0\n");
		free_error(pile, 0);
}

int	*c_errors(char **av)
{
	int	*a;
	int	size;
	int	i;

	i = -1;
	size = push_swap_strlen(av);
	a = malloc(size * sizeof(int));
	while (++i < size)
		a[i] = push_swap_atoi(av[i], a);
	check_doubles(a, size);
	return (a);
}

int	main(int ac, char **av)
{
	t_piles	pile;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		pile.a = c_errors(av);
		pile.size_a = push_swap_strlen(av);
		pile.b = malloc(pile.size_a * sizeof(int));
		if (!pile.b)
		{
			free(pile.a);
			return (0);
		}
		pile.size_b = 0;
		read_from_stdin(&pile);
	}
	return (0);
}
