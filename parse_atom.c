/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 16:55:05 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/31 16:55:20 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

double		parse_atom(char **expr)
{
	BOOL	neg;
	double	num;

	while (**expr == ' ')
		(*expr)++;
	neg = FALSE;
	if (**expr == '-')
	{
		neg = TRUE;
		(*expr)++;
		while (**expr == ' ')
			(*expr)++;
	}
	if (**expr == '+')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		num = parse_summands(expr);
		(*expr)++;
		return (neg) ? (-num) : (num);
	}
	num = ft_atoi(*expr);
	while (**expr <= 57 && **expr >= 48)
		(*expr)++;
	return (neg) ? (-num) : (num);
}
