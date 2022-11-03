#include "bsq_b.h"

void	ft_bsq(int fd)
{
    t_solver	*solver;
    int		*ln_count;

    solver = solver_new(ft_parse_chars(fd, lncount));
    
