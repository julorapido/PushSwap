/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <jsaintho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:25:43 by jsaintho          #+#    #+#             */
/*   Updated: 2024/07/01 12:16:48 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer of it
t_stack	*ft_stacknew(int nbr, t_stack *prev_)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->next = NULL;
	if (prev_ != NULL)
		new->prev = prev_;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// Returns the last node of a list
t_stack	*ft_stacklast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*n;

	if (*stack)
	{
		n = ft_stacklast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Returns the size of the Linked List
int	ft_stacksize(t_stack *s)
{
	size_t	i;
	t_stack	*head;

	head = s;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

// Prints the Linked List
void	printList(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	//printf("=//=//=//=//=//=//=//=//=//=");
	while (tmp)
	{
		if (tmp -> nbr)
			printf(" >> [%ld] : %ld >> \n", tmp->nbr, tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}


long	ft_stack_nth(t_stack **s, int n)
{
	t_stack *h;
	int 	c;

	c = 0;
	h = *s;
	while (h && c != n)
	{
		c++;
		h = h->next;
	}
	if (c != n)
		return (-1);
	return (h->nbr);
}
