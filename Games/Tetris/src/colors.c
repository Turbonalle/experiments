#include "../incl/fractol.h"

int	set_color(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	get_b(int color)
{
	return (color & 0xFF);
}
