/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:53:06 by shkaruna          #+#    #+#             */
/*   Updated: 2024/01/25 16:57:45 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_conversions(char c, va_list *args, int *count, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), count);
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), count);
	else if (c == 'u')
		ft_unsignednbr(va_arg(*args, unsigned int), count);
	else if (c == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), count, 'X');
	else if (c == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), count, 'x');
	else if (c == '%')
		ft_putchar('%', count);
	else
		*i -= 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_conversions(format[i], &args, &count, &i);
			i++;
		}
		else
		{
			ft_putchar((char)format[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("char: %c\n", 'g');
// 	printf("char: %c\n", 'g');
// 	printf("\n");
// 	ft_printf("string: %s\n", "hbjhuir");
// 	printf("string: %s\n", "hbjhuir");
// 	printf("\n");
// 	ft_printf("int: %i\n", -16434);
// 	printf("int: %i\n", -16434);
// 	printf("\n");
// 	ft_printf("decimal: %d\n", 16434);
// 	printf("decimal: %d\n", 16434);
// 	printf("\n");
// 	ft_printf("hex lower: %x\n", 17);
// 	printf("hex lower: %x\n", 17);
// 	printf("\n");
// 	ft_printf("hex upper: %X\n", 17);
// 	printf("hex upper: %X\n", 17);
// 	printf("\n");
// 	ft_printf("hex pointer: %p\n", (void *)13);
// 	printf("hex pointer: %p\n", (void *)13);
// 	printf("\n");
// 	ft_printf("unsigned in: %u\n", 67243);
// 	printf("unsigned in: %u\n", 67243);
// 	printf("\n");
// 	ft_printf("percent: %%\n");
// 	printf("percent: %%\n");
// 	return (0);
// }
