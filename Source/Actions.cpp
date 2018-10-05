#include "Actions.h"

/**< Queued Game Action. The next action to be processed as determined by user input. */
std::atomic<GameAction> blue_action = GameAction::NONE;
std::atomic<GameAction> purple_action = GameAction::NONE;
std::atomic<GameAction> green_action = GameAction::NONE;
std::atomic<GameAction> yellow_action = GameAction::NONE;

