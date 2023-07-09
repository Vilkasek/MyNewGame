#pragma once

// Import structures with raylib
#include "Player.hpp"
#include "Tilemap.hpp"

// Game states
enum class GameState
{
    GAME,
};

// Define class
class Game
{
// Public methods
public:
    Game();
    ~Game();

    // Main game loop
    void run();

// Private methods
private:
    // Init components
    void initWin();
    void initCamera(Camera2D &cam, int w, int h);
    
    // Init everything
    void init();

    // Update components
    void updateCamera(Camera2D& cam, const Tilemap& tilemap, int screenWidth, int screenHeight);

    // Updates states
    void updateGame();

    // Game update
    void update();

    // Render states
    void renderGame();

    // Game render
    void render();

    // Deinitialization
    void deinit();

// Private vars
private:
    // Window sizes
    const int sWidth = 1280;
    const int sHeight = 720;

    // Initialization of states
    GameState gameState = GameState::GAME;

    // Create game objects
    Player player;
    Tilemap tilemap;

    // Create game components
    Camera2D camera = { 0 };

    // Create variables to control camera boundaries
    int tileSize = { 0 };
    int mapWidth = { 0 };
    int mapHeight = { 0 };

    int mapLeft = { 0 };
    int mapRight = { 0 };
    int mapTop = { 0 };
    int mapBottom = { 0 };
};