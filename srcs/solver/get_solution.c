/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:23:47 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/03 21:23:47 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_rect	solver_get_solution(t_solver *solver)
{
	t_rect	res;

	if (!solver)
		return ((t_rect){0, 0, 0, 0});
	res.x = solver->best_point.x - solver->best_point_size + 1;
	res.y = solver->best_point.y - solver->best_point_size + 1;
	res.width = solver->best_point_size;
	res.height = solver->best_point_size;
	return (res);
}
