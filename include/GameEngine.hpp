#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <stack>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

class GameState;

class GameEngine
{
public:
	GameEngine(const std::string& title, const unsigned int width = 640, const unsigned int height = 480, const unsigned int bpp = 32, const bool fullscreen = false);

	void ChangeState(std::unique_ptr<GameState> state);
	void PushState(std::unique_ptr<GameState> state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	sf::RenderWindow screen;

private:
	// the stack of states
	std::stack<std::unique_ptr<GameState> > states;

	bool m_running;
	bool m_fullscreen;
};

#endif // GAMEENGINE_HPP
