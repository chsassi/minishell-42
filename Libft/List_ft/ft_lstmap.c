/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:28:43 by brulutaj          #+#    #+#             */
/*   Updated: 2024/01/02 16:21:53 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nn;
	t_list	*nl;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	nl = NULL;
	while (lst)
	{
		c = f(lst->content);
		nn = ft_lstnew(c);
		if (!nn)
		{
			del(c);
			ft_lstclear(&nl, del);
			return (nl);
		}
		ft_lstadd_back(&nl, nn);
		lst = lst->next;
	}
	return (nl);
}
/*
void	*f(void *i)
{
	int	*j = malloc(sizeof(int));
	*j = *(int *)i + 1;
	return (j);
}

void	del(void *content)
{
	free(content);
}

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
	int		i = 1;
	int		j = 2;
	int		k = 3;
	t_list *node1 = ft_lstnew(&i);
	t_list *node2 = ft_lstnew(&j);
	t_list *node3 = ft_lstnew(&k);
	node1->next = node2;
	node2->next = node3;
	print(node1);
	printf("\n");
	t_list *mapped = ft_lstmap(node1, f, del);
	print(mapped);
	return (0);
}*/