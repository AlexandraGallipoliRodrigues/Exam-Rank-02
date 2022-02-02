/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:53:59 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/02 17:14:08 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
#include <stdlib.h>

int	ft_c_type(va_list ap)
{
	int c = va_arg(ap, int);
	int num = write(1, &c, 1);
	return (num);
}

int	ft_s_type(va_list ap)
{
	char *s = va_arg(ap, char *);
	int num = 0;
	int i = 0;

	if (!s)
	{
		num += write(1, "(null)", 6);
		return (num);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		num++;
		i++;
	}
	return (num);
}

void	ft_putnbr_base(unsigned int x, char *base, int *num, int len)
{
	if (x < 0)
	{
		*num += write(1, "-", 1);
		ft_putnbr_base(x * -1, base, num, len);
	}
	if (x >= len)
		ft_putnbr_base(x/len, base, num, len);
	*num += write(1, &base[x % len], 1);

}
void	ft_putnbr_base_p(unsigned long int x, char *base, int *num, int len)
{
	if (x < 0)
	{
		*num += write(1, "-", 1);
		ft_putnbr_base(x * -1, base, num, len);
	}
	if (x >= len)
		ft_putnbr_base(x/len, base, num, len);
	*num += write(1, &base[x % len], 1);

}
void	ft_putnbr_base_i(int x, char *base, int *num, int len)
{
	if (x == -2147483648)
		*num = write(1, "-2147483648", 1);
	if (x < 0)
	{
		*num += write(1, "-", 1);
		ft_putnbr_base(x * -1, base, num, len);
	}
	if (x >= len)
		ft_putnbr_base(x/len, base, num, len);
	*num += write(1, &base[x % len], 1);

}
int ft_u_type(va_list ap)
{
	unsigned int u = va_arg(ap, unsigned int);
	int num = 0;
	int len = 10;

	ft_putnbr_base(u, "0123456789", &num, len);
	return (num);
}
int ft_i_type(va_list ap)
{
	int i = va_arg(ap, int);
	int num = 0;
	int len = 10;

	ft_putnbr_base_i(i, "0123456789", &num, 10);
	return (num);
}
int	ft_x_type(va_list ap)
{
	unsigned int x = va_arg(ap, unsigned int);
	int num = 0;
	int base_len = 16;

	ft_putnbr_base(x, "0123456789abcdef", &num, 16);
	return (num);
}
int	ft_xx_type(va_list ap)
{
	unsigned int x = va_arg(ap, unsigned int);
	int num = 0;
	int base_len = 16;

	ft_putnbr_base(x, "0123456789ABCDEF", &num, 16);
	return (num);
}
int ft_p_type(va_list ap)
{
	unsigned long int p = va_arg(ap, unsigned long int);
	int num = 0;
	int len = 16;

	ft_putnbr_base_p(p, "0123456789ABCDEF", &num, len);
	return (num);
}
int ft_printf(const char *format, ...)
{
	int i = 0;
	int num = 0;
	va_list ap;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				num += ft_c_type(ap);
			if (format[i] == 's')
				num += ft_s_type(ap);
			if (format[i] == 'x')
				num += ft_x_type(ap);
			if (format[i] == 'X')
				num += ft_xx_type(ap);
			if (format[i] == 'i' || format[i] == 'd')
				num += ft_i_type(ap);
			if (format[i] == 'u')
				num += ft_u_type(ap);
			if (format[i] == 'p')
				num += ft_p_type(ap);
			if (format[i] == '%')
				num += write(1, "%", 1);
		}
		else
			num += write(1, &format[i], 1);
		i++;
	}
	return (num);
}
int main()
{
    printf("----> Mio\n");
    printf("\n%d\n", ft_printf("holala %d %s %x", -12, "42\0", 12));
    printf("\n----> Original\n");
    printf("\n%d\n", printf("holala %d %s %x", -12, "42\0", 12));
    return(0);
}

