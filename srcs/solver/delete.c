#include "solver.h"

void	solver_delete(t_solver *solver)
{
	if (!solver)
		return ;
	free(solver->last_line);
	free(solver->chrs);
	free(solver);
}
