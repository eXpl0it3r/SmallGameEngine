#include <iostream>
#include <memory>
#include <stdexcept>

#include "StateMachine.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

PlayState::PlayState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
: State{ machine, window, replace }
{
	if (!m_backgroundTexture.loadFromFile("img/play.png"))
	{
		throw std::runtime_error{ "Was unable to load image 'img/play.png'" };
	}

	m_background.setTexture(m_backgroundTexture, true);

	std::cout << "PlayState Init\n";
}

void PlayState::pause()
{
	std::cout << "PlayState Pause\n";
}

void PlayState::resume()
{
	std::cout << "PlayState Resume\n";
}

void PlayState::update()
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
						m_machine.quit();
						break;

					case sf::Keyboard::M:
						m_next = StateMachine::build<MenuState>(m_machine, m_window, false);
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

void PlayState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw(m_background);
	m_window.display();
}
