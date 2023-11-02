# include "../include/so_long.h"

static int	count_nbr(unsigned long long arg, unsigned long long base);

int	write_out_nbr(unsigned long long arg, char *base)
{
	char					ch;
	int						len;
	unsigned long long		base_len;

	base_len = ft_strlen(base);
	len = count_nbr(arg, base_len);
	while (arg >= base_len)
	{
		write_out_nbr(arg / base_len, base);
		arg = arg - ((arg / base_len) * base_len);
	}
	if (arg < base_len)
	{
		ch = base[arg];
		write(1, &ch, 1);
	}
	return (len);
}

int	ft_printf_string(char *arg)
{
	size_t	len;

	if (!arg)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(arg);
	write(1, arg, ft_strlen(arg));
	return (len);
}

static int	count_nbr(unsigned long long arg, unsigned long long base)
{
	int	count;

	count = 0;
	while (arg > base)
	{
		arg = arg / base;
		count++;
	}
	if (arg == base)
		count++;
	return (count + 1);
}