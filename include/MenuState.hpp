#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine;

class MenuState : public GameState
{
public:
	MenuState( bool replace = true );
	~MenuState();

	void Pause();
	void Resume();

	void HandleEvents( GameEngine& game );
	void Update( GameEngine& game );
	void Draw( GameEngine& game );

private:

	sf::Texture bgTex;
	sf::Sprite bg;
};

#endif // MENUSTATE_HPP
