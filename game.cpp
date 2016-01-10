//game loop
#include "game.h"
#include <Windows.h>

Game::Game() {
 inputManager = new InputManager;
 graphicsManager = new GraphicsManager;
}

void Game::run() {
	while (running) {
		//throttle the game
		//throttling code
		
		inputManager.handleinput(this);
		
		grahicsManager.render(this);
	}
}
