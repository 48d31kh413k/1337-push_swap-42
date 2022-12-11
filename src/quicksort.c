
#include "../include/push_swap.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	quicksort_three_pile_a_and_b(t_piles *pile, int len)
{
	if (len == 3 && pile->size_a == 3)
		three_numbers_case_pile_a(pile);
	else if (len == 2)
	{
		if (pile->a[0] > pile->a[1])
			swap_a(pile, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(pile->a[0] < pile->a[1]
				&& pile->a[1] < pile->a[2]))
		{
			if (len == 3 && pile->a[0] > pile->a[1] && pile->a[2])
				swap_a(pile, 0);
			else if (len == 3 && !(pile->a[2] > pile->a[0]
					&& pile->a[2] > pile->a[1]))
				len = ft_push(pile, len, 0);
			else if (pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (len++)
				push_a(pile, 0);
		}
	}
}

int	sort_three_b(t_piles *pile, int len)
{
	if (len == 1)
		push_a(pile, 0);
	else if (len == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile, 0);
		while (len--)
			push_a(pile, 0);
	}
	else if (len == 3)
	{
		while (len || !(pile->a[0] < pile->a[1] && pile->a[1] < pile->a[2]))
		{
			if (len == 1 && pile->a[0] > pile->a[1])
				swap_a(pile, 0);
			else if (len == 1 || (len >= 2 && pile->b[0] > pile->b[1])
				|| (len == 3 && pile->b[0] > pile->b[2]))
				len = ft_push(pile, len, 1);
			else
				swap_b(pile, 0);
		}
	}
	return (0);
}

int	mediane_of_numbers(int *pivot, int *pile, int size)
{
	int		*temporaire_pile;
	int		i;

	temporaire_pile = (int *)malloc(size * sizeof(int));
	if (!temporaire_pile)
		return (0);
	i = 0;
	while (i < size)
	{
		temporaire_pile[i] = pile[i];
		i++;
	}
	temporary_sort(temporaire_pile, size);
	*pivot = temporaire_pile[size / 2];
	free(temporaire_pile);
	return (1);
}

int	quicksort_pile_a(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_three_pile_a_and_b(pile, len);
		return (1);
	}
	//if (!count_r && !mediane_of_numbers(&pivot, pile->a, len))
	if (!mediane_of_numbers(&pivot, pile->a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (pile->a[0] < pivot && (len--))
			push_b(pile, 0);
		else if (++count_r)
			rotate_a(pile, 0);
	}
	while (numbers / 2 + numbers % 2 != pile->size_a && count_r--)
		reverse_rotate_a(pile, 0);
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
	return (1);
}

int	quicksort_pile_b(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	//if (!count_r && check_sorted(pile->b, len, 1) == 1)
	if (check_sorted(pile->b, len, 1) == 1)
		while (len--)
			push_a(pile, 0);
	if (len <= 3)
	{
		sort_three_b(pile, len);
		return (1);
	}
	numbers = len;
	if (!mediane_of_numbers(&pivot, pile->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (pile->b[0] >= pivot && len--)
			push_a(pile, 0);
		else if (++count_r)
			rotate_b(pile, 0);
	}
	while (numbers / 2 != pile->size_b && count_r--)
		reverse_rotate_b(pile, 0);
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
}
