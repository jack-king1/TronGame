#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Actions.h"
#include <vector>
#include "Grid.h"
#include "Rect.h"


class Line : public GameObject
{
public:
	Line();
	~Line();

	int getLength();
	char getDirection();

	void setDirection(char d);

	float setVelocity(float velocity_x, float velocity_y);
	float getVelocityX();
	float getSpeed();

	void setVector(int x, int y);
	int getVectorX();
	int getVectorY();


	void moveHori(double dt_sec);

	void moveVert(float dt_sec);

	float getspriteX();
	float getspriteY();

	void setCurrentPosition();

	bool gridCollision(Line line, Grid grid_array[]);

	float getTrailPosX();
	float getTrailPosY();

	void setTrailPosX(float x_pos);
	void setTrailPosY(float y_pos);

	float getSpawnX();
	float getSpawnY();

	void setSpawnX(float spawn_X);
	void setSpawnY(float spawn_y);

	float getGridX();
	float getGridY();

	void setGridX(float grid_x);
	void setGridY(float grid_y);

	void cleanPath();

	bool vector(std::vector<Line*> vector, GameAction game_action);
	void createTrail(std::vector<Line*> vector, ASGE::Renderer* scene_renderer, std::string colour);

	bool collisionCheck(std::vector<Line*> vector);
	bool collisionCheckSelf(std::vector<Line*> vector);
	void outOfBounds(float x_pos, float y_pos, float x_pos_width, float y_pos_height);

	void setAlive(bool dead);
	bool getAlive();

private:
	float speed = 200.0f;
	vector2 direction_vector = { 0, 0 };
	char direction = 'd';
	int length = 0;
	bool alive = true;

	float spawn_location_x;
	float spawn_location_y;
	
	int grid_pos_x;
	int grid_pos_y;

	//used for active player pos
	float current_xpos;
	float current_ypos;

	//used for trail pos
	float trail_xpos;
	float trail_ypos;
};