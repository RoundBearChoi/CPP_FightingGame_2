#include "AllocationCount.h"
//class LastCounter { public: LastCounter() { std::cout << "starting allocation count: " << numObjects << std::endl; } ~LastCounter() { std::cout << "final allocation count: " << numObjects << std::endl; } };
//LastCounter last;

#include "Game.h"

int main()
{
	RB::Game game;

	game.Run();
	
	return 0;
}