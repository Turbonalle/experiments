#include "../lib/raycaster.h"

void init_map(map_t *map, int columns, int rows, int cell_size)
{
	int i;

	map->columns = columns;
	map->rows = rows;
	map->cell_size = cell_size;
	map->grid = malloc(sizeof(int *) * rows);
	if (!map->grid)
		ft_error();
	i = -1;
	while (++i < map->rows)
	{
		map->grid[i] = malloc(sizeof(int) * map->columns);
		if (!map->grid[i])
			ft_error();
	}
	reset_map(map);
}

void print_map(map_t *map)
{
	int column;
	int row;

	row = -1;
	while (++row < map->rows)
	{
		column = -1;
		while (++column < map->columns)
			printf("%d ", map->grid[row][column]);
		printf("\n");
	}
}

void free_map(map_t *map)
{
	int i;

	i = map->rows;
	while (--i >= 0)
		free(map->grid[i]);
	free(map->grid);
}