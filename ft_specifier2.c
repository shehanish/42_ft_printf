/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:08:19 by shkaruna          #+#    #+#             */
/*   Updated: 2024/01/25 16:37:18 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-n, count);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putchar(n % 10 + '0', count);
	}
	else
		ft_putchar(n + '0', count);
}

void	ft_unsignednbr(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_unsignednbr(n / 10, count);
	}
	ft_putchar((n % 10) + '0', count);
}

void	ft_hexadecimal(unsigned int n, int *count, char x_or_X)
{
	char	str[25];
	char	*num_base;
	int		i;

	if (x_or_X == 'x')
		num_base = "0123456789abcdef";
	else
		num_base = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	while (n != 0)
	{
		str[i] = num_base[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar(str[i], count);
	}
}
