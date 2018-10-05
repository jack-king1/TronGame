#include <string>
#include <math.h>
#include <Engine/Keys.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Sprite.h>
#include "GameScene.h"
#include "MenuScene.h"
#include "Game.h"

/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/
AngryBirdsGame::~AngryBirdsGame()
{
	inputs->unregisterCallback(key_callback_id);
}

/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The keyHandler and clickHandler
			 callback should also be set in the initialise function.
*   @return  True if the game initialised correctly.
*/
bool AngryBirdsGame::init()
{
	setupResolution();
	if (!initAPI())
	{
		return false;
	}

	toggleFPS();
	renderer->setWindowedMode(ASGE::Renderer::WindowMode::WINDOWED);
	renderer->setClearColour(ASGE::COLOURS::BLACK);

	inputs->use_threads = false;

	current_scene = std::unique_ptr<MenuScene>(new MenuScene);

	if (!current_scene->init(renderer.get(), inputs.get()))
	{
		return false;
	}


	return true;
}

void AngryBirdsGame::update(const ASGE::GameTime& us)
{
	auto dt_sec = us.delta_time.count() / 1000.0;
	switch (current_scene->update(dt_sec))
	{
		case Scene::MENU:
		{
			current_scene.reset();
			current_scene = std::unique_ptr<MenuScene>(new MenuScene);
			current_scene->init(renderer.get(), inputs.get());
			break;
		}
		case Scene::GAME:
		{
			current_scene.reset();
			current_scene = std::unique_ptr<GameScene>(new GameScene);
			current_scene->init(renderer.get(), inputs.get());
			break;
		}
		case Scene::EXIT:
		{
			signalExit();
			break;
		}
	}
}

void AngryBirdsGame::render(const ASGE::GameTime& us)
{
	renderer->setFont(0);
	current_scene->render(renderer.get());
}

void AngryBirdsGame::setupResolution()
{
	// how will you calculate the game's resolution?
	// will it scale correctly in full screen? what AR will you use?
	// how will the game be framed in native 16:9 resolutions?
	// here are some abritrary values for you to adjust as you see fit
	game_width = 1400;
	game_height = 1000;
}
