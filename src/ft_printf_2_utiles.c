# include "../include/so_long.h"

int	ft_printf_char(int arg)
{
	write(1, (char *)&arg, 1);
	return (1);
}

int	ft_printf_hex(unsigned int arg, char form)
{
	int		len;
	char	*base;

	if (form == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = write_out_nbr(arg, base);
	return (len);
}

int	ft_printf_uns_int(unsigned int arg)
{
	int		len;
	char	*base;

	base = "0123456789";
	len = write_out_nbr(arg, base);
	return (len);
}

int	ft_printf_int(int arg)
{
	int		len;
	char	*base;

	base = "0123456789";
	if (arg == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (arg < 0)
	{
		arg *= -1;
		write(1, "-", 1);
		len = 1 + write_out_nbr(arg, base);
	}
	else
		len = 0 + write_out_nbr(arg, base);
	return (len);
}

int	ft_printf_ptr(void *arg)
{
	int					len;
	unsigned long long	ptr_value;

	ptr_value = (unsigned long long)arg;
	if (!arg)
		return (ft_printf_string("(nil)"));
	write(1, "0x", 2);
	len = write_out_nbr(ptr_value, "0123456789abcdef");
	return (len + 2);
}
