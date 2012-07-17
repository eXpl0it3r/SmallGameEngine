#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine;

class PlayState : public GameState
{
public:
	PlayState( bool replace = true );
	~PlayState();

	void Pause();
	void Resume();

	void HandleEvents( GameEngine& game );
	void Update( GameEngine& game );
	void Draw( GameEngine& game );

private:
	sf::Texture bgTex;
	sf::Sprite bg;
};

#endif // PLAYSTATE_HPP
