#include "Line.h"

Line::Line()
{

}

Line::~Line()
{

}


int Line::getLength()
{
	return length;
}

char Line::getDirection()
{
	return direction;
}

void Line::setVector(int x, int y)
{
	direction_vector.x = x;
	direction_vector.y = y;
}

void Line::setDirection(char d)
{

}

float Line::setVelocity(float velocity_x, float velocity_y)
{
	return 0.0f;
}

float Line::getVelocityX()
{
	return direction_vector.x;
}

float Line::getSpeed()
{
	return speed;
}

int Line::getVectorX()
{
	return direction_vector.x;
}

int Line::getVectorY()
{
	return direction_vector.y;
}

void Line::moveHori(double dt_sec)
{
	spriteComponent()->getSprite()->xPos(spriteComponent()->getSprite()->xPos() + (direction_vector.x * speed)* dt_sec);
}

void Line::moveVert(float dt_sec)
{
	spriteComponent()->getSprite()->yPos(spriteComponent()->getSprite()->yPos() + (direction_vector.y * speed) * dt_sec);
}

float Line::getspriteX()
{
	float sprite_xpos = spriteComponent()->getSprite()->xPos();
	return sprite_xpos;
}

float Line::getspriteY()
{
	float sprite_ypos = spriteComponent()->getSprite()->yPos();
	return sprite_ypos;
}

void Line::setCurrentPosition()
{
	trail_xpos = spriteComponent()->getSprite()->xPos();//getspriteX();
	trail_ypos = spriteComponent()->getSprite()->yPos();;//getspriteY();
}

bool Line::gridCollision(Line line, Grid grid_array[])
{
	for (int i = 0; i <= 1620; i++)
	{
		if (line.spriteComponent()->getSprite()->xPos() == grid_array->getGridX() && line.spriteComponent()->getSprite()->yPos() == grid_array->getGridY())
		{
			/*grid_array->addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\" + colour + ".png");*/
			return true;
		}
	}

	return false;
}

float Line::getTrailPosX()
{
	return trail_xpos;
}

float Line::getTrailPosY()
{
	return trail_ypos;
}

void Line::setTrailPosX(float x_pos)
{
	trail_xpos = x_pos;
}

void Line::setTrailPosY(float y_pos)
{
	trail_ypos = y_pos;
}

float Line::getSpawnX()
{
	return spawn_location_x;
}

float Line::getSpawnY()
{
	return spawn_location_y;
}

void Line::setSpawnX(float spawn_x)
{
	spawn_location_x = 24 * spawn_x;
}

void Line::setSpawnY(float spawn_y)
{
	spawn_location_y = spawn_y * 24;
}

float Line::getGridX()
{
	return grid_pos_x;
}

float Line::getGridY()
{
	return grid_pos_y;
}

void Line::setGridX(float grid_x)
{
	grid_pos_x = grid_x;
}

void Line::setGridY(float grid_y)
{
	grid_pos_y = grid_y;
}

void Line::cleanPath()
{

}

void Line::createTrail(std::vector<Line*> vector, ASGE::Renderer* scene_renderer, std::string colour)
{
	std::string filename = ".\\Resources\\Textures\\Players\\";
	filename += colour + ".png";

	//vector.emplace_back(new Line());
	vector.back()->addSpriteComponent(scene_renderer, filename);
	vector.back()->setTrailPosX(getspriteX());
	vector.back()->setTrailPosY(getspriteY());
	vector.back()->spriteComponent()->getSprite()->xPos(getspriteX());
	vector.back()->spriteComponent()->getSprite()->yPos(getspriteY());
}

bool Line::collisionCheck(std::vector<Line*> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (spriteComponent()->getBoundingBox().isInside(vector[i]->spriteComponent()->getBoundingBox()))
		{
			setAlive(false);
		}
	}
	return false;
}

bool Line::collisionCheckSelf(std::vector<Line*> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i > 5)
		{
			if (spriteComponent()->getBoundingBox().isInside(vector[i]->spriteComponent()->getBoundingBox()))
			{
				setAlive(false);
			}
		}
	}

	return false;
}

void Line::outOfBounds(float x_pos, float y_pos, float x_pos_width, float y_pos_height)
{
	if (spriteComponent()->getBoundingBox().x <= x_pos ||
		spriteComponent()->getBoundingBox().x + spriteComponent()->getBoundingBox().length >= x_pos + x_pos_width ||
		spriteComponent()->getBoundingBox().y <= y_pos ||
		spriteComponent()->getBoundingBox().y + spriteComponent()->getBoundingBox().length >= y_pos + y_pos_height )
	{
		setAlive(false);
	}
}

void Line::setAlive(bool dead)
{
	alive = dead;
}

bool Line::getAlive()
{
	return alive;
}

bool Line::vector(std::vector<Line*> vector, GameAction game_action)
{
	if (vector.empty())
	{
		if (getspriteX() >= getSpawnX() + 16 || getspriteX() <= getSpawnX() - 16
			|| getspriteY() >= getSpawnY() + 16 || getspriteY() <= getSpawnY() - 16)
		{
			return true;
		}
	}
	else if (!vector.empty())
	{
		switch (game_action)
		{
		case GameAction::DOWN:
		{
			if (getspriteY() >= vector.back()->getTrailPosY() + 16)
			{
				return true;
			}
		}
		break;
		case GameAction::RIGHT:
		{
			if (getspriteX() >= vector.back()->getTrailPosX() + 16)
			{
				return true;
			}
		}
		break;
		case GameAction::LEFT:
		{
			if (getspriteX() <= vector.back()->getTrailPosX() - 16)
			{
				return true;
			}
		}
		break;
		case GameAction::UP:
		{
			if (getspriteY() <= vector.back()->getTrailPosY() - 16)
			{
				return true;
			}
		}
		break;
		default:
			break;
		}
	}

	return false;
}