#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include "GameState.hpp"

#include <SFML/Graphics.hpp>

class GameEngine;

class IntroState : public GameState
{
public:
	IntroState( GameEngine& game, bool replace = true );

	void pause();
	void resume();

	void update();
	void draw();

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bg;
	sf::RectangleShape m_fader;
	sf::Color m_alpha;
};

#endif // INTROSTATE_HPP
