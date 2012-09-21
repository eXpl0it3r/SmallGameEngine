#include "GameEngine.hpp"

#include <memory>
#include <iostream>
#include "GameState.hpp"

#include "IntroState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

GameEngine::GameEngine( const std::string& title, const unsigned int width, const unsigned int height, const unsigned int bpp, const bool fullscreen ) :
    m_resume( false ),
	m_running( false ),
	m_fullscreen( fullscreen )
{
	int flags = 0;

	if( fullscreen )
		flags = sf::Style::Fullscreen;
	else
		flags = sf::Style::Default;

	// Create render window
	screen.create( sf::VideoMode( width, height, bpp ), title, flags );
	screen.setFramerateLimit( 30 );

	std::cout << "GameEngine Init" << std::endl;
}

void GameEngine::run( std::unique_ptr<GameState> state )
{
	m_running = true;

	m_states.push( std::move( state ) );
}

void GameEngine::nextState()
{
    if(m_resume)
    {
        // cleanup the current state
        if ( !m_states.empty() )
        {
            m_states.pop();
        }

        // resume previous state
        if ( !m_states.empty() )
        {
            m_states.top()->resume();
        }

        m_resume = false;
    }

	// there needs to be a state
	if ( !m_states.empty() )
	{
		std::unique_ptr<GameState> temp = m_states.top()->next();

		// only change states if there's a next one existing
		if( temp != nullptr )
		{
			// replace the running state
			if( temp->isReplacing() )
				m_states.pop();
			// pause the running state
			else
				m_states.top()->pause();

			m_states.push( std::move( temp ) );
		}
	}
}

void GameEngine::lastState()
{
    m_resume = true;
}

void GameEngine::update()
{
	// let the state update the game
	m_states.top()->update();
}

void GameEngine::draw()
{
	// let the state draw the screen
	m_states.top()->draw();
}
