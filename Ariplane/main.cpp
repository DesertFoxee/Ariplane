#include <iostream>
#include "game.h"



using namespace std;



int main()
{
	Game game("Game", Vector2u(800, 600));
	game.run();

	//sf::Clock clock;
	//sf::Time start ;
	//sf::Time start1 ;
	//while (true)
	//{
	//	start1 = clock.getElapsedTime() ;
	//	if (start1.asMilliseconds() >= 100) {
	//		cout << start1.asSeconds() << endl;
	//		clock.restart();
	//	}
	//
	//}
}
