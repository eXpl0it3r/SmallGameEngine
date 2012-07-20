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

	void Run( std::unique_ptr<GameState> state );

	void NextState();
	void LastState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	template <typename T>
	std::unique_ptr<T> Build( bool replace = true );

	sf::RenderWindow screen;

private:
	// the stack of states
	std::stack<std::unique_ptr<GameState> > states;

	bool m_running;
	bool m_fullscreen;
};

template <typename T>
std::unique_ptr<T> GameEngine::Build( bool replace )
{
	return std::move( std::unique_ptr<T>( new T( replace ) ) );
}

#endif // GAMEENGINE_HPP
