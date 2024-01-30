#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    if (argc < 2) {
    printf("You must include at least 1 argument\n");
    return 1; //or exit(1);
  }
   // print number of arguments
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

}
