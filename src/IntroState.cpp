#include <memory>
#include <iostream>

#include "IntroState.hpp"
#include "PlayState.hpp"
#include "GameEngine.hpp"

IntroState::IntroState( bool replace ) : GameState( replace )
{
	bgTex.loadFromFile( "img/intro.bmp" );
	bg.setTexture( bgTex, true );

	// start off opaque
	alpha = sf::Color( 0, 0, 0, 255 );

	// fill the fader surface with black
	fader.setFillColor( alpha );
	fader.setSize( static_cast<sf::Vector2f>( bgTex.getSize() ) );

	std::cout << "IntroState Init" << std::endl;
}

IntroState::~IntroState()
{
	std::cout << "IntroState Cleanup" << std::endl;
}

void IntroState::Pause()
{
	std::cout << "IntroState Pause" << std::endl;
}

void IntroState::Resume()
{
	std::cout << "IntroState Resume" << std::endl;
}

void IntroState::HandleEvents( GameEngine& game )
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
					case sf::Keyboard::Space:
						next = game.Build<PlayState>( true );
						break;

					case sf::Keyboard::Escape:
						game.Quit();
						break;
				}
				break;
		}
	}
}

void IntroState::Update( GameEngine& game ) 
{
	if( alpha.a != 0 )
		alpha.a--;

	fader.setFillColor( alpha );
}

void IntroState::Draw( GameEngine& game ) 
{
	// Clear the previous drawing
	game.screen.clear();

	game.screen.draw( bg );

	// no need to draw if it's transparent
	if( alpha.a != 0 )
		game.screen.draw( fader );

	game.screen.display();
}

