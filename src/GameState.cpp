#include "GameState.hpp"

GameState::GameState( StateMachine& machine, sf::RenderWindow &window, bool replace )
: m_machine( machine )
, m_window( window )
, m_replacing( replace )
{

}

GameState::~GameState()
{

}

std::unique_ptr<GameState> GameState::next()
{
	return std::move( m_next );
}

bool GameState::isReplacing()
{
	return m_replacing;
}
