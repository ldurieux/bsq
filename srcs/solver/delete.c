/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:23:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/03 21:23:46 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	solver_delete(t_solver *solver)
{
	if (!solver)
		return ;
	free(solver->last_line);
	free(solver->chrs);
	free(solver);
}
