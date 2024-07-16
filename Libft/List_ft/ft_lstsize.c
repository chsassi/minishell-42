/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:01:42 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/20 20:56:51 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
/*
int main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		len;
	int		i =	1;
	int		j = 2;
	int		k = 3;

	node1 = ft_lstnew(&i);
	node2 = ft_lstnew(&j);
	node3 = ft_lstnew(&k);
	node1->next = node2;
	node2->next = node3;
	len = ft_lstsize(node1);
	printf("Lunghezza: %d", len);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/