#include "../include/so_long.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str_ret;
	unsigned int i_count_str1;
	unsigned int i_count_str2;

	if (!str1)
	{
		str1 = malloc(sizeof(char) + 1);
		if (!str1)
			return (0);
		str1[0] = 0;
	}
	str_ret = malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str_ret)
		return (ft_free_str(&str1));
	i_count_str1 = -1;
	while (str1[++i_count_str1])
		str_ret[i_count_str1] = str1[i_count_str1];
	i_count_str2 = -1;
	while (str2[++i_count_str2])
		str_ret[i_count_str1 + i_count_str2] = str2[i_count_str2];
	str_ret[i_count_str1 + i_count_str2] = '\0';
	free(str1);
	return (str_ret);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i_count;

	i_count = 0;
	if (!str)
		return (0);
	while (str[i_count] != '\0')
		i_count++;
	return (i_count);
}

char	*ft_chrinstr(char *str, int chr)
{
	int	i_count;

	i_count = 0;
	while (str[i_count] != '\0')
	{
		if (str[i_count] == (char)chr)
			return (&((char *)str)[i_count]);
		i_count++;
	}
	if ((char)chr == '\0')
		return (&((char *)str)[i_count]);
	return (0);
}

char	*ft_substr(char *storage, unsigned int start, unsigned int len)
{
	unsigned int 	i_count;
	char	*str_ret;

	i_count = 0;
	if (!storage)
		return (0);
	if (start > ft_strlen(storage))
	{
		str_ret = malloc(sizeof(char) * (1));
		if (!str_ret)
			return (NULL);
		str_ret[0] = '\0';
		return (str_ret);
	}
	if (ft_strlen(storage) - start < len)
		len = ft_strlen(storage) - start;
	str_ret = malloc(sizeof(char) * (len + 1));
	if (!str_ret)
		return (NULL);
	while (start < ft_strlen(storage) && i_count < len && storage[start])
		str_ret[i_count++] = storage[start++];
	str_ret[i_count - 1] = '\0';
	return (str_ret);
}
