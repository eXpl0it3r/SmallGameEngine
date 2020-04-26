#include "StateMachine.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>

MenuState::MenuState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
: State{ machine, window, replace }
{
	m_bgTex.loadFromFile("img/menu.png");

	m_bg.setTexture(m_bgTex, true);

	std::cout << "MenuState Init\n";
}

void MenuState::pause()
{
	std::cout << "MenuState Pause\n";
}

void MenuState::resume()
{
	std::cout << "MenuState Resume\n";
}

void MenuState::update()
{
	for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				m_machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						m_machine.lastState();
						break;

					default:
						break;
				}
				break;

			default:
				break;
		}
	}
}

void MenuState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw(m_bg);
	m_window.display();
}
