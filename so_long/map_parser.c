#include "main.h"

static int check_outer_walls(t_map map)
{
    int cols;
    int rows;

    cols = 0;
    while (cols < map.cols)
    {
        if (map.data[0][cols] != '1' || map.data[map.rows - 1][cols] != '1')
        return (1);
        cols++;
    }
    rows = 0;
    while (rows < map.rows)
    {
        if (map.data[rows][0] != '1' || map.data[rows][map.cols - 1] != '1')
            return (1);
        rows++;
    }
    return (0);
}

static t_array3 get_count_items(t_map map, t_array3 count, int start_pos[2])
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
                count.data[0]++;
            else if (map.data[rows][cols] == 'P')
            {
                count.data[1]++;
                start_pos[0] = rows;
                start_pos[1] = cols;
            }
            else if (map.data[rows][cols] == 'E')
                count.data[2]++;
            cols++;
        }
        rows++;
    }
    return (count);
}

static void check_map_items(char **data, int coordsYX[2], t_array3 *count)
{
    if (data[coordsYX[0]][coordsYX[1]] == '1' || data[coordsYX[0]][coordsYX[1]] == 'M')
        return;
    if (data[coordsYX[0]][coordsYX[1]] == 'C')
        count->data[0]++;
    else if (data[coordsYX[0]][coordsYX[1]] == 'P')
        count->data[1]++;
    else if (data[coordsYX[0]][coordsYX[1]] == 'E')
        count->data[2]++;
    data[coordsYX[0]][coordsYX[1]] = 'M';
    // Recursive call for 4 directions;
    check_map_items(data, (int[]){coordsYX[0] - 1, coordsYX[1]}, count);
    check_map_items(data, (int[]){coordsYX[0] + 1, coordsYX[1]}, count);
    check_map_items(data, (int[]){coordsYX[0], coordsYX[1] - 1}, count);
    check_map_items(data, (int[]){coordsYX[0], coordsYX[1] + 1}, count);
}

static char **duplicate_map_data(t_map map)
{
    int i;
    char **new_map;

    new_map = malloc(sizeof(char *) * (map.rows + 1));
    if (!new_map)
        return (NULL);
    i = 0;
    while (i < map.rows)
    {
        new_map[i] = ft_strdup(map.data[i]);
        if (!new_map[i])
        {
            while (i > 0)
                free(new_map[--i]);
            free(new_map);
            return (NULL);
        }
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}

int parse_map(t_map map)
{
    int start_pos[2];
    const t_array3 existing_elem = get_count_items(map, (t_array3){0}, start_pos);
    t_array3 res;
    char **data;

    data = duplicate_map_data(map);
    res = (t_array3){0};
    if (check_outer_walls(map))
        return (ft_putstr_fd("Error: map is not surrounded by walls\n", 2), 1);
    if (existing_elem.data[0] == 0)
        return ( ft_putstr_fd("Error: no collectibles found\n", 2), 1);
    if (existing_elem.data[1] != 1 || existing_elem.data[2] != 1)
        return (ft_putstr_fd("Error: invalid number of player/exit\n", 2), 1);
    check_map_items(data, start_pos, &res);
    free_map_data(data, map.rows, map.cols);
    if (res.data[0] != existing_elem.data[0])
        return (ft_putstr_fd("Error: collectibles are not valid\n", 2), 1);
    if (res.data[1] != existing_elem.data[1])
        return (ft_putstr_fd("Error: player is not valid\n", 2), 1);
    if (res.data[2] != existing_elem.data[2])
        return (ft_putstr_fd("Error: exit is not valid\n", 2), 1);
    return (0);
}
