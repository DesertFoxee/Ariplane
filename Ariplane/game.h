#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "EventState.h"
#include "Ariplane.h"



using namespace sf;



class Game
{
public:
	Game(const String title = "None"  ,const Vector2u size = Vector2u(DEFAULT_SCREEN_W , DEFAULT_SCREEN_H));
	~Game();
	virtual void run();
private:
	virtual void update();
	virtual void render() ;
	virtual void process();

	void handleKeyMovement(Keyboard::Key key , bool isPressed );
	sf::RenderWindow window;
	sf::Event event;


	Ariplane Ari;
};



#endif // !GAME_H


