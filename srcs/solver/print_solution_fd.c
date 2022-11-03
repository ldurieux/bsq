#include "solver.h"

static void	skip_line(int fd)
{
	char	buf;

	while (read(fd, &buf, 1) <= 0 || buf == '\n')
		;
}

void	solver_print_solution_fd(t_solver *solver, int fd)
{
	t_rect	rect;
	t_point	pos;
	char	buf;

	if (!solver)
		return ;
	rect = solver_get_solution(solver);
	rect.width = rect.x + rect.width;
	rect.height = rect.y + rect.height;
	skip_line(fd);
	pos.y = (uint32_t)-1;
	while (++pos.y)
	{
		pos.x = (uint32_t)-1;
		while (++pos.x)
		{
			if (read(fd, &buf, 1) <= 0)
				return ;
			if (buf == '\n')
				break ;
			if (pos.x >= rect.x && pos.x < rect.width &&
				pos.y >= rect.y && pos.y < rect.height)
				write(STDOUT, solver->chrs + SOLUTION_IDX, 1);
			write(STDOUT, &buf, 1);
		}
		write(STDOUT, "\n", 1);
	}
}
