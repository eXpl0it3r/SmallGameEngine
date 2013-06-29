#include "GameEngine.hpp"
#include "IntroState.hpp"

int main ()
{
	// initialize the engine
	GameEngine game( "Engine Test v2.0" );
	game.run( game.build<IntroState>( true ) );
	sf::Clock clock;

	// main loop
	while( game.running() )
	{
		sf::Time elapsed = clock.restart();
		game.nextState();
		game.update(elapsed);
		game.draw(elapsed);
	}

	// leaving the scope of 'game' will cleanup the engine
    return 0;
}

