/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:57:56 by artperez          #+#    #+#             */
/*   Updated: 2024/11/15 09:31:02 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list	**lst;
	t_list	n1;
	t_list	n2;
	t_list	n0;
	
	*lst = &n1;
	n1.next = &n2;
	n2.next = NULL;
	ft_lstadd_front(lst, &n0))
	printf("%s", ;
}*/