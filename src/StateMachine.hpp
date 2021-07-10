#pragma once

#include "State.hpp"

#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>

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

	[[nodiscard]] bool running() const;
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
	auto new_state = std::unique_ptr<T>{ nullptr };

	try
	{
		new_state = std::make_unique<T>(machine, window, replace);
	}
	catch(std::runtime_error& exception)
	{
		std::cout << "Creation of new state was unsuccessful\n";
		std::cout << exception.what() << std::endl;
	}

	return new_state;
}
