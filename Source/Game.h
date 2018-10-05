#pragma once
#include <string>
#include <Engine/OGLGame.h>

#include "Scene.h"


/**
*  An OpenGL Game based on ASGE.
*/
class AngryBirdsGame :
	public ASGE::OGLGame
{
public:
	AngryBirdsGame() = default;
	~AngryBirdsGame();

	virtual bool init() override;
	virtual void update(const ASGE::GameTime& us) override;
	virtual void render(const ASGE::GameTime& us) override;
	void setupResolution();
	std::unique_ptr<Scene> current_scene = nullptr;

private:
	int  key_callback_id = -1;	        /**< Key Input Callback ID. */
};