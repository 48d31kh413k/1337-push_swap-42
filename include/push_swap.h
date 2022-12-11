#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_piles;

void	push_swap(char **av);
int		push_swap_strlen(char **av);
void	error_detected(int *pile);
int		push_swap_atoi(char *str, int *pile);
void	check_doubles(int *pile, int size);
//Instructions
void	swap_a(t_piles *pile, int bonus);
void	swap_b(t_piles *pile, int bonus);
void	swap_s(t_piles *pile, int bonus);
void	rotate_a(t_piles *pile, int bonus);
void	rotate_b(t_piles *pile, int bonus);
void	rotate_r(t_piles *pile, int bonus);
void	reverse_rotate_a(t_piles *pile, int bonus);
void	reverse_rotate_b(t_piles *pile, int bonus);
void	reverse_rotate_r(t_piles *pile, int bonus);
void	push_b(t_piles *pile, int bonus);
void	push_a(t_piles *pile, int bonus);
//Sort
int		sort(t_piles *pile, int size);
int		check_sorted(int *pile, int size, int order);
void	three_numbers_case_pile_a(t_piles *three);
void	temporary_sort(int *pile_temporaire, int size);
//Quicksort
int		quicksort_pile_a(t_piles *pile, int len, int count_r);
int		quicksort_pile_b(t_piles *pile, int len, int count_r);
void	quicksort_three_pile_a_and_b(t_piles *pile, int len);
int		sort_three_b(t_piles *pile, int len);
int		ft_push(t_piles *pile, int len, int pb);
int		mediane_of_numbers(int *pivot, int *pile, int size);
//Bonus
void	read_from_stdin(t_piles *pile);
int		*c_errors(char **av);
void	exec_instruction(t_piles *pile, char *instruction);
void	free_error(t_piles *pile, int choix);
#endif
