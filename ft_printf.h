/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:20:46 by shkaruna          #+#    #+#             */
/*   Updated: 2024/01/25 16:44:02 by shkaruna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putnbr(int n, int *count);
void	ft_hexadecimal(unsigned int n, int *count, char x_or_X);
void	ft_unsignednbr(unsigned int n, int *count);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_pointer(unsigned long int pointer, int *count);
int		ft_printf(const char *format, ...);

#endif