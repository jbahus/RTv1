/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 22:41:07 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/08 23:06:32 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	while (n--)
	{
		str1 = (unsigned char*)s1;
		str2 = (unsigned char*)s2;
		if (*str1 != *str2)
			return (*str1 - *str2);
		s1++;
		s2++;
	}
	return (0);
}
