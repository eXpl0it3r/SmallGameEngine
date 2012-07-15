#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine;

class IntroState : public GameState
{
public:
	IntroState();
	~IntroState();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine& game);
	void Update(GameEngine& game);
	void Draw(GameEngine& game);

private:
	sf::Texture bgTex;
	sf::Sprite bg;
	sf::RectangleShape fader;
	sf::Color alpha;
};

#endif // INTROSTATE_HPP
