/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:36:23 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:32:32 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* void print_list(t_list *lst)
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

	int		n1 = 42;
	t_list	*node1 = malloc(sizeof(t_list));
	node1->content = &n1;
	node1->next = NULL;

	int		n2 = 99;
	t_list	*node2 = malloc(sizeof(t_list));
	node2->content = &n2;
	node2->next = NULL;

	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	printf("Linked List: ");
	print_list(head);

	while (head)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
}
 */
