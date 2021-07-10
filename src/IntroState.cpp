#include "IntroState.hpp"
#include "PlayState.hpp"
#include "StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <memory>

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
: State{ machine, window, replace }
, m_alpha{ 0, 0, 0, 255 } // Start off opaque
{
	if (!m_backgroundTexture.loadFromFile("img/intro.png"))
	{
		throw std::runtime_error{ "Was unable to load image 'img/intro.png'" };
	}

	m_background.setTexture(m_backgroundTexture, true);

	// Fill the fader surface with black
	m_fader.setFillColor(m_alpha);
	m_fader.setSize(static_cast<sf::Vector2f>(m_backgroundTexture.getSize()));

	std::cout << "IntroState Init\n";
}

void IntroState::pause()
{
	std::cout << "IntroState Pause\n";
}

void IntroState::resume()
{
	std::cout << "IntroState Resume\n";
}

void IntroState::update()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
            case sf::Event::Closed:
                m_machine.quit();
                break;

            case sf::Event::KeyPressed:
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Space:
                        m_next = StateMachine::build<PlayState>(m_machine, m_window, true);
                        break;

                    case sf::Keyboard::Escape:
                        m_machine.quit();
                        break;

					default:
						break;
                }
                break;
            }

			default:
				break;
		}
	}

	if (m_alpha.a != 0)
	{
		m_alpha.a--;
	}

	m_fader.setFillColor(m_alpha);
}

void IntroState::draw()
{
	// Clear the previous drawing
	m_window.clear();

	m_window.draw(m_background);

	// No need to draw if it's transparent
	if (m_alpha.a != 0)
	{
		m_window.draw(m_fader);
	}

	m_window.display();
}
