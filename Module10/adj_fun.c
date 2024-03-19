
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "adj_converter.h"

#define DIRECTED_ONE_DIRECTION 0
#define DIRECTED_UNBALANCED 1
#define UNDIRECTED 2
#define MAX_DISTANCE 10

AdjMatrix *buildRandomMatrix(int size, int type)
{
    srand(time(NULL));
    AdjMatrix *matrix = blank_matrix(size);

    for (int i = 0; i < matrix->size; i++)
    {
        for (int j = 0; j < matrix->size; j++)
        {
            if (i == j)
                continue; // skip self reference
            switch (type)
            {
            case DIRECTED_ONE_DIRECTION:
                if (i < j)
                    matrix->data[i][j] = rand() % MAX_DISTANCE;
                else
                    matrix->data[i][j] = 0; // no back edges
                /* code */
                break;
            case DIRECTED_UNBALANCED:
                matrix->data[i][j] = rand() % MAX_DISTANCE;
                break;
            case UNDIRECTED:
                matrix->data[i][j] = rand() % MAX_DISTANCE;
                matrix->data[j][i] = matrix->data[i][j];
                break;
            default:
                fprintf(stderr, "Invalid type");
                return NULL;
            }
        }
    }
    return matrix;
}

int main(int argc, char **argv)
{

    printf("Undirected Matrix\n");
    AdjMatrix *matrix = buildRandomMatrix(5, UNDIRECTED);
    print_matrix(matrix);

    // printf("Directed Matrix, one direction\n");
    // AdjMatrix *one_dir_matrix = buildRandomMatrix(5, DIRECTED_ONE_DIRECTION);
    // print_matrix(one_dir_matrix);

    // printf("Directed Matrix, unbalanced\n");
    // AdjMatrix *unbalanced_matrix = buildRandomMatrix(5, DIRECTED_UNBALANCED);
    // print_matrix(unbalanced_matrix);

    // Making adjacency list, not needed at the moment

    printf("Converting matrix to list\n");
    AdjList *list = convert_matrix_to_list(matrix);
    print_graph(list);

    printf("Converting list to matrix\n");
    // int size = list->size;
    // printf("\tin main the size of the list is %d\n", size);
    AdjMatrix *new_matrix = convert_list_to_matrix(list);

    free_graph(list);
    print_matrix(new_matrix);
    free_matrix(new_matrix);

    free_matrix(matrix);
    // free_matrix(one_dir_matrix);
    // free_matrix(unbalanced_matrix);
    return 0;
}