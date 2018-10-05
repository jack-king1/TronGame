#include "GameScene.h"
#include "Game.h"
#include "Actions.h"

GameScene::~GameScene()
{
	input->unregisterCallback(0);
}

bool GameScene::init(ASGE::Renderer * renderer, ASGE::Input* input)
{
	renderer->setClearColour(ASGE::COLOURS::BLACK);

	key_handler_id = input->addCallbackFnc(
		ASGE::E_KEY, &GameScene::keyHandler, this);
	scene_renderer = renderer;

	//setGridPositions();

	grid_sprite.addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\box.png");
	grid_sprite.spriteComponent()->getSprite()->xPos(168);
	grid_sprite.spriteComponent()->getSprite()->yPos(97);

	line1.addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\blue.png");
	line2.addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\purple.png");
	line3.addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\green.png");
	line4.addSpriteComponent(renderer, ".\\Resources\\Textures\\Players\\yellow.png");

	ASGE::Sprite* line1_sprite = line1.spriteComponent()->getSprite();
	line1.setGridX(12);
	line1.setGridY(9);
	line1.setSpawnX(line1.getGridX());
	line1.setSpawnY(line1.getGridY());
	line1_sprite->xPos(line1.getSpawnX());
	line1_sprite->yPos(line1.getSpawnY());

	ASGE::Sprite* line2_sprite = line2.spriteComponent()->getSprite();
	line2.setGridX(46);
	line2.setGridY(9);
	line2.setSpawnX(line2.getGridX());
	line2.setSpawnY(line2.getGridY());
	line2_sprite->xPos(line2.getSpawnX());
	line2_sprite->yPos(line2.getSpawnY());

	ASGE::Sprite* line3_sprite = line3.spriteComponent()->getSprite();
	line3.setGridX(12);
	line3.setGridY(33);
	line3.setSpawnX(line3.getGridX());
	line3.setSpawnY(line3.getGridY());
	line3_sprite->xPos(line3.getSpawnX());
	line3_sprite->yPos(line3.getSpawnY());

	ASGE::Sprite* line4_sprite = line4.spriteComponent()->getSprite();
	line4.setGridX(46);
	line4.setGridY(33);
	line4.setSpawnX(line4.getGridX());
	line4.setSpawnY(line4.getGridY());
	line4_sprite->xPos(line4.getSpawnX());
	line4_sprite->yPos(line4.getSpawnY());
	return true;
}

