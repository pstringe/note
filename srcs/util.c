/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:49:09 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/22 18:28:11 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "openssl.h"

/*
**	just a test function to print the contents of the block queue
*/

void	print_blocks(t_args *args)
{
	int 	i;
	int		j;
	t_list	*tmp;
	char	*block;
	
	tmp = args->blocks->head;
	i = -1;
	while (tmp)
	{
		block = (char*)tmp->content;
		ft_printf("block %d:\n", ++i);
		j = -1;	
		while (++j < 65)
			ft_printf("%c ", block[j] < 41 ? '.' : block[j]);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

