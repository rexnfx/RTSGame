//game loop
#include "game.h"
#include <Windows.h>

Game::Game() {

}

void Game::run() {
	while (running) {
		//throttle the game
		//throttling code
		
		inputManager.handle();
		
		grahicsManager.render(this);
	}
}
