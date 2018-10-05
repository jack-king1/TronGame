#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Line.h"
#include "Grid.h"

class GameScene :
	public Scene
{
public:
	GameScene() = default;
	virtual ~GameScene();
	virtual bool init(ASGE::Renderer* renderer, ASGE::Input* input) override;
	virtual Scene::NextScene update(float dt) override;
	virtual void render(ASGE::Renderer* renderer) override;

private:
	ASGE::Input* input = nullptr;
	ASGE::Renderer* scene_renderer = nullptr;

	void keyHandler(const ASGE::SharedEventData data);
	void setNextTrailPosition(char colour);
	void setGridPositions();
	int key_handler_id = -1;

	Grid grid_sprite;
	Grid grid_array[1620]; //1620

	Line line1;
	Line line2;
	Line line3;
	Line line4;

	std::vector<Line*> blue_line;
	std::vector<Line*> purple_line;
	std::vector<Line*> green_line;
	std::vector<Line*> yellow_line;

	enum Action
	{
		EXIT,
		CHANGE_TO_MENU,
		NONE
	};

	Action current_action = NONE;
};