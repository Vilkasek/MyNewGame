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

    // Camera initializing
    camera.target = (Vector2){ player.position.x + 64, player.position.y + 64 };
    camera.offset = (Vector2){ (float)sWidth / 2 , (float)sHeight / 2 };
    camera.rotation = 5;
    camera.zoom = 1;

    // Initial game state
    GameState gameState = GameState::GAME;

    // Init game objects
    player.init();
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
    
    // Update camera
    camera.target = player.position;
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

    switch(gameState)
    {
        case GameState::GAME:
            renderGame();
            break;
    }

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
