/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:14:58 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/23 13:49:31 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
int main(void)
{
	t_list 	*node1;
	t_list 	*node2;
	t_list 	*node3;
	t_list	*result;
	int	i = 1;
	int j = 2;
	int k = 3;
	node1 = ft_lstnew(&i);
	node2 = ft_lstnew(&j);
	node3 = ft_lstnew(&k);
	node1->next = node2;
	node2->next = node3;
	result = ft_lstlast(node1);
	printf("Contentuto ultimo nodo: %d", *((int *)result->content));
	free(node1);
	free(node2);
	free(node3);
	return(0);
}*/