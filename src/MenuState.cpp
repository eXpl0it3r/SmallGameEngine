#include <memory>
#include <iostream>

#include "GameEngine.hpp"
#include "MenuState.hpp"

MenuState::MenuState( GameEngine& game, bool replace ) : GameState( game, replace )
{
	m_bgTex.loadFromFile( "img/menu.png" );

	m_bg.setTexture( m_bgTex, true );

	std::cout << "MenuState Init" << std::endl;
}

void MenuState::pause()
{
	std::cout << "MenuState Pause" << std::endl;
}

void MenuState::resume()
{
	std::cout << "MenuState Resume" << std::endl;
}

void MenuState::update()
{
	sf::Event event;

	while( m_game.screen.pollEvent( event ) )
	{
		switch( event.type )
		{
			case sf::Event::Closed:
				m_game.quit();
				break;

			case sf::Event::KeyPressed:
				switch( event.key.code )
				{
					case sf::Keyboard::Escape:
						m_game.lastState();
						break;
				}
				break;
		}
	}
}

void MenuState::draw()
{
	// Clear the previous drawing
	m_game.screen.clear();
	m_game.screen.draw( m_bg );
	m_game.screen.display();
}

