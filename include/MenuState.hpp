#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine;

class MenuState : public GameState
{
public:
	MenuState( GameEngine& game, bool replace = true );

	void pause();
	void resume();

	void update(sf::Time elapsed);
	void draw(sf::Time elapsed);

private:

	sf::Texture m_bgTex;
	sf::Sprite m_bg;
};

#endif // MENUSTATE_HPP
