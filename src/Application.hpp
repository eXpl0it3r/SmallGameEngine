#pragma once

#include "StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
public:
	void run();

private:
	StateMachine m_machine;
	sf::RenderWindow m_window;
};
