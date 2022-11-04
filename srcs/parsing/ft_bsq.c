#include "bsq_b.h"

static int ft_check(char *str, int ln, t_solver *solv)
{
	char	empty;
	char	wall;

	empty = solv->chrs[EMPTY_IDX];
	wall = solv->chrs[WALL_IDX];
	while (ln--)
	{
		if (*str != empty && *str != wall)
			return (0);
		str++;
	}
	return (*str == '\n');
}

void	ft_bsq(int fd, char *path)
{
	t_solver	*solver;
	int		line_count;
	int		ln;
	char	*line;

	solver = solver_new(ft_parse_chars(fd, &line_count));
	if (!solver)
		return (solver_delete(solver));
	if (!ft_mesure_line_slvraddline(fd, &ln, solver))
		return (solver_delete(solver));
	line = malloc(ln + 1);
	if (!line)
		return (solver_delete(solver));
	line_count--;
	while (line_count--)
	{
		if (read(fd, line, ln + 1) < ln + 1)
			return (free(line), solver_delete(solver));
		if (!ft_check(line, ln, solver))
			return (free(line), solver_delete(solver));
		if (!solver_add_line(solver, line))
			return (free(line), solver_delete(solver));
	}
	fd = open(path, O_RDONLY);
	if (fd != -1)
		solver_print_solution_fd(solver, fd);
	return (free(line), solver_delete(solver));
}
