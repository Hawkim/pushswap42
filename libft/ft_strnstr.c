/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:15:19 by nal-haki          #+#    #+#             */
/*   Updated: 2024/06/14 19:59:43 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!little[0])
		return ((char *)big);
	while ((len && *big))
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] && i < len)
			{
				if (big[i] != little[i])
					break ;
				i++;
			}
			if (!little[i])
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
