#include "../includes/ft_so_long.h"

void	ft_show_error(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
}

void	ft_print_score(t_program *sl)
{
	ft_putstr_fd("SCORE: ", 1);
	ft_putnbr_fd(sl->game.moves, 1);
	ft_putstr_fd("\n", 1);
}
