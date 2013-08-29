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
	GameEngine( const std::string& title, const unsigned int width = 640, const unsigned int height = 480, const unsigned int bpp = 32, const bool fullscreen = false );

	void run( std::unique_ptr<GameState> state );

	void nextState();
	void lastState();

	void update();
	void draw();

	bool running() { return m_running; }
	void quit() { m_running = false; }

	template <typename T>
	std::unique_ptr<T> build( bool replace = true );

	sf::RenderWindow screen;

private:
	// the stack of states
	std::stack<std::unique_ptr<GameState> > m_states;
	bool m_resume;

	bool m_running;
	bool m_fullscreen;
};

template <typename T>
std::unique_ptr<T> GameEngine::build( bool replace )
{
	return std::move( std::unique_ptr<T>( new T( *this, replace ) ) );
}

#endif // GAMEENGINE_HPP
