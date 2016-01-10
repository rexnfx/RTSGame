//game loop
#include "graphics.h"

class Game {
	InputManager inputManager;
    GraphicsManager* graphicsManager;
	bool running;
public:
    Game();
    void run();
	bool isRunning() { return running; }
};
