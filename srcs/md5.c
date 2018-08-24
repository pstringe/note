/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:51:18 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/22 18:30:19 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "openssl.h"

/*
**	initialized values to be used within the md5 algorithm	
*/

t_md5	*init_md5()
{
	t_md5 *m;

	m = ft_memalloc(sizeof(t_md5));
	return(m);
	
}

/*
**	md5 hashing algorithm
*/

void	md5(t_args *args)
{
	t_md5	*m;
	char	*block;
	
	//initialize shift amounts, constants and registers
	m = init_md5();
	//for each block
	while ((block = (char*)ft_dequeue(args->blocks)))
	{
		//break block into 4 16-bit words
		break_block(m, block);
	
		//display plain block	
		//ft_printf("%s\n", block);
		
		/*break blocks test
		int i;
		i = -1;
		while (++i < 16)
			ft_printf("%#010x ", m->words[i]);
		ft_putchar('\n');
		end test*/
	
		/*reverse test
		int j;
		i = -1;
		while (++i < 16)
		{
			j = 4;
			while (j >= 0)
				ft_putchar(m->words[i] >> ((--j) * 8));
		}
		ft_putstr("\n\n");
		end test*/	
		
		//if 0 <= i < 16
			// F = (b & c) | ((!b) & d)
			// g = i;
		//else if 16 <= i < 32
			// F = (d & b) | ((!d) and c)
			// g = (5 * i + 1) % 16
		//else if 32 <= i < 48
			// F = b ^ c ^ d
			// g = (3 * i + 5) % 16
		//else if 48 <= i < 64
			//F = c ^ (b | (!d))
			//g = (7 * i) % 16
		//computer the intermediate hash value
		//add the old hash value to the new hash value
	}
	
	//output
	//ft_printf("md5 trigger: %s\nmessage: %s", args->cmd->name, args->msg);
}
