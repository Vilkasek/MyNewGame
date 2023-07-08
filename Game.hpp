#pragma once

// Import structures with raylib
#include "Player.hpp"
#include "Human.hpp"
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
    // Init objects
    void initWin();
    
    // Init everything
    void init();

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

    // Create player
    Player player;
};