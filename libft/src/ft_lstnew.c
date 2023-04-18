/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:07:29 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/15 12:43:45 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_child	*ft_lstnew(char **cmd)
{
	t_child	*new;

	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	return (new);
}
/*
int	main(int ac, char **av)
{
	t_list	*new;

	(void)ac;
	new = ft_lstnew((void *)av[1]);
	printf("%p\n", new->content);
	printf("%s\n", (char *)new->content);
}
*/
