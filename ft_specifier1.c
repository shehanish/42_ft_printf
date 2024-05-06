/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:17:30 by shkaruna          #+#    #+#             */
/*   Updated: 2024/01/25 16:48:09 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], count);
		i++;
	}
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_convert_pointer_to_hex(unsigned long int pointer, char *str)
{
	char	*num_base;
	int		i;

	num_base = "0123456789abcdef";
	i = 0;
	while (pointer != 0)
	{
		str[i] = num_base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	str[i] = '\0';
}

void	ft_pointer(unsigned long int pointer, int *count)
{
	char	str[40];
	int		i;

	if (!pointer)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	if (pointer == 0)
		ft_putchar('0', count);
	write(1, "0x", 2);
	*count += 2;
	ft_convert_pointer_to_hex(pointer, str);
	i = ft_strlen(str);
	while (i--)
	{
		ft_putchar(str[i], count);
	}
}