Scene::NextScene GameScene::update(float dt)
{
	//ASGE::Sprite* line1_sprite = line1.spriteComponent()->getSprite();
	if (current_action == GameScene::Action::CHANGE_TO_MENU)
	{
		return Scene::MENU;
	}
	else if (current_action == GameScene::Action::EXIT)
	{
		return Scene::EXIT;
	}


	//move player line 1
	if (line1.getAlive())
	{
		line1.moveHori(dt);
		line1.moveVert(dt);
		line1.setCurrentPosition();
	}

	//move player line 2
	if (line2.getAlive())
	{
		line2.moveHori(dt);
		line2.moveVert(dt);
		line2.setCurrentPosition();
	}

	//move player line 3
	if (line3.getAlive())
	{
		line3.moveHori(dt);
		line3.moveVert(dt);
		line3.setCurrentPosition();
	}

	//move player line 4
	if (line4.getAlive())
	{
		line4.moveHori(dt);
		line4.moveVert(dt);
		line4.setCurrentPosition();
	}

	//check to see if the player has collided with a grid element.
	if (line1.vector(blue_line, blue_action))
	{
		setNextTrailPosition('b');
	}

	if (line2.vector(purple_line, purple_action))
	{
		setNextTrailPosition('p');
	}

	if (line3.vector(green_line, green_action))
	{
		setNextTrailPosition('g');
	}

	if (line4.vector(yellow_line, yellow_action))
	{
		setNextTrailPosition('y');
	}

	if (!blue_line.empty())
	{
		//line1.collisionCheckSelf(blue_line);
		line2.collisionCheck(blue_line);
		line3.collisionCheck(blue_line);
		line4.collisionCheck(blue_line);
	}

	if (!purple_line.empty())
	{
		line1.collisionCheck(purple_line);

		line3.collisionCheck(purple_line);
		line4.collisionCheck(purple_line);
	}

	if (!green_line.empty())
	{
		line1.collisionCheck(green_line);
		line2.collisionCheck(green_line);
		line4.collisionCheck(green_line);
	}

	if (!yellow_line.empty())
	{
		line1.collisionCheck(yellow_line);
		line2.collisionCheck(yellow_line);
		line3.collisionCheck(yellow_line);
	}

	line1.outOfBounds(grid_sprite.spriteComponent()->getBoundingBox().x, grid_sprite.spriteComponent()->getBoundingBox().y, grid_sprite.spriteComponent()->getBoundingBox().length, grid_sprite.spriteComponent()->getBoundingBox().height);
	line2.outOfBounds(grid_sprite.spriteComponent()->getBoundingBox().x, grid_sprite.spriteComponent()->getBoundingBox().y, grid_sprite.spriteComponent()->getBoundingBox().length, grid_sprite.spriteComponent()->getBoundingBox().height);
	line3.outOfBounds(grid_sprite.spriteComponent()->getBoundingBox().x, grid_sprite.spriteComponent()->getBoundingBox().y, grid_sprite.spriteComponent()->getBoundingBox().length, grid_sprite.spriteComponent()->getBoundingBox().height);
	line4.outOfBounds(grid_sprite.spriteComponent()->getBoundingBox().x, grid_sprite.spriteComponent()->getBoundingBox().y, grid_sprite.spriteComponent()->getBoundingBox().length, grid_sprite.spriteComponent()->getBoundingBox().height);

	return Scene::NONE;
}

void GameScene::render(ASGE::Renderer* renderer)
{
	renderer->renderText("Score: ", 30, 870, 1.0, ASGE::COLOURS::YELLOW);
	renderer->renderSprite(*grid_sprite.spriteComponent()->getSprite());
	renderer->renderText(std::to_string(blue_line.size()), 30, 500, 1.0, ASGE::COLOURS::AQUAMARINE);
	renderer->renderText(std::to_string(purple_line.size()), 30, 550, 1.0, ASGE::COLOURS::PURPLE);
	renderer->renderText(std::to_string(green_line.size()), 30, 600, 1.0, ASGE::COLOURS::LAWNGREEN);
	renderer->renderText(std::to_string(yellow_line.size()), 30, 650, 1.0, ASGE::COLOURS::YELLOW);
	renderer->renderSprite(*line2.spriteComponent()->getSprite());
	renderer->renderSprite(*line3.spriteComponent()->getSprite());
	renderer->renderSprite(*line4.spriteComponent()->getSprite());
	renderer->renderSprite(*line1.spriteComponent()->getSprite());
	//renderer->renderText(std::to_string(line1.getspriteX()), 900, 50, 1.0, ASGE::COLOURS::AQUAMARINE);
	//renderer->renderText(std::to_string(line1.getspriteY()), 1100, 50, 1.0, ASGE::COLOURS::AQUAMARINE);

	if (!blue_line.empty())
	{
		for (int i = 0; i < blue_line.size(); i++)
		{
			renderer->renderSprite(*blue_line[i]->spriteComponent()->getSprite());
		}
	}

	//int grid_pos_x = 0;
	//int grid_pos_y = 0;
	//for (int i = 0; i <= 1620; i++)
	//{
	//	int position_y = grid_array[grid_pos_y].getGridY();
	//	int position_x = grid_array[i].getGridX();
	//	renderer->renderText(std::to_string(position_x), position_x + 4, position_y + 10, 0.5, ASGE::COLOURS::YELLOW);
	//	renderer->renderText(std::to_string(position_y), position_x + 4, position_y + 20, 0.5, ASGE::COLOURS::YELLOW);
	//	grid_pos_x++;
	//	if (grid_pos_x >= 45)
	//	{
	//		grid_pos_x = 0;
	//		grid_pos_y += 1;
	//	}
	//}

	if (!purple_line.empty())
	{
		for (int i = 0; i < purple_line.size(); i++)
		{
			renderer->renderSprite(*purple_line[i]->spriteComponent()->getSprite());
		}
	}

	if (!green_line.empty())
	{
		for (int i = 0; i < green_line.size(); i++)
		{
			renderer->renderSprite(*green_line[i]->spriteComponent()->getSprite());
		}
	}

	if (!yellow_line.empty())
	{
		for (int i = 0; i < yellow_line.size(); i++)
		{
			renderer->renderSprite(*yellow_line[i]->spriteComponent()->getSprite());
		}
	}
}

