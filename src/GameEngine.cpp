#include "GameEngine.hpp"

#include <iostream>
#include "GameState.hpp"

GameEngine::GameEngine(const std::string& title, const unsigned int width, const unsigned int height, const unsigned int bpp, const bool fullscreen) :
	m_fullscreen(fullscreen)
{
	int flags = 0;

	if(fullscreen)
		flags = sf::Style::Fullscreen;
	else
		flags = sf::Style::Default;

	// Create render window
	screen.create(sf::VideoMode(width, height, bpp), title, flags);
	screen.setFramerateLimit(30);

	m_running = true;

	std::cout << "GameEngine Init" << std::endl;
}

void GameEngine::ChangeState(std::unique_ptr<GameState> state) 
{
	// cleanup the current state
	if ( !states.empty() )
	{
		states.pop();
	}

	// store and init the new state
	states.push(std::move(state));
}

void GameEngine::PushState(std::unique_ptr<GameState> state)
{
	// pause current state
	if ( !states.empty() ) {
		states.top()->Pause();
	}

	// store and init the new state
	states.push(std::move(state));
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() )
	{
		states.pop();
	}

	// resume previous state
	if ( !states.empty() )
	{
		states.top()->Resume();
	}
}

void GameEngine::HandleEvents() 
{
	// let the state handle events
	states.top()->HandleEvents(*this);
}

void GameEngine::Update() 
{
	// let the state update the game
	states.top()->Update(*this);
}

void GameEngine::Draw() 
{
	// let the state draw the screen
	states.top()->Draw(*this);
}
