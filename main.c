#include "bsq_b.h"

int main(int argc, char **argv)
{
	int	fd;

//	if (argc == 1)
//		ft_bsq_stdin();
	argv++;
	while (argc-- != 1)
	{
		fd = open(*argv, O_RDONLY);
		if (fd != -1)
		{
			ft_putstr_fd("error can't read the file path :", 1);
			ft_putendl_fd(*argv, 1);
			argv++;
			continue;
		}
		ft_bsq(fd, *argv);
		close(fd);
		argv++;
	}
	return (0);
}

