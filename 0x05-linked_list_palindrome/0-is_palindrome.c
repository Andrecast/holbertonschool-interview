#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list - Get the length of a linked list
 * @head: linked list head
 * Return: lenght
 */

int list(listint_t **head)
{
	int i;
	listint_t *current = *head;

	for (i = 0; current != NULL; i++)
		current = current->next;
	return (i);
}

/**
 * reversed - function that reversed a linked list
 * @head: double pointer
 * Return: Address of the new element
 */

listint_t *reversed(listint_t **head)
{
	listint_t *prev = NULL, *current = *head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - checks if a linked list is palindrome
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length = list(head);
	int half = length / 2;
	int i, if_palindrome = 1;
	listint_t *reversed;
	listint_t *current = *head;
	listint_t *current_reversed;

	reversed = *head;
	for (i = 0; i < half; i++)
		reversed = reversed->next;
	if (length % 2 != 0)
		reversed = reversed->next;
	reversed = reversed(&reversed);
	current_reversed = reversed;
	current = *head;
	while (current_reversed != NULL)
	{
		if (current_reversed->n != current->n)
			if_palindrome = 0;
		current_reversed = current_reversed->next;
		current = current->next;
	}
	return (if_palindrome);
}