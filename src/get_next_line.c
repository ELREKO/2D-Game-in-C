#include "../include/so_long.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_chrinstr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_chrinstr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_readbuf(int fd, char *storage)
{
	int		i_rid;
	char	*str_buffer;

	i_rid = 1;
	str_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buffer)
		return (ft_free(&storage));
	str_buffer[0] = '\0';
	while (i_rid > 0 && !ft_chrinstr(str_buffer, '\n'))
	{
		i_rid = read (fd, str_buffer, BUFFER_SIZE);
		if (i_rid > 0)
		{
			str_buffer[i_rid] = '\0';
			storage = ft_strjoin(storage, str_buffer);
		}
	}
	free(str_buffer);
	if (i_rid == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*str_storage = {0};
	char		*str_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str_storage && !ft_chrinstr(str_storage, '\n')) || !str_storage)
		str_storage = ft_readbuf (fd, str_storage);
	if (!str_storage)
		return (NULL);
	str_line = ft_new_line(str_storage);
	if (!str_line)
		return (ft_free(&str_storage));
	str_storage = ft_clean_storage(str_storage);
	return (str_line);
}
