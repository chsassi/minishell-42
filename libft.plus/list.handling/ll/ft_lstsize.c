/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:39:15 by chsassi           #+#    #+#             */
/*   Updated: 2024/06/18 14:32:32 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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

void free_list(t_list *head)
{
	while (head)
	{
		t_list *temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
}

int main(void)
{
	t_list	*head = NULL;

	int		*n1 = malloc(sizeof(int));
	*n1 = 42;
	t_list	*node1 = ft_lstnew(n1);

	int		*n2 = malloc(sizeof(int));
	*n2 = 99;
	t_list	*node2 = ft_lstnew(n2);

	head = node2;
	node2->next = node1;

	printf("Linked List: ");
	print_list(head);

	int		size = ft_lstsize(head);
	printf("Size of the List: %d\n", size);
	free_list(head);
} */
