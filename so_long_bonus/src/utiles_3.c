#include "../include/so_long.h"

char	*ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}