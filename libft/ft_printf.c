/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albarrei <albarrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:33:09 by albarrei          #+#    #+#             */
/*   Updated: 2025/03/11 11:50:54 by albarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whatistheformathere(const char *str, int count, va_list args)
{
	if (*str == 'c')
		count = ft_putchar(va_arg(args, int), count);
	if (*str == 's')
		count += ft_putstr(va_arg(args, char *));
	if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (*str == 'x' || *str == 'X')
		count += ft_puthex(*str, va_arg(args, unsigned int));
	if (*str == 'p')
		count += ft_putpointer(va_arg(args, void *));
	if (*str == '%')
	{
		write(1, "%", 1);
		count++;
	}
	if (*str == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	if (!str || str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count = ft_whatistheformathere(str, count, args);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	int	count =	ft_printf(NULL);
	ft_printf("Count mío: %i\n", count);
	count = printf(NULL);
	printf("Count original: %i", count);
}*/
