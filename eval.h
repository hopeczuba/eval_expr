/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 17:00:38 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/31 17:00:40 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H
# include <stdlib.h>
# include <unistd.h>
# define BOOL int
# define TRUE 1
# define FALSE 0

int			eval_expr(char *expr);
double		parse_atom(char **expr);
double		parse_factors(char **expr);
double		parse_summands(char **expr);
int			ft_atoi(char *str);
void		ft_putchar(char c);
void		ft_putnbr(int nb);

#endif
