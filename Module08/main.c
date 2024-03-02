#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

#include "linkedlist.h"

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Build a list with the above data, use add_back.
    // Initialize the list
    NeuList *lst_pointer = create_list();
    // Loop through the array
    int current_year;
    int current_wins;
    for (int i = 0; i < 5; i++)
    {
        current_wins = test_wins[i];
        current_year = test_years[i];

        add_back(lst_pointer, current_wins, current_year);
        // print_list(lst_pointer);
    }

    // printf("FINAL LIST\n");
    print_list(lst_pointer);

    // print the list out to make sure it's correct using your print list function you wrote in linkedlist.h

    // find a year

    // 2016
    Pair *found = find(lst_pointer, 2016);
    printf("looking for 2016\n");
    print_node(found);
    printf("\n");
    // 2014
    printf("looking for 2014\n");
    found = find(lst_pointer, 2014);
    print_node(found);
    printf("\n");

    printf("Freeing the list");
    free_list(lst_pointer);

    return 0;
}