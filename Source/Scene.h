#pragma once
#include <Engine\OGLGame.h>

class Scene
{
public:
	enum NextScene
	{
		MENU,
		GAME,
		EXIT,
		NONE
	};

	Scene() = default;
	virtual ~Scene() = default;
	virtual bool init(ASGE::Renderer* renderer, ASGE::Input* input) = 0;
	virtual NextScene update(float dt) = 0;
	virtual void render(ASGE::Renderer* renderer) = 0;
};