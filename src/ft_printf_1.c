# include "../include/so_long.h"

static int	ft_flagcheck(size_t ui_count, const char *str_give, va_list ap);
static int	ft_inner_ceck(const char *str_give, size_t *ui_count,
		int i_len, va_list ap);
static int	ft_write(const char *str_give, va_list ap);

int	ft_printf(char *format, ...)
{
	va_list	ap;
	char	*str_give;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	str_give = ft_strdup(format);
	if (str_give != NULL)
	{
		va_start(ap, format);
		len = ft_write(str_give, ap);
		if (len == -1)
				return (-1);
		va_end(ap);
	}
	free(str_give);
	return (len);
}

static int	ft_flagcheck(size_t ui_count, const char *str_give, va_list ap)
{
	int	len;

	if (str_give[ui_count] == 'c')
		len = ft_printf_char(va_arg(ap, int));
	if (str_give[ui_count] == 's')
		len = ft_printf_string(va_arg(ap, char *));
	if (str_give[ui_count] == 'p')
		len = ft_printf_ptr(va_arg(ap, void *));
	if (str_give[ui_count] == 'd')
		len = ft_printf_int(va_arg(ap, int));
	if (str_give[ui_count] == 'i')
		len = ft_printf_int(va_arg(ap, int));
	if (str_give[ui_count] == 'u')
		len = ft_printf_uns_int(va_arg(ap, unsigned int));
	if (str_give[ui_count] == 'x')
		len = ft_printf_hex(va_arg(ap, unsigned int), 'x');
	if (str_give[ui_count] == 'X')
		len = ft_printf_hex(va_arg(ap, unsigned int), 'X');
	if (str_give[ui_count] == '%')
	{
		len = 1;
		write(1, "%", 1);
	}
	return (len);
}

static int	ft_inner_ceck(const char *str_give, size_t *ui_count,
		int i_len, va_list ap)
{	
	size_t	i_check_flags;

	i_check_flags = 0;
	if (str_give[*ui_count] == '\0')
		return (-1);
	while (i_check_flags < ft_strlen("cspdiuxX%"))
	{
		if (str_give[*ui_count] == "cspdiuxX%"[i_check_flags++])
		{
			i_len = ft_flagcheck(*ui_count, str_give, ap) + i_len;
			return (i_len);
		}
	}
	*ui_count = *ui_count - 1;
	write(1, "%", 1);
	return (i_len + 2);	
}

static int	ft_write(const char *str_give, va_list ap)
{
	size_t	ui_count;
	int		i_len;
	int		i_spec_write;

	ui_count = 0;
	i_len = 0;
	i_spec_write = 0;
	while (str_give[ui_count] != '\0')
	{
		while (str_give[ui_count] == '%')
		{
			ui_count++;
			i_spec_write++;
			i_len = ft_inner_ceck(str_give, &ui_count, i_len, ap);
			if (i_len == -1)
				return (-1);
			ui_count++;
		}
		if (str_give[ui_count] == '\0')
			break ;
		write (1, &str_give[ui_count++], 1);
	}
	return (ui_count + i_len - (i_spec_write * 2));
}


