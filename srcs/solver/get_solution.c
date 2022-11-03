#include "solver.h"

t_rect	solver_get_solution(t_solver *solver)
{
	t_rect	res;

	if (!solver)
		return ((t_rect){0, 0, 0, 0});
	res.x = solver->best_point.x - solver->best_point_size;
	res.y = solver->best_point.y - solver->best_point_size;
	res.width = solver->best_point_size;
	res.height = solver->best_point_size;
	return (res);
}
