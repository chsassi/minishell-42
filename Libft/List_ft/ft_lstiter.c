/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:08:23 by brulutaj          #+#    #+#             */
/*   Updated: 2023/11/23 14:25:03 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	if (!p)
		return ;
	while (p)
	{
		f(p->content);
		p = p->next;
	}
}
/*
void	f(void *i)
{
	*(int *)i = *(int *)i + 1;
}

void	print(t_list *lst)
{
	while(lst)
	{
		printf ("<%d>", *(int *)lst->content);
		lst = lst->next;
	}
}

int main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		i = 1;
	int		j = 2;
	int		k = 3;

	node1 = ft_lstnew(&i);
	node2 = ft_lstnew(&j);
	node3 = ft_lstnew(&k);
	node1->next = node2;
	node2->next = node3;
	print(node1);
	printf("\n");
	ft_lstiter(node2, f);
	print(node1);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/