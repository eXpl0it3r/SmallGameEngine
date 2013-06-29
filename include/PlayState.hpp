#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine;

class PlayState : public GameState
{
public:
	PlayState( GameEngine& game, bool replace = true );

	void pause();
	void resume();

	void update((sf::Time elapsed);
	void draw((sf::Time elapsed);

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bg;
};

#endif // PLAYSTATE_HPP
