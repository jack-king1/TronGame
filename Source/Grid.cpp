#include "Grid.h"

Grid::Grid()
{

}

Grid::~Grid()
{

}

void Grid::setSpriteColour()
{

}

void Grid::setGridX(float x_pos, int grid_number_x)
{
	grid_x = (grid_number_x * 24) + x_pos;
}


void Grid::setGridY(float y_pos, int grid_number_y)
{
	grid_y = (grid_number_y * 24) + y_pos;
}

float Grid::getGridX()
{
	return grid_x;
}

float Grid::getGridY()
{
	return grid_y;
}

void Grid::setClaimedPosition(bool claimed)
{
}

bool Grid::getClaimedPosition()
{
	return claimed_position;
}
