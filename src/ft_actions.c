#include "../includes/ft_so_long.h"

void	ft_lost_game(t_program *sl)
{
	ft_putstr_fd("Enemy caught you and you lost! See you again!\n", 1);
	ft_free_enemies_pos(sl, sl->game.enemies - 1);
	ft_free_map(sl, sl->game.height - 1);
	ft_free_program(sl);
	exit(0);
}

void	ft_collect_collectibles(t_program *sl, int x, int y)
{
	if (sl->game.map[x][y] == COLLECTIBLE)
	{
		sl->game.collectibles--;
		sl->game.map[x][y] = SPACE;
	}
}

void	ft_check_exit(t_program *sl, int x, int y)
{
	if (sl->game.map[x][y] == EXIT)
	{
		if (sl->game.collectibles == 0)
		{
			sl->game.moves++;
			ft_putstr_fd("Congratulations, you won! ", 1);
			ft_print_score(sl);
			ft_putstr_fd("See you again!\n", 1);
			ft_free_enemies_pos(sl, sl->game.enemies - 1);
			ft_free_map(sl, sl->game.height - 1);
			ft_free_program(sl);
			exit(0);
		}
	}
}

int	ft_check_enemy(t_program *sl, int x, int y)
{
	int	i;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < sl->game.enemies)
	{
		enemy_x = (*sl->game.enemies_pos[i]).x;
		enemy_y = (*sl->game.enemies_pos[i]).y;
		if (x == enemy_x && y == enemy_y)
			return (1);
		i++;
	}
	return (-1);
}
