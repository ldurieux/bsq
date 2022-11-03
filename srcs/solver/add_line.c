#include "solver.h"

static int	first_line(t_solver *solver, char *line)
{
	size_t	idx;

	solver->last_line = malloc(sizeof(uint32_t) * ft_strlen(line));
	if (!solver->last_line)
		return (0);
	idx = (size_t)-1;
	while (line[++idx])
		solver->last_line[idx] = line[idx] == solver->chrs[WALL_IDX];
	return (1);
}

void	solver_add_line(t_solver *solver, char *line)
{
	size_t	idx;
	char	wall;

	if (!solver)
		return ;
	if (!solver->last_line)
		return (first_line(solver, line));
	wall = solver->chrs[WALL_IDX];
	idx = (size_t)0;
	solver->last_line[0] = (line[idx] == wall) * solver->last_line[0];
	while (line[++idx])
	{
		if (line[idx] == wall)
			solver->last_line[idx] = 0;
		else
		{
			solver->last_line[idx] = ft_min(solver->last_line[idx - 1],
					solver->last_line[idx]) * (line[idx] != wall);
		}
	}
	return (1);
}
