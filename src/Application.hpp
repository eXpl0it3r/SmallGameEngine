#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IntroState.hpp"
#include "StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Application
{
public:
	Application() = default;

	void run();

private:
	StateMachine m_machine;
	sf::RenderWindow m_window;
};

#endif // APPLICATION_HPP
