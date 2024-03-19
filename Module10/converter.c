#include "adj_converter.h"

AdjMatrix *convert_list_to_matrix(AdjList *list)
{
    int size = list->size;
    AdjMatrix *matrix = blank_matrix(list->size);
    // Traverse through each adjacency list (this will be the row in the matrix)
    for (int row = 0; row < list->size; row++)
    {
        //  Traverse through each edge in the adjacency list (the vertex # will be the column)
        edge_t *current_node = list->adj_lists[row];
        while (current_node != NULL)
        {
            matrix->data[row][current_node->vertex] = current_node->weight; // add weight to the matrix
            current_node = current_node->next;                              // go to the next node in the linked list
        }
    }

    return matrix;
}

AdjList *convert_matrix_to_list(AdjMatrix *matrix)
{
    AdjList *list = create_graph(matrix->size);

    // traverse through each row
    for (int row = 0; row < matrix->size; row++)
    {
        // go through each item in the row
        for (int col = 0; col < matrix->size; col++)
        {
            int edge_weight = matrix->data[row][col];
            // everytime there's an edge make an edge node, add it to the list
            if (edge_weight != 0)
            {
                add_edge(list, row, col, edge_weight);
            }
        }
    }

    return list;
}