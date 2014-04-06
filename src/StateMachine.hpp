#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <memory>
#include <stack>
#include <string>

class GameState;

namespace sf
{
	class RenderWindow;
}

class StateMachine
{
public:
	StateMachine();

	void run( std::unique_ptr<GameState> state );

	void nextState();
	void lastState();

	void update();
	void draw();

	bool running() { return m_running; }
	void quit() { m_running = false; }

	template <typename T>
	static std::unique_ptr<T> build( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

private:
	// The stack of states
	std::stack<std::unique_ptr<GameState>> m_states;

	bool m_resume;
	bool m_running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build( StateMachine& machine, sf::RenderWindow& window, bool replace )
{
	return std::move( std::unique_ptr<T>( new T( machine, window, replace ) ) );
}

#endif // GAMEENGINE_HPP
