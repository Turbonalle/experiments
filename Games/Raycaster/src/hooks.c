#include "../lib/raycaster.h"

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;

	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	(void)param;

	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");

	if (xdelta < 0)
		puts("Left!");
	else if (xdelta > 0)
		puts("Right!");
}

void my_hook(void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	(void)param;
}

void my_mousehook(mouse_key_t mouse_key, action_t action, modifier_key_t modifier_key, void *param)
{
	mlx_t *mlx;
	vector_t mouse;

	mlx = param;
	if (mouse_key == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		printf("Left mouse button pressed!\n");
		mlx_get_mouse_pos(mlx, &mouse.x, &mouse.y);
		printf("Mouse position = [%d,%d]\n", (int)mouse.x, (int)mouse.y);
	}
	(void)modifier_key;
	(void)param;
}