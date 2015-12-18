/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 19:11:26 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/02 22:56:41 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (alst || del)
	{
		tmp = *alst;
		while (tmp->next)
		{
			next = tmp->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next;
		}
		(*del)(tmp->content, tmp->content_size);
		*alst = NULL;
	}
}
