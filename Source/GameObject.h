#pragma once
#include <string>
#include "SpriteComponent.h"
#include "Vector2.h"

/**
*  Objects used throughout the game.
*  Provides a nice solid base class for objects in this game world.
*  They currently support only sprite components, but this could easily
*  be extended to include things like rigid bodies or input systems. 
*  @see SpriteComponent
*/
class GameObject
{
public:
	/**
	*  Default constructor.
	*/
	GameObject() = default;

	/**
	*  Destructor. Frees dynamic memory.
	*/
	~GameObject();
	virtual void render(ASGE::Renderer* renderer);

	/**
	*  Allocates and attaches a sprite component to the object. 
	*  Part of this process will attempt to load a texture file.
	*  If this fails this function will return false and the memory
	*  allocated, freed. 
	*  @param [in] renderer The renderer used to perform the allocations
	*  @param [in] texture_file_name The file path to the the texture to load
	*  @return true if the component is successfully added
	*/
	bool  addSpriteComponent(ASGE::Renderer* renderer, const std::string& texture_file_name);
	
	/**
	*  Returns the sprite componenent.
	*  IT IS HIGHLY RECOMMENDED THAT YOU CHECK THE STATUS OF THE POINTER
	*  IS IS VALID FOR A COMPONENT TO BE NULL AS THEY ARE OPTIONAL!
	*  @return a pointer to the objects sprite component (if any)
	*/
	 SpriteComponent* spriteComponent();

	 bool getVisibility();
	 void setVisibility(bool vis_val);
	 bool getFlight();
	 void setFlight(bool flight_val);
	 bool getReady();
	 void setReady(bool ready_val);
	 bool getLanded();
	 void setLanded(bool land_val);
	 float getX();
	 void setX(float x);
	 float getY();
	 void setY(float y);
	 float getSpeed();
	 void setSpeed(float speed_set);
	 float getVelocityY();
	 void setVelocityY(float velocity_set);
	 float getVelocityX();
	 void setVelocityX(float velocity_set);
	 float getMass();
	 void setMass(float mass_set);
	 void normaliseVector();

private:

	void freeSpriteComponent();	
	SpriteComponent* sprite_component = nullptr;
	vector2 direction{ direction.x, direction.y };
	bool visible = true;
	bool flight = false;
	bool ready = false;
	bool landed = false;
	float mass = 0;
	float speed = 0;
	float y_velocity = 0;
	float x_velocity = 0;
};