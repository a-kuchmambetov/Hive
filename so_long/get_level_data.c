#include "main.h"

void get_level_data(t_map map, t_level *level)
{
    int rows;
    int cols;

    rows = 0;
    while (rows < map.rows)
    {
        cols = 0;
        while (cols < map.cols)
        {
            if (map.data[rows][cols] == 'C')
                level->total_collectibles++;
            else if (map.data[rows][cols] == 'P')
            {
                level->p_pos[0] = rows;
                level->p_pos[1] = cols;
            }
            else if (map.data[rows][cols] == 'E')
            {
                level->e_pos[0] = rows;
                level->e_pos[1] = cols;
            }
            cols++;
        }
        rows++;
    }
}