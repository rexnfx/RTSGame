//game loop
#include "graphics.h"

class Game {
    GraphicsManager* graphicsManager;
	bool running;
public:
    Game();
    void run();
	bool isRunning() { return running; }
};