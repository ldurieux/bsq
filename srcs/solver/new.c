/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:23:48 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/03 21:23:49 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_solver	*solver_new(char *chrs)
{
	t_solver	*res;

	res = malloc(sizeof(t_solver));
	if (!res)
		return (NULL);
	res->last_line = NULL;
	res->cur_line = (size_t)-1;
	res->best_point.x = 0;
	res->best_point.y = 0;
	res->best_point_size = 0;
	res->chrs = chrs;
	return (res);
}
