#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include "GameState.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class IntroState : public GameState
{
public:
	IntroState( StateMachine& game, sf::RenderWindow& window, bool replace = true );

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
