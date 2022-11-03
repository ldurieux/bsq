#include "solver.h"

t_solver	*solver_new(char *chrs)
{
	t_solver	*res;

	res = malloc(sizeof(t_solver));
	if (!res)
		return (NULL);
	res->last_line = NULL;
	res->best_point.x = 0;
	res->best_point.y = 0;
	res->chrs = chrs;
	return (res);
}
