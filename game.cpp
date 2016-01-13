//game loop
#include "game.h"

Game::Game() {
    inputManager = new InputManager (this);
    graphicsManager = new GraphicsManager (this);
    nextGameTick = GetTickCount();
}

void Game::run() {
    if (running) {
        //throttle the game
        //throtling code
        nextGameTick = GetTickCount();
        loops = 0;
        while (GetTickCount() > nextGameTick && loops < maxFrameskip) {
            inputManager->handleInput();

            //updateState

            nextGameTick += skipTicks;
            loops++;
        }

        interpolation = float (GetTickCount() + skipTicks - nextGameTick)
                        / float (skipTicks);

        graphicsManager->render (interpolation);
    }
}
