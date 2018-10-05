#pragma once
#include "Scene.h"

class MenuScene :
	public Scene
{
public:
	MenuScene() = default;
	virtual ~MenuScene();

	virtual bool init(ASGE::Renderer* renderer, ASGE::Input* input) override;
	virtual Scene::NextScene update(float dt) override;
	virtual void render(ASGE::Renderer* renderer) override;

private:
	ASGE::Input* input = nullptr;

	void keyHandler(const ASGE::SharedEventData data);
	int key_handler_id = -1;

	enum Action
	{
		CHANGE_TO_GAME,
		EXIT,
		NONE
	};

	Action current_action = NONE;
};