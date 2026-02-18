/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 01:00:08 by albarrei          #+#    #+#             */
/*   Updated: 2025/01/09 09:16:02 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count = 1;
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count++;
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
		count = ft_putunbr(n / 10);
	count++;
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count);
}

int	ft_puthex(const char str, unsigned int n)
{
	static char	hex[] = "0123456789abcdef";
	static char	uphex[] = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (n > 15)
		count += ft_puthex(str, n / 16);
	count++;
	if (str == 'x')
		write(1, &hex[n % 16], 1);
	else
		write(1, &uphex[n % 16], 1);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long	address;
	static char		*hex = "0123456789abcdef";
	char			buffer[16];
	int				count;
	int				i;

	address = (unsigned long)ptr;
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = 0;
	while (address)
	{
		buffer[i++] = hex[address % 16];
		address /= 16;
	}
	count = write(1, "0x", 2);
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}
