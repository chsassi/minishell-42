/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:29:03 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/22 16:09:54 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
void	print(t_list *lst)
{
	while (lst)
	{
		printf(" <%d> ", *((int *)lst->content));
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		i = 1;
	int		j = 2;
	int		k = 3;

	node1 = ft_lstnew(&i);
	node2 = ft_lstnew(&j);
	node3 = ft_lstnew(&k);
	head = node1;
	node1->next = node2;
	print(head);
	printf("\n");
	ft_lstadd_front(&head, node3);
	print(head);
	free(node1);
	free(node2);
	free(node3);
	return(0);
}*/