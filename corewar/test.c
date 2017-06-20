#include "libft.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*cham;
	int		fd;
	int		i;
	unsigned char	*buf;

	fd = open(av[1], O_RDONLY);
	buf = ft_memalloc(9);
	while ((r = read(fd, buf, 8)) > 0)
	{

	}
	printf("%x ", buf);
	close(fd);
	return (0);
}
