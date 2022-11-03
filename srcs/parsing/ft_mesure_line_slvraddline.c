#include "bsq_b.h"

int ft_mesure_line_slvraddline(int fd, int *ln_line, t_solver *solver)
{
	char    *line;

	line = ft_read_till_lnfd(fd);
	if (!line || !solver_add_line(solver, line))
		return (0);
	*ln_line = ft_strlen(*line);
	free(line);
	return (1);
}
