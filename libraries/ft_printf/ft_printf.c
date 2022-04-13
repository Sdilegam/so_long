/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:50:01 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/04/07 14:07:30 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_size	ft_check_flags(const char *string, int *flags)
{
	t_size	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '-')
			flags[0] = 1;
		else if (string[index] == '#')
			flags[1] = 1;
		else if (string[index] == '0')
			flags[2] = '0';
		else if (string[index] == ' ')
			flags[3] = 1;
		else if (string[index] == '+')
			flags[5] = 1;
		else
			break ;
		index++;
	}
	return (index);
}

int	ft_get_conv(char chr, va_list args, int *flags)
{
	if (chr == 'c')
		return (convert_char(va_arg(args, int), flags));
	if (chr == 's')
		return (convert_str(va_arg(args, char *), flags));
	if (chr == 'd' || chr == 'i')
		return (convert_int(va_arg(args, int), flags));
	if (chr == 'u')
		return (convert_uint(va_arg(args, unsigned int), flags));
	if (chr == 'x')
		return (convert_hexa(va_arg(args, unsigned int), L_HEX, flags));
	if (chr == 'X')
		return (convert_hexa(va_arg(args, unsigned int), U_HEX, flags));
	if (chr == 'p')
		return (convert_ptr(va_arg(args, unsigned long), L_HEX, flags));
	if (chr == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_count_modifiers(const char *string, int *flags)
{
	int	index;

	index = 0;
	index += ft_check_flags(string, flags);
	if (ft_isdigit(string[index]))
	{
		flags[6] = 0;
		while (ft_isdigit(string[index]))
			flags[6] = flags[6] * 10 + string[index++] - '0';
	}
	if (string[index] == '.')
	{
		flags[4] = 0;
		index++;
		while (ft_isdigit(string[index]))
			flags[4] = flags[4] * 10 + string[index++] - '0';
	}
	return (index);
}

void	reset_flags(int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = ' ';
	flags[3] = 0;
	flags[4] = -1;
	flags[5] = 0;
	flags[6] = -1;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	t_size	count;
	int		flags[7];

	count = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			reset_flags(flags);
			string += ft_count_modifiers(string, flags);
			count += ft_get_conv(*string++, args, flags);
		}
		else
			count += ft_putchar(*string++);
	}
	va_end(args);
	return (count);
}
