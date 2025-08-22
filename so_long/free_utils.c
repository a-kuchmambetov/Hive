#include "main.h"

void free_map_data(char **data, int rows, int cols)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(data[i]);
        i++;
    }
    free(data);
}