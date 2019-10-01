#include "game.h"



bool KEYBOARD[MAX_KEYSTATE] = { false };

Game::Game(const String title, const Vector2u size) : Ari(PVector(100,200))
{
	window.create(sf::VideoMode(size.x, size.y), title);

}


Game::~Game()
{
}

void Game::handleKeyMovement(Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
		case Keyboard::W:
			KEYBOARD[K::KState::Up] =isPressed;
			break;
		case Keyboard::A:
			KEYBOARD[K::KState::Left] = isPressed;
			break;
		case Keyboard::S:
			KEYBOARD[K::KState::Down] = isPressed;
			break;
		case Keyboard::D:
			KEYBOARD[K::KState::Right] = isPressed;
			break;
		case Keyboard::Z:
			KEYBOARD[K::KState::Skill1] = isPressed;
			break;
		case Keyboard::C:
			KEYBOARD[K::KState::Skill2] = isPressed;
			break;
		default:
			break;
	}
}

// update game;
void Game::update()
{
	Ari.update();
}
// draw render ;
void Game::render()
{
	window.clear();
	Ari.render(window);
	window.display();

}


// processing 
void Game::process()
{
	while (window.pollEvent(event)) {
		switch (event.type)
		{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				handleKeyMovement(event.key.code , true);
				break;
			case Event::KeyReleased:
				handleKeyMovement(event.key.code, false);
				break;
		}
	}

}

void Game::run()
{
	while (window.isOpen())
	{
		process();
		update();
		render();	
	}

}


