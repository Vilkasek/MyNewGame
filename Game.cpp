#include "Game.hpp"

Game::Game()
{
    // Initialization
    init();
}
Game::~Game()
{
    // Deinitialization
    deinit();
}

// Main game loop
void Game::run()
{
    while(!WindowShouldClose())
    {
        // Update game
        update();

        // Render game
        render();
    }
}

/*
    Init objects:
    - Window
*/
void Game::initWin()
{
    // Create window
    InitWindow(sWidth, sHeight, "Zombie survivalist");

    // Limiting FPS
    SetTargetFPS(60);
}

// Main init function
void Game::init()
{
    initWin();

    // Initial game state
    GameState gameState = GameState::GAME;
}

/*
    Update states:
    - Game
*/
void Game::updateGame()
{
// TODO: player, enemy, world, camera, music, etc.
}

// Main udpate
void Game::update()
{
    switch(gameState)
    {
        case GameState::GAME:
            updateGame();
    }
}

/*
    Render states:
    - Game
*/
void Game::renderGame()
{
    ClearBackground(WHITE);
}

// Main render
void Game::render()
{
    BeginDrawing();

    switch(gameState)
    {
        case GameState::GAME:
            renderGame();
    }

    EndDrawing();
}

// Deinitialization
void Game::deinit()
{
    CloseWindow();
}
