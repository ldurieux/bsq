/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:23:50 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/03 21:23:51 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static void	skip_line(int fd)
{
	char	buf;

	while (read(fd, &buf, 1) == 1 && buf != '\n')
		;
}

static void	init(t_solver *solver, int fd, t_rect *rect, t_point *pos)
{
	*rect = solver_get_solution(solver);
	rect->width = rect->x + rect->width;
	rect->height = rect->y + rect->height;
	skip_line(fd);
	pos->y = (uint32_t)-1;
}

void	solver_print_solution_fd(t_solver *solver, int fd)
{
	t_rect	rect;
	t_point	pos;
	char	buf;

	if (!solver)
		return ;
	init(solver, fd, &rect, &pos);
	while (++pos.y != -1)
	{
		pos.x = (uint32_t) - 1;
		while (++pos.x != -1)
		{
			if (read(fd, &buf, 1) <= 0)
				return ;
			if (buf == '\n')
				break ;
			if (pos.x >= rect.x && pos.x < rect.width
				&& pos.y >= rect.y && pos.y < rect.height)
				write(STDOUT, solver->chrs + SOLUTION_IDX, 1);
			else
				write(STDOUT, &buf, 1);
		}
		write(STDOUT, "\n", 1);
	}
}
