/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha-256.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:54:29 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/22 18:29:42 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "openssl.h"

/*
**	sha-256 hashing algorithm
*/

void	sha(t_args *args)
{
	ft_printf("sha-256 trigger: %s\nmessage: %s", args->cmd->name, args->msg);
}


