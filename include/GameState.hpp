#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <memory>

#include "GameEngine.hpp"

class GameState
{
public:
	GameState( GameEngine& game, bool replace = true ) : m_game( game ), m_replacing( replace ) {}
	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void update(sf::Time elapsed) = 0;
	virtual void draw(sf::Time elapsed) = 0;

	std::unique_ptr<GameState> next()
	{
		return std::move( m_next );
	}

	bool isReplacing()
	{
		return m_replacing;
	}

protected:
    GameEngine& m_game;
	bool m_replacing;
	std::unique_ptr<GameState> m_next;
};

#endif // GAMESTATE_HPP
