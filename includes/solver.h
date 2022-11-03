#ifndef SOLVER_H
# define SOLVER_H

# include <stdlib.h>
# include <stdint.h>

typedef struct s_point
{
	uint32_t	x;
	uint32_t	y;
}	t_point;

typedef struct s_rect
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	width;
	uint32_t	height;
}	t_rect;

# define EMPTY_IDX 0
# define WALL_IDX 1
# define SOLUTION_IDX 2

typedef struct s_solver
{
	char	*last_line;
	t_point	best_point;
	char	*chrs;
}	t_solver;

t_solver	*solver_new(char *chrs);
t_rect		solver_get_solution(t_solver *solver);
void		solver_delete(t_solver *solver);

#endif // SOLVER_H
