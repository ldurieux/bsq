#ifndef BSQ_B_H
# define BSQ_B_H

# include <fcntl.h>
# include <unistd.h>

# include "libft.h"
# include "solver.h"

char	*ft_read_chars(int fd, int *lncount);
char	*ft_parse_chars(int fd, int *lncount);

#ifndef
