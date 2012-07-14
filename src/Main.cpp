#include "GameEngine.hpp"
#include "IntroState.hpp"

int main ()
{
	// initialize the engine
	GameEngine game( "Engine Test v1.0" );

	// load the intro
	game.ChangeState( std::move( IntroState::Instance() ) );

	// main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	// Leaving the scope of 'game' will cleanup the engine
    return 0;
}
