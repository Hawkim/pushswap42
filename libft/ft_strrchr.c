/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:09:41 by nal-haki          #+#    #+#             */
/*   Updated: 2024/06/12 15:41:19 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (len)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}
