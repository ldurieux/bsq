#include "bsq_b.h"

void	ft_bsq(int fd, char *argv)
{
    t_solver	*solver;
    int		line_count;
    int		ln;
    char	*line;

    solver = solver_new(ft_parse_chars(fd, &line_count));
    if (!solver)
	return (solver_delete(solver));
    if (!ft_mesure_line_slvraddline(fd, &ln))
	return (solver_delete(solver));
    line = malloc(ln + 1);
    if (!line)
	return (solver_delete(solver));
    while (line_count--)
	if (read(fd, line, ln + 1) < ln + 1 
		|| !ft_check(line) || !solver_add_line(solver, line))
	    return (free(line), solver_delete(solver));
    ln = open(path, O_RDONLY);
    if (ln != -1)
	solver_print_solution(solver, ln);
    return (free(line), solver_delete(solver));
}



    
    

    
