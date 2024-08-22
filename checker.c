/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:18:30 by nal-haki          #+#    #+#             */
/*   Updated: 2024/07/30 10:18:33 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	ps_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static int	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse(char *str, t_list **stack_1, t_list **stack_2)
{
	int		len;
	int		(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ps_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && !f(str, "sa", 2))
		|| (len == 2 && !f(str, "ra", 2)))
		run(str, stack_1, NULL, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && !f(str, "sb", 2))
		|| (len == 2 && !f(str, "rb", 2)))
		run(str, stack_2, NULL, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && !f(str, "ss", 2))
		|| (len == 2 && !f(str, "pb", 2)) || (len == 2 && !f(str, "rr", 2)))
		run(str, stack_1, stack_2, -1);
	else if (len == 2 && !f(str, "pa", 2))
		run(str, stack_2, stack_1, -1);
	else
		return (ps_error());
	return (0);
}

static void	sort_check(t_list **stack_1)
{
	char		*cmd;
	t_list		*stack_2;
	static char	*str;

	stack_2 = NULL;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (parse(cmd, stack_1, &stack_2))
		{
			free(str);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (is_sorted(*stack_1) && !ft_lstsize(stack_2))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	int		len;
	char	**strs;
	t_list	*stack;

	if (argc > 1)
	{
		strs = NULL;
		len = split_argv(&strs, argv + 1, " ");
		if (!len || !is_valid(strs))
		{
			ps_free(strs);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		stack = NULL;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(strs[len]));
		sort_check(&stack);
		ft_lstclear(&stack, free);
		free(strs);
	}
	return (0);
}
