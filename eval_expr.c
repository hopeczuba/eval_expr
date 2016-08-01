/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 16:55:42 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/31 16:55:56 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

double		modulus(double n1, double n2)
{
	int		int_n1;
	int		int_n2;

	int_n1 = n1;
	int_n2 = n2;
	return (int_n1 % int_n2);
}

double		parse_factors(char **expr)
{
	double	n1;
	double	n2;
	char	op;

	n1 = parse_atom(expr);
	while (TRUE)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '/' && op != '*' && op != '%')
			return (n1);
		(*expr)++;
		n2 = parse_atom(expr);
		if (op == '/')
			n1 /= n2;
		else if (op == '*')
			n1 *= n2;
		else
			n1 = modulus(n1, n2);
	}
}

double		parse_summands(char **expr)
{
	double	n1;
	double	n2;
	char	op;

	n1 = parse_factors(expr);
	while (TRUE)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '-' && op != '+')
			return (n1);
		(*expr)++;
		n2 = parse_factors(expr);
		if (op == '-')
			n1 -= n2;
		else
			n1 += n2;
	}
}

int			eval_expr(char *expr)
{
	return (parse_summands(&expr));
}
