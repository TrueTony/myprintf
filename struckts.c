/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:46:12 by ksenaida          #+#    #+#             */
/*   Updated: 2019/11/23 15:07:24 by ksenaida         ###   ########.fr       */
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
	list->widthofline = 0;
	list->widthofcontent = 0;
	list->base = 10;
	return (list);
}
