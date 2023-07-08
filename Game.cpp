// Include Game header
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
    // Init game components
    initWin();

    // Initial game state
    GameState gameState = GameState::GAME;

    // Init game objects
    player.init(sWidth, sHeight);
    tilemap.init();
}

/*
    Update states:
    - Game
*/
void Game::updateGame()
{
    // TODO: player, enemy, world, camera, music, etc.
    player.update();
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
    // Clear old frame
    ClearBackground(BLACK);

    // Render game objects
    for(int i = 0; i < 2; i++) tilemap.render(i);
    player.render();
}

// Main render
void Game::render()
{
    BeginDrawing();

    // Begin 2D mode to use camera
    BeginMode2D(player.camera);

    switch(gameState)
    {
        case GameState::GAME:
            renderGame();
            break;
    }

    // End that mode
    EndMode2D();

    EndDrawing();
}

// Deinitialization
void Game::deinit()
{
    // Deinit objects
    player.deinit();
    tilemap.deinit();

    // Close window
    CloseWindow();
}
