#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <memory>

#include "GameEngine.hpp"

class GameState
{
public:
	GameState( bool replace = true ) : replacing( replace ) {}
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents( GameEngine& game ) = 0;
	virtual void Update( GameEngine& game ) = 0;
	virtual void Draw( GameEngine& game ) = 0;

	std::unique_ptr<GameState> Next()
	{
		return std::move( next );
	}

	/*void ChangeState( GameEngine& game, std::unique_ptr<GameState> state )
	{
		game.ChangeState( std::move( state ) );
	}*/

	bool isReplacing()
	{
		return replacing;
	}

protected:
	bool replacing;
	std::unique_ptr<GameState> next;
};

#endif // GAMESTATE_HPP
