#pragma once

#include "State.hpp"

#include <memory>
#include <stack>

namespace sf
{
	class RenderWindow;
}

class StateMachine
{
public:
	StateMachine();

	void run(std::unique_ptr<State> state);

	void nextState();
	void lastState();

	void update();
	void draw();

	bool running() const;
	void quit();

	template <typename T>
	static std::unique_ptr<T> build(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

private:
	// The stack of states
	std::stack<std::unique_ptr<State>> m_states;

	bool m_resume;
	bool m_running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine& machine, sf::RenderWindow& window, bool replace)
{
	return std::make_unique<T>(machine, window, replace);
}
