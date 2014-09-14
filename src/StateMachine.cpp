#include "StateMachine.hpp"
#include "State.hpp"

#include <iostream>
#include <memory>

StateMachine::StateMachine()
: m_resume( false )
, m_running( false )
{
	std::cout << "StateMachine Init" << std::endl;
}

void StateMachine::run( std::unique_ptr<State> state )
{
	m_running = true;

	m_states.push( std::move( state ) );
}

void StateMachine::nextState()
{
    if(m_resume)
    {
        // Cleanup the current state
        if ( !m_states.empty() )
        {
            m_states.pop();
        }

        // Resume previous state
        if ( !m_states.empty() )
        {
            m_states.top()->resume();
        }

        m_resume = false;
    }

	// There needs to be a state
	if ( !m_states.empty() )
	{
		std::unique_ptr<State> temp = m_states.top()->next();

		// Only change states if there's a next one existing
		if( temp != nullptr )
		{
			// Replace the running state
			if( temp->isReplacing() )
				m_states.pop();
			// Pause the running state
			else
				m_states.top()->pause();

			m_states.push( std::move( temp ) );
		}
	}
}

void StateMachine::lastState()
{
    m_resume = true;
}

void StateMachine::update()
{
	// Let the state update the game
	m_states.top()->update();
}

void StateMachine::draw()
{
	// Let the state draw the screen
	m_states.top()->draw();
}
