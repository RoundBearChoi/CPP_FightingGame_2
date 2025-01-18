#include "AllocationCount.h"
//class LastCounter { public: LastCounter() { std::cout << "starting allocation count: " << numObjects << std::endl; } ~LastCounter() { std::cout << "final allocation count: " << numObjects << std::endl; } };
//LastCounter last;

#include "Game.h"

int main()
{
	RB::Game game;

	game.Run();
	
	std::cout << "ending program.. press enter to exit.." << std::endl;
	std::cin.get();

	return 0;
}