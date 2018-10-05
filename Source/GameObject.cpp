#include <Engine\Renderer.h>
#include "GameObject.h"

GameObject::~GameObject()
{
	freeSpriteComponent();
}

void GameObject::render(ASGE::Renderer* renderer)
{
	renderer->renderSprite(*sprite_component->getSprite());
}

bool GameObject::addSpriteComponent(
	ASGE::Renderer* renderer, const std::string& texture_file_name)
{
	freeSpriteComponent();

	sprite_component = new SpriteComponent();
	if (sprite_component->loadSprite(renderer, texture_file_name))
	{
		return true;
	}

	freeSpriteComponent();
	return false;
}

void  GameObject::freeSpriteComponent()
{
	delete sprite_component;
	sprite_component = nullptr;
}

SpriteComponent* GameObject::spriteComponent() 
{
	return sprite_component;
}

bool GameObject::getVisibility()
{
	return visible;
}

void GameObject::setVisibility(bool vis_val)
{
	visible = vis_val;
}

bool GameObject::getFlight()
{
	return flight;
}

void GameObject::setFlight(bool flight_val)
{
	flight = flight_val;
}

bool GameObject::getReady()
{
	return ready;
}

void GameObject::setReady(bool ready_val)
{
	ready = ready_val;
}

bool GameObject::getLanded()
{
	return landed;
}

void GameObject::setLanded(bool land_val)
{
	landed = land_val;
}

float GameObject::getX()
{
	return direction.x;
}

void GameObject::setX(float x)
{
	direction.x = x;
}

float GameObject::getY()
{
	return direction.y;
}

void GameObject::setY(float y)
{
	direction.y = y;
}

float GameObject::getSpeed()
{
	return speed;
}

void GameObject::setSpeed(float speed_set)
{
	speed = speed_set;
}

float GameObject::getVelocityY()
{
	return y_velocity;
}

void GameObject::setVelocityY(float velocity_set)
{
	y_velocity = velocity_set;
}

float GameObject::getVelocityX()
{
	return x_velocity;
}

void GameObject::setVelocityX(float velocity_set)
{
	x_velocity = velocity_set;
}

float GameObject::getMass()
{
	return mass;
}

void GameObject::setMass(float mass_set)
{
	mass = mass_set;
}

void GameObject::normaliseVector()
{
	float magnitude = sqrtf((direction.x*direction.x) + (direction.y*direction.y));

	if (!magnitude)
		return;

	direction.x /= magnitude;
	direction.y /= magnitude;
}
