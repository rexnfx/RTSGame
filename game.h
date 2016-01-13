#include <Windows.h>
#include "graphics.h"
#include "gameinput.h"
#include "player.h"
#include "networkManager.h"

class Game {
    InputManager* inputManager;
    GraphicsManager* graphicsManager;
    Player* player1;
    NetworkManager* networker;
    static const int ticksPerSecond = 25;
    static const int skipTicks = 1000 / ticksPerSecond;
    static const int maxFrameskip = 5;
    DWORD nextGameTick;
    int loops;
    float interpolation;
    bool running;
public:
    Game();
    void run();
    bool isRunning() {
        return running;
    }
};
