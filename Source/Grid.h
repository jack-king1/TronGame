#pragma once
#include "GameObject.h"
#include <vector>


class Grid : public GameObject
{
public:
	Grid();
	~Grid();

	void setSpriteColour();

	void setGridX(float x_pos, int grid_number_x);
	void setGridY(float y_pos, int grid_number_y);

	float getGridX();
	float getGridY();

	void setClaimedPosition(bool claimed);
	bool getClaimedPosition();


private:
	float grid_x;
	float grid_y;
	bool claimed_position;
};