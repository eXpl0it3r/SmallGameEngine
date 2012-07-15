#include <iostream>
#include "PlayState.hpp"
#include "MenuState.hpp"
#include "GameEngine.hpp"

PlayState::PlayState()
{
	bgTex.loadFromFile("img/play.bmp");

	bg.setTexture(bgTex, true);

	std::cout << "PlayState Init" << std::endl;
}

PlayState::~PlayState()
{
	std::cout << "PlayState Cleanup" << std::endl;
}

void PlayState::Pause()
{
	std::cout << "PlayState Pause" << std::endl;
}

void PlayState::Resume()
{
	std::cout << "PlayState Resume" << std::endl;
}

void PlayState::HandleEvents(GameEngine& game)
{
	sf::Event event;

	if (game.screen.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				game.Quit();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						game.Quit();
						break;
					case sf::Keyboard::M:
						game.PushState( game.Build<MenuState>() );
						break;
				}
				break;
		}
	}
}

void PlayState::Update(GameEngine& game)
{

}

void PlayState::Draw(GameEngine& game)
{
	// Clear the previous drawing
	game.screen.clear();
	game.screen.draw(bg);
	game.screen.display();
}

