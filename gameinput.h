#include <windows.h>
class Game;

class InputManager {
public:
    InputManager (Game* game);
    void handleInput();
};