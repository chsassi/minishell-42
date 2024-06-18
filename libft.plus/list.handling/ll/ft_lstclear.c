/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:16:29 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:32:32 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}

/* void delete(void *nodo)
{
	free(nodo);
}

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d -> ", *(int *)(lst->content));
		lst = lst->next;
	}
	printf("NULL\n");
}

int main(void)
{
	t_list *head = NULL;

	int		*n1 = malloc(sizeof(int));
	*n1 = 42;
	t_list	*node1 = ft_lstnew(n1);

	int		*n2 = malloc(sizeof(int));
	*n2 = 99;
	t_list *node2 = ft_lstnew(n2);

	head = node2;
	node2->next = node1;

	printf("Linked List (before clear): ");
	print_list(head);

	ft_lstclear(&head, delete);

	printf("Linked List (after clear): ");
	print_list(head);
} */
