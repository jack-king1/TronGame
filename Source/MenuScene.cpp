#include "MenuScene.h"

MenuScene::~MenuScene()
{
	input->unregisterCallback(0);
}

bool MenuScene::init(ASGE::Renderer * renderer, ASGE::Input* input)
{
	renderer->setClearColour(ASGE::COLOURS::BLACK);

	key_handler_id = input->addCallbackFnc(
		ASGE::E_KEY, &MenuScene::keyHandler, this);

	return true;
}

Scene::NextScene MenuScene::update(float dt)
{
	if (current_action == MenuScene::Action::CHANGE_TO_GAME)
	{
		return Scene::GAME;
	}
	if (current_action == MenuScene::Action::EXIT)
	{
		return Scene::EXIT;
	}
	return Scene::NONE;
}

void MenuScene::render(ASGE::Renderer * renderer)
{
	renderer->renderText("TRON GAME",400, 150, 2.0, ASGE::COLOURS::LIGHTBLUE);
	renderer->renderText("Press Enter To Begin", 200, 300, 1.0, ASGE::COLOURS::YELLOW);

}

void MenuScene::keyHandler(const ASGE::SharedEventData data)
{
	auto event = static_cast<const ASGE::KeyEvent*>(data.get());

	if (event->action == ASGE::KEYS::KEY_PRESSED)
	{
		if (event->key == ASGE::KEYS::KEY_ENTER)
		{
			current_action = MenuScene::Action::CHANGE_TO_GAME;
		}
		if (event->key == ASGE::KEYS::KEY_ESCAPE)
		{
			current_action = MenuScene::Action::EXIT;
		}
	}
}