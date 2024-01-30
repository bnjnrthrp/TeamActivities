#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

int main(int argc, char const *argv[])
{
    char buff[BUFF_SIZE]; 
    if (argc < 2) {
    printf("You must include at least 1 argument\n");
    return 1; //or exit(1);
    }

    FILE *input = fopen(argv[1],"r");
    // verify that we actually opened a file / not an empty file
    if (input == NULL) {
        printf("error opening the file\n");
        exit(1); // Does exit not return something? What's the difference between exit(1) and return 1;
    }

    char* line = malloc(BUFF_SIZE * sizeof(char));
    while (fgets(line, BUFF_SIZE, input) != NULL) { //!= NULL means go until the end of file??
        // do the thing, line now has the line from input
        printf("%s", line);
    }

    free(line); // don't forget to free memory!
    fclose(input); // don't forget to close a file!
    return 0;
}