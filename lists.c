/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:46:12 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/21 19:02:47 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_printf	*newlist_with_printf()
{
	t_printf	*list;

	list = (t_printf*)malloc(sizeof(t_printf));
	list->flag = 'Q';
	list->width = 0;
	list->presicion = 0;
	list->length = NULL;
	list->type = 'Q';
	return (list);
}
