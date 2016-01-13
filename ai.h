//generally creates its own thread and may use GPU for math
class Game;

class AIManager {
    Game* game;
public:
    AIManager (Game*);
};
