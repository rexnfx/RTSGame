#include <Windows.h>
#include "graphics.h"
#include "gameinput.h"
#include "player.h"
#include "networkManager.h"

class Game {
    InputManager* inputManager;
    GraphicsManager* graphicsManager;
<<<<<<< HEAD
    Player* player1;
    NetworkManager* networker;
    bool running;
    static const int ticksPerSecond = 25;
    static const int skipTicks = 1000 / ticksPerSecond;
    static const int maxFrameskip = 5;
    DWORD nextGameTick;
    int loops;
    float interpolation;
=======
    bool running;
>>>>>>> 3dd28a402433a7da666b7c46f2ceb2146db55b86
public:
    Game();
    void run();
    bool isRunning() {
        return running;
    }
};
