#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * factorise - this function deals with factorising lineptr input
 * @lineptr: line read
*/

void factorise(const char **lineptr)
{
    char *endptr = NULL;
    long long int num = strtoll(*lineptr, &endptr, 10), q = 2, p = 0;


    while (q <= num / 2)
    {
        if (num % q == 0)
        {
            p = num / q;
            break;
        }
        q += 1;
    }
    printf("%lld=%lld*%lld\n", num, p, q);
    free((char *)*lineptr);
    *lineptr = NULL;
}

/**
 * main - program seeks to factorise a number into n=p*q
 * @ac: argument count
 * @av: argument vector
 * Return: 0 always upon success, otherwise failure
 */

int main(int ac, char *av[])
{
    size_t n = 0;
    char *lineptr = NULL;
    FILE *file = NULL;

    if (ac < 2)
        return (EXIT_FAILURE);

    file = fopen(av[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "File read error");
        return (EXIT_FAILURE);
    }
    while(getline(&lineptr, &n, file) >= 0)
    {
        if (lineptr[0] == '\n')
        {
            free(lineptr);
            lineptr = NULL;
            continue;
        }
        factorise((const char **)&lineptr);
    }
    if (lineptr != NULL)
        free(lineptr);
    fclose(file);
    return (0);
}
