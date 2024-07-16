/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:39:35 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/21 11:53:50 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
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

int main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		i = 1;
	int		j = 2;
	int		k = 3;

	node1 = (ft_lstnew(&i));
	node2 = (ft_lstnew(&j));
	node3 = (ft_lstnew(&k));
	head = node1;
	node1->next = node2;
	ft_lstadd_back(&head, node3);
	print(head);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/