#pragma once

#include "State.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class IntroState final : public State
{
public:
	IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
	sf::RectangleShape m_fader;
	sf::Color m_alpha;
};
