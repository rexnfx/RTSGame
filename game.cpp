//game loop
#include "game.h"
#include <Windows.h>

Game::Game() {
    inputManager = new InputManager(this);
    graphicsManager = new GraphicsManager(this);
}

void Game::run() {
    while(running) {
        //throttle the game
        //throtling code

        inputManager->handleInput();

        graphicsManager->render();
    }
}
