//graphics objects
class Game;

class GraphicsManager {
    Game* game;
public:
    GraphicsManager (Game*);
    void render (float interpolation);
};