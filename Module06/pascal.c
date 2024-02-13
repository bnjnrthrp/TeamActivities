#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define MAX 5000
#define PRINT_SINGLE 1
#define PRINT_ALL 2

typedef uint64_t ull;

// don't forget to allocate space for your table (multi-demi arrayof MAX x MAX)
static ull table[MAX][MAX];

void printSingleRow(ull *row, int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("%llu ", row[i]);
    }
    printf("\n");
}

// dynamic programming: find the value of the number in row n and column i
ull pascaldp(int n, int i, ull *ops)
{
    //     // if already calculated, return from the array
    //     if (table[n][i] > 0)
    //     {
    //         printf("table[%d][%d]\n", n, i); // TESTING
    //         return table[n][i];
    //     }
    //     // otherwise we need to calculate it ourselves
    //     // if this is the first or last number in the row then it equals 1
    //     if (i == 0 || i == n)
    //     {
    //         printf("\ti was 0 or n\n"); // TESTING
    //         table[n][i] = 1;
    //     }
    //     else
    //     {
    //         printf("\tadding to the table\n"); // TESTING
    //         (*ops)++;
    //         table[n][i] = table[n - 1][i - 1] + table[n - 1][i];
    //         printf("\t\t%llu + %llu = %llu\n", table[n - 1][i - 1], table[n - 1][i], table[n][i]); // TESTING
    //     }

    //     return table[n][i];
    if (table[n][i] > 0)
    {
        return table[n][i];
    }
    if (n == i || i == 0)
    {
        return 1;
    }
    else
    {
        (*ops)++;
        table[n][i] = pascaldp(n - 1, i, ops) + pascaldp(n - 1, i - 1, ops);
        return table[n][i];
    }
}

// *ops is a pointer to an ull number that counts the number of operations
// n is an integer for the row we're in
ull *pascaldp_full(int n, ull *ops)
{
    // theory: are we not iterating through the rows above row n when we are supposed to be???
    ull *row = malloc((sizeof(ull)) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        row[i] = pascaldp(n, i, ops);
    }
    return row;
}

ull pascalr(int n, int i, ull *ops)
{
    if (n == i || i == 0)
    {
        return 1;
    }
    else
    {
        (*ops)++;
        return pascalr(n - 1, i, ops) + pascalr(n - 1, i - 1, ops);
    }
}

ull *pascalr_full(int n, ull *ops)
{
    ull *row = malloc((sizeof(ull)) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        row[i] = pascalr(n, i, ops);
    }
    return row;
}

ull *pascal_iterative(int n, ull *ops)
{
    ull **triangle = (ull **)malloc((n + 1) * sizeof(ull *));
    for (int i = 0; i <= n; i++)
    {
        triangle[i] = (ull *)malloc((i + 1) * sizeof(ull));
        triangle[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            (*ops)++;
            if (i == j)
            {
                triangle[i][j] = 1;
            }
            else
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }
    // copy the last row into a new array to return
    ull *row = malloc((sizeof(ull)) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        row[i] = triangle[n][i];
    }
    // free the triangle
    for (int i = 0; i <= n; i++)
    {
        free(triangle[i]);
    }
    free(triangle);

    // give back the single row
    return row;
}

// NOTE: this is receiving the row we malloced
double time_function(ull *(*func)(int, ull *), int n, ull *ops, bool print)
{
    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC, &begin);
    ull *row = func(n, ops);
    clock_gettime(CLOCK_MONOTONIC, &end);
    if (print)
    {
        printSingleRow(row, n);
        free(row); // NOTE: added this to try and fix memory leak?
    }
    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

void help()
{
    printf("./pascal.out N [Type] [Print Level]\n");
    printf("\tN is the number of rows in the pascal triangle, required.\n");
    printf("\t[Type] is 4 for dp and iterative only, 3 for all three, 2 for dynamic programming version, 1 for recursive version, 0 for iterative version, defaults to 3.\n");
    printf("\t[Print Level] leave blank for speed compare only, or print to print row\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("at least two arguments needed!\n");
        help();
        return 1;
    }

    const int n = atoi(argv[1]);
    int type = 3;
    int print = 0;
    if (argc > 2)
    {
        type = atoi(argv[2]);
    }
    if (argc > 3)
    {
        print = true;
    }

    // table = (ull *)calloc((MAX * MAX), sizeof(ull *));

    ull ops;
    double time;
    switch (type)
    {
    case 0:
        printf("iterative version\n");
        ops = 0;
        time = time_function(pascal_iterative, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 1:
        printf("recursive version\n");
        ops = 0;
        time = time_function(pascalr_full, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 2:
        printf("dynamic programming version\n");
        ops = 0;
        time = time_function(pascaldp_full, n, &ops, print);
        printf("time: %f(%llu)\n", time, ops);
        break;
    case 4:
        ops = 0;
        time = time_function(pascal_iterative, n, &ops, print);
        printf("%f,%llu,", time, ops);

        ops = 0;
        time = time_function(pascaldp_full, n, &ops, print);
        printf("%f,%llu,-,-", time, ops);
        break;
    default:
        ops = 0;
        time = time_function(pascal_iterative, n, &ops, print);
        printf("%f,%llu,", time, ops);

        ops = 0;
        time = time_function(pascaldp_full, n, &ops, print);
        printf("%f,%llu,", time, ops);

        ops = 0;
        time = time_function(pascalr_full, n, &ops, print);
        printf("%f,%llu", time, ops);

        break;
    }
    // free(table);
}
