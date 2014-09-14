#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class PlayState : public State
{
public:
	PlayState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	void pause();
	void resume();

	void update();
	void draw();

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bg;
};

#endif // PLAYSTATE_HPP
