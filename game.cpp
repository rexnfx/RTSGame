//game loop
#include "game.h"

Game::Game() {
<<<<<<< HEAD
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
=======
    inputManager = new InputManager(this);
    graphicsManager = new GraphicsManager(this);
}

void Game::run() {
    while(running) {
        //throttle the game
        //throtling code

        inputManager->handleInput();

        graphicsManager->render();
>>>>>>> 3dd28a402433a7da666b7c46f2ceb2146db55b86
    }
}
