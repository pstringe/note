/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:40:00 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/23 09:26:25 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "openssl.h"

/*
** breaks block into 32bit ints
*/

void	break_block(t_md5 *m, char *block)
{
	int i; //word count;
	int	j; //block index;
	int k; //limit;
	int	l; //shift;
	
	j = -1;
	i = -1;
	k = 4;
	ft_bzero(m->words, 64);
	while (++i < 16)
	{
		l = 4;
		while (++j < k)
			m->words[i] |= ((block[++j]) << ((--l) * 8));
		j--;
		k += 4;
	}
}

/*
**	retrieve the plain-text input
*/

void	get_msg(t_args *args, int idx, char **argv, int argc)
{
	int 	fd;
	char 	*line;
	char	*tmp;

	fd = 0;
	if ((fd = open(argv[idx], O_RDONLY)) >= 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			tmp = args->msg ? ft_strdup(args->msg) : NULL;
			if (args->msg)
				free(args->msg);
			args->msg = ft_strjoin(tmp, line);
			if (line)
				free(line);
		}
	}
	else if ((fd = open(0, O_RDONLY)) >= 0)
	{
		get_next_line(fd, &line);
		args->msg = ft_strdup(line);
		free(line);
	}
	else if (idx < argc && argv[idx])
		args->msg = ft_strdup(argv[idx]);
	else
		ft_printf("no argument\n");
}

/*
**	perhaps I'll try padding the msg before breaking it into blocks
*/

void	pad_msg(t_args *args)
{
	int 	l;
	int 	r;
	char 	*tmp;
	t_pad	p;

	if (!((l = ft_strlen(args->msg)) % 64))
		return;
	r = l % 64;
	tmp = ft_strnew(l + r);
	ft_memcpy(tmp, args->msg, l);
	p = 
}

/*
**	split the message into 512bit (64 byte blocks) and pad up to 48bits
**	with the last 64 bits representing the length of the original message
**	establish length of original message
** 	establish the expected number of complete blocks which do not require padding
**	establish the remaining number of characters after the last complete block which must be padded into a complete block
**	this loop will execute, if and only if there are enough characters to form at least one complete block.
**	copy 64 bytes from the msg text to a block
**	enque a copy of this block
**	increment the index by the number of copied bytes
**	zero out the block
**	copy the remaining number of bytes in the msg text over to bloc
**	increment i by the remaining number of bytes
**	set j to the remaining no of bytes
**	I append a bit to the end of the msg text by ORing it against that index
**	I pad the block with null characters until the index is 64bits shy of a complete block
**	I use the last 64 bits to represent the original length of the msg
**	ft_bzero(&block[j], 8);
**	for each of the remaining 8 bytes, on the block,
**
** isolate the appropriate bits from the total length starting with the most significant,
** shift them to the least significant place value, and OR them against the current byte
** in the block
**
**	initialize the queue in the event there was <= 1 blocks worth of text
*/

void	get_blocks(t_args *args)
{
	uint64_t	len;
	int 		blocks;
	int	 		remainder;
	char		block[65];
	t_pad		p;

	block[64] = '\0'; 
	len = ft_strlen(args->msg);
	blocks = len / 64;
	remainder = len % 64;
	p.msg_idx = 0;
	
	while (blocks-- > 0)
	{
		ft_memcpy(block, args->msg + p.msg_idx, 64);
		if (!args->blocks)
			args->blocks = ft_queuenw(ft_strdup(block), 64);
		else
			ft_enqueue(args->blocks, ft_strdup(block), 64);
		p.msg_idx += 64;
	}
	
	ft_bzero(block, 64);
	ft_memcpy(block, args->msg + p.msg_idx, remainder);
	p.msg_idx += remainder;
	p.blk_idx = remainder;
	block[p.blk_idx] |= (1 << 7);

	while (++p.blk_idx < 64 - 8)
		block[p.blk_idx] = '\0';
	p.bit_shft = 8;
	p.nrm_shft = 8;
	
	while(p.blk_idx < 64 && p.bit_shft >= 0)
		block[p.blk_idx++] |= (((0xff << ((--p.bit_shft) * 8)) & len) >> (--p.nrm_shft) * 8);
	
	if (!args->blocks)
		args->blocks = ft_queuenw(ft_strdup(block), 64 + 1);
	else
		ft_enqueue(args->blocks, ft_strdup(block), 64);
}

