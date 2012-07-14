#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <memory>
#include "GameEngine.hpp"

class GameState
{
public:
	//virtual ~GameState() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(GameEngine& game) = 0;
	virtual void Update(GameEngine& game) = 0;
	virtual void Draw(GameEngine& game) = 0;

	void ChangeState(GameEngine& game, std::unique_ptr<GameState> state)
	{
		game.ChangeState(std::move(state));
	}
};

#endif // GAMESTATE_HPP
