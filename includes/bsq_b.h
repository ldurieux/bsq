#ifndef BSQ_B_H
# define BSQ_B_H

# include <fcntl.h>
# include <unistd.h>

# include "libft.h"
# include "solver.h"

char	*ft_read_till_lnfd(int fd);
char	*ft_parse_chars(int fd, int *lncount);
void	ft_bsq(int fd, char *argv);
int	ft_mesure_line_slvraddline(char **line, int fd, int *ln_line, t_solver * solver)

#endif
