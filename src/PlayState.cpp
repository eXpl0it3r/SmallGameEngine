#include <memory>
#include <iostream>

#include "PlayState.hpp"
#include "MenuState.hpp"
#include "GameEngine.hpp"

PlayState::PlayState( GameEngine& game, bool replace ) : GameState( game, replace )
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
						m_game.quit();
						break;
					case sf::Keyboard::M:
						m_next = m_game.build<MenuState>( false );
						break;
				}
				break;
		}
	}
}

void PlayState::draw()
{
	// Clear the previous drawing
	m_game.screen.clear();
	m_game.screen.draw( m_bg );
	m_game.screen.display();
}

