/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nal-haki <nal-haki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:18:58 by nal-haki          #+#    #+#             */
/*   Updated: 2024/07/30 10:19:02 by nal-haki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

# define BUFFER_SIZE 42

/* push_swap_utils.c */
int		split_argv(char ***strs, char **argv, char *sep);
int		is_valid(char **strs);
int		is_sorted(t_list *stack);

/* instructions.c */
void	run(char *str, t_list **stack_1, t_list **stack_2, int x);

/* sort.c */
void	sort(t_list **stack);

/* sort_utils.c */
int		stack_min(t_list *stack);
int		stack_max(t_list *stack);
int		min(int a, int b);
int		count_rotate(int a, int b);

/* sort_big_utils.c */
int		stack_idx_minmax(t_list *stack, int num);
void	get_min_rotate(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	rotate_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	rotate_diff(t_list **stack_a, t_list **stack_b, int a, int b);

/* get_next_line.c */
char	*get_next_line(char **str);

#endif
