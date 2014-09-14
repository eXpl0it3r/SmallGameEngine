#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class MenuState : public State
{
public:
	MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	void pause();
	void resume();

	void update();
	void draw();

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bg;
};

#endif // MENUSTATE_HPP
