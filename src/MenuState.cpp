#include <memory>
#include <iostream>

#include "MenuState.hpp"
#include "GameEngine.hpp"

MenuState::MenuState( bool replace ) : GameState( replace )
{
	bgTex.loadFromFile( "img/menu.bmp" );

	bg.setTexture( bgTex, true );

	std::cout << "MenuState Init" << std::endl;
}

MenuState::~MenuState()
{
	std::cout << "MenuState Cleanup" << std::endl;
}

void MenuState::Pause()
{
	std::cout << "MenuState Pause" << std::endl;
}

void MenuState::Resume()
{
	std::cout << "MenuState Resume" << std::endl;
}

void MenuState::HandleEvents( GameEngine& game )
{
	sf::Event event;

	if( game.screen.pollEvent( event ) )
	{
		switch( event.type )
		{
			case sf::Event::Closed:
				game.Quit();
				break;

			case sf::Event::KeyPressed:
				switch( event.key.code )
				{
					case sf::Keyboard::Escape:
						game.PopState();
						break;
				}
				break;
		}
	}
}

void MenuState::Update( GameEngine& game ) 
{

}

void MenuState::Draw( GameEngine& game )
{
	// Clear the previous drawing
	game.screen.clear();
	game.screen.draw( bg );
	game.screen.display();
}

