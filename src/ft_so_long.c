#include "../includes/ft_so_long.h"

int	game(char **argv)
{
	t_program	*sl;
	int			status;

	sl = (t_program *) malloc(sizeof(t_program));
	if (sl == NULL)
	{
		ft_show_error("Malloc error\n");
		return (1);
	}
	status = ft_initialize_game(sl);
	if (status == -1)
	{
		ft_free_program(sl);
		return (1);
	}
	status = ft_parse_map(sl, argv[1]);
	if (status == -1)
	{
		ft_free_program(sl);
		return (1);
	}
	ft_display_program(sl);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_show_error("Invalid number of arguments\n");
		return (1);
	}
	else
		return (game(argv));
}