void GameScene::keyHandler(const ASGE::SharedEventData data)
{
	auto key_event = static_cast<const ASGE::KeyEvent*>(data.get());
	auto action = key_event->action;
	auto key = key_event->key;

	if (key_event->action == ASGE::KEYS::KEY_PRESSED)
	{
		if (key_event->key == ASGE::KEYS::KEY_ENTER)
		{
			current_action = GameScene::Action::CHANGE_TO_MENU;
		}

		if (key_event->key == ASGE::KEYS::KEY_ESCAPE)
		{
			current_action = GameScene::Action::EXIT;
		}
		else if (key == ASGE::KEYS::KEY_S)//player1
		{
			//if(line1.getspriteX() != )
			// fix sprite rendering issues of trail function
			setNextTrailPosition('b');
			blue_action = GameAction::DOWN;
			line1.setVector(0, 1);
		}
		else if (key == ASGE::KEYS::KEY_D)
		{
			setNextTrailPosition('b');
			blue_action = GameAction::RIGHT;
			line1.setVector(1, 0);
		}
		else if (key == ASGE::KEYS::KEY_A)
		{
			setNextTrailPosition('b');
			blue_action = GameAction::LEFT;
			line1.setVector(-1, 0);
		}
		else if (key == ASGE::KEYS::KEY_W)
		{
			setNextTrailPosition('b');
			blue_action = GameAction::UP;
			line1.setVector(0, -1);
		}
		else if (key == ASGE::KEYS::KEY_J) //player 2
		{
			setNextTrailPosition('p');
			purple_action = GameAction::DOWN;
			line2.setVector(0, 1);
		}
		else if (key == ASGE::KEYS::KEY_K)
		{
			setNextTrailPosition('p');
			purple_action = GameAction::RIGHT;
			line2.setVector(1, 0);
		}
		else if (key == ASGE::KEYS::KEY_H)
		{
			setNextTrailPosition('p');
			purple_action = GameAction::LEFT;
			line2.setVector(-1, 0);
		}
		else if (key == ASGE::KEYS::KEY_U)
		{
			setNextTrailPosition('p');
			purple_action = GameAction::UP;
			line2.setVector(0, -1);
		}
		else if (key == ASGE::KEYS::KEY_DOWN) //player 3
		{
			setNextTrailPosition('g');
			green_action = GameAction::DOWN;
			line3.setVector(0, 1);
		}
		else if (key == ASGE::KEYS::KEY_RIGHT)
		{
			setNextTrailPosition('g');
			green_action = GameAction::RIGHT;
			line3.setVector(1, 0);
		}
		else if (key == ASGE::KEYS::KEY_LEFT)
		{
			setNextTrailPosition('g');
			green_action = GameAction::LEFT;
			line3.setVector(-1, 0);
		}
		else if (key == ASGE::KEYS::KEY_UP)
		{
			setNextTrailPosition('g');
			green_action = GameAction::UP;
			line3.setVector(0, -1);
		}
		else if (key == ASGE::KEYS::KEY_KP5) //player 4
		{
			setNextTrailPosition('y');
			yellow_action = GameAction::DOWN;
			line4.setVector(0, 1);
		}
		else if (key == ASGE::KEYS::KEY_KP6)
		{
			setNextTrailPosition('y');
			yellow_action = GameAction::RIGHT;
			line4.setVector(1, 0);
		}
		else if (key == ASGE::KEYS::KEY_KP4)
		{
			setNextTrailPosition('y');
			yellow_action = GameAction::LEFT;
			line4.setVector(-1, 0);
		}
		else if (key == ASGE::KEYS::KEY_KP8)
		{
			setNextTrailPosition('y');
			yellow_action = GameAction::UP;
			line4.setVector(0, -1);
		}
	}
}

