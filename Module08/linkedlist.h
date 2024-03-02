#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

// TODO: Create your node_t type here
typedef struct node
{
    int num_wins;
    int year;
    struct node *next; // notice this pointer!
} Pair;

typedef struct list
{
    Pair *head;
    int size;
} NeuList;

Pair *new_node(int wins, int year, Pair *next)
{

    Pair *newNode = (Pair *)malloc(sizeof(Pair));
    newNode->num_wins = wins;
    newNode->year = year;
    newNode->next = next;
    return newNode;
}

NeuList *create_list()
{
    NeuList *list = (NeuList *)malloc(sizeof(NeuList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void push_front(NeuList *list, int wins, int year)
{
    Pair *newNode = new_node(wins, year, list->head);
    list->head = newNode;
    list->size++;
}

void add_back(NeuList *list, int wins, int year)
{
    Pair *newNode = new_node(wins, year, NULL);
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Pair *curr = list->head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list->size++;
}

void print_list(NeuList *list)
{
    Pair *curr = list->head;
    // go through all the nodes except the last one
    while (curr->next != NULL)
    {
        // print the current node's info, and arrow to the next node
        print_node(curr);
        printf(" -> ");
        // printf("(%d, %d) -> ", curr->num_wins, curr->year);
        curr = curr->next;
    }
    // print node without the arrow at the end because it's the tail
    printf("(%d, %d)\n", curr->num_wins, curr->year);
}

void print_node(Pair *my_node)
{
    printf("(%d, %d)", my_node->num_wins, my_node->year);
}

Pair *find(NeuList *list, int year)
{
    Pair *curr = list->head;
    // iterate through list
    for (int i = 0; i < (list->size); i++)
    {
        // see if current node has correct year
        if (curr->year == year)
        {
            return curr;
        }

        // otherwise continue iterating to next node
        curr = curr->next;
    }

    // if went through entire list and couldn't find it return null
    return NULL;
}

void free_list(NeuList *list)
{
    Pair *curr = list->head;
    Pair *next;

    // iterate through list
    for (int i = 0; i < (list->size); i++)
    {
        // Set the next pointer prior to freeing the current Node
        next = curr->next;
        free(curr);
        // update for our next iteration
        curr = next;
    }

    // finally free the list pointer
    free(list);
}

#endif // LINKED_LIST_H