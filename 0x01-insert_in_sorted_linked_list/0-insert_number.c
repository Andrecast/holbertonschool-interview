#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *tmp = *head;

    new_node = malloc(sizeof(listint_t));
    if (!new_node) /*Si  malloc alla, retorne NULL*/
        return (NULL);

    new_node->n = number;

    if (*head == NULL || (*head)->n > number)/*Si la lista está vacia o si solo hay 1 nodo*/
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    while (tmp->next != NULL && tmp->next->n < number) /*Mientras haya al menos 1 nodo y el nodo actual sea menor al nuevo nodo*/
        {
            tmp = tmp->next; /*Recorra la lista*/
        }
        new_node->next = tmp->next; /*tmp->next está apuntando al n del siguiente nodo*/
        tmp->next = new_node;
    return (new_node);
}