void GameScene::setNextTrailPosition(char colour)
{
	switch (colour)
	{
		case 'b': //blue
		{
			blue_line.emplace_back(new Line());
			blue_line.back()->addSpriteComponent(scene_renderer, ".\\Resources\\Textures\\Players\\blue.png");
			blue_line.back()->setTrailPosX(line1.getspriteX());
			blue_line.back()->setTrailPosY(line1.getspriteY());
			blue_line.back()->spriteComponent()->getSprite()->xPos(line1.getspriteX());
			blue_line.back()->spriteComponent()->getSprite()->yPos(line1.getspriteY());
		}
		break;
		case 'p': //purple
		{
			purple_line.emplace_back(new Line());
			purple_line.back()->addSpriteComponent(scene_renderer, ".\\Resources\\Textures\\Players\\purple.png");
			purple_line.back()->setTrailPosX(line2.getspriteX());
			purple_line.back()->setTrailPosY(line2.getspriteY());
			purple_line.back()->spriteComponent()->getSprite()->xPos(line2.getspriteX());
			purple_line.back()->spriteComponent()->getSprite()->yPos(line2.getspriteY());
		}
		break;
		case 'g': //green
		{
			green_line.emplace_back(new Line());
			green_line.back()->addSpriteComponent(scene_renderer, ".\\Resources\\Textures\\Players\\green.png");
			green_line.back()->setTrailPosX(line3.getspriteX());
			green_line.back()->setTrailPosY(line3.getspriteY());
			green_line.back()->spriteComponent()->getSprite()->xPos(line3.getspriteX());
			green_line.back()->spriteComponent()->getSprite()->yPos(line3.getspriteY());
		}
		break;
		case 'y': //yellow
		{
			yellow_line.emplace_back(new Line());
			yellow_line.back()->addSpriteComponent(scene_renderer, ".\\Resources\\Textures\\Players\\yellow.png");
			yellow_line.back()->setTrailPosX(line4.getspriteX());
			yellow_line.back()->setTrailPosY(line4.getspriteY());
			yellow_line.back()->spriteComponent()->getSprite()->xPos(line4.getspriteX());
			yellow_line.back()->spriteComponent()->getSprite()->yPos(line4.getspriteY());
		}
		break;
	}


	//switch (colour)
	//{
	//case 'b': //blue
	//{
	//	blue_line.emplace_back(new Line());
	//	blue_line.back()->createTrail(blue_line, scene_renderer, "blue");
	//}
	//break;
	//case 'p': //purple
	//{
	//	purple_line.emplace_back(new Line());
	//	purple_line.back()->createTrail(purple_line, scene_renderer, "purple");
	//}
	//break;
	//case 'g': //green
	//{
	//	green_line.emplace_back(new Line());
	//	green_line.back()->createTrail(green_line, scene_renderer, "green");
	//}
	//break;
	//case 'y': //yellow
	//{
	//	yellow_line.emplace_back(new Line());
	//	yellow_line.back()->createTrail(yellow_line, scene_renderer, "yellow");
	//}
	//break;
	//}
}

void GameScene::setGridPositions()
{
	//1692 squares in total

	//int grid_pos_x = 0;
	//int grid_pos_y = 0;

	//for (int i = 0; i <= 1620;i++)
	//{
	//	if (grid_pos_x >= 45)
	//	{
	//		grid_pos_x = 0;
	//	}

	//	grid_array[i].setGridX(160, grid_pos_x);
	//	grid_pos_x++;
	//	
	//}



	//for (int j = 0; j <= 1620; j++)
	//{
	//	
	//	if (grid_pos_y >= 35)
	//	{
	//		grid_pos_y = 0;
	//	}
	//	grid_array[j].setGridY(100, grid_pos_y);
	//	grid_pos_y++;
	//}
}
