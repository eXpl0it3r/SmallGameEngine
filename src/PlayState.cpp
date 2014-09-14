#include <memory>
#include <iostream>

#include "StateMachine.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

PlayState::PlayState( StateMachine& machine, sf::RenderWindow& window, bool replace )
: State( machine, window, replace )
{
	m_bgTex.loadFromFile( "img/play.png" );

	m_bg.setTexture( m_bgTex, true );

	std::cout << "PlayState Init" << std::endl;
}

void PlayState::pause()
{
	std::cout << "PlayState Pause" << std::endl;
}

void PlayState::resume()
{
	std::cout << "PlayState Resume" << std::endl;
}

void PlayState::update()
{
	sf::Event event;

	while( m_window.pollEvent( event ) )
	{
		switch( event.type )
		{
			case sf::Event::Closed:
				m_machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch( event.key.code )
				{
					case sf::Keyboard::Escape:
						m_machine.quit();
						break;

					case sf::Keyboard::M:
						m_next = StateMachine::build<MenuState>( m_machine, m_window, false );
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
	m_window.draw( m_bg );
	m_window.display();
}
