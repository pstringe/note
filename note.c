/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:55:17 by pstringe          #+#    #+#             */
/*   Updated: 2018/08/23 18:11:04 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "note.h"

struct	input
{
	int		options;
	char 	*text;
}		input;

void	parse(int argc, char **argv)
{
}

int		open_task(tsk_lst *task_list, )
{

}

int		execute(*f)()[NO_OF_FUNCS] = {
	{"open", open_task},
	{"close", close_task},
	{"queue", queue_task},
	{"rm", remove_task}
}

int 	main(int argc, char *argv)
{
	input	args;

	if (!(args = parse(argc, argv)))
		return (usage());
	execute[args.func](args);
	return (0);
}
