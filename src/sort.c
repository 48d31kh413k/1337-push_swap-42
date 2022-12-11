
#include "../include/push_swap.h"
#include "../printf/ft_printf.h"

void	temporary_sort(int *pile_temporaire, int size)
{
	int	i;
	int	j;
	int	temporaire;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_temporaire[i] > pile_temporaire[j])
			{
				temporaire = pile_temporaire[i];
				pile_temporaire[i] = pile_temporaire[j];
				pile_temporaire[j] = temporaire;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_case_pile_a(t_piles *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		swap_a(three, 0);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three, 0);
		reverse_rotate_a(three, 0);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] < three->a[2])
		rotate_a(three, 0);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] > three->a[2])
	{
		swap_a(three, 0);
		rotate_a(three, 0);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
		reverse_rotate_a(three, 0);
}

int	sort(t_piles *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile, 0);
		else if (size == 3)
			three_numbers_case_pile_a(pile);
		else
			quicksort_pile_a(pile, size, 0);
	}
	return (0);
}

int	ft_push(t_piles *pile, int len, int push)
{
	if (push == 0)
		push_b(pile, 0);
	else
		push_a(pile, 0);
	len--;
	return (len);
}
