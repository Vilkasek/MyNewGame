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
    Init components:
    - Window
    - Camera
*/
void Game::initWin()
{
    // Create window
    InitWindow(sWidth, sHeight, "Zombie survivalist");

    // Limiting FPS
    SetTargetFPS(60);
}
void Game::initCamera(Camera2D &cam, int w, int h)
{
    cam.target = (Vector2){ player.position.x + 64, player.position.y + 64 };
    cam.offset = (Vector2){ (float)w / 2 , (float)h / 2 };
    cam.rotation = 0;
    cam.zoom = 1;
}

// Main init function
void Game::init()
{
    // Init game components
    initWin();
    initCamera(camera, sWidth, sHeight);

    // Initial game state
    GameState gameState = GameState::GAME;

    // Init game objects
    player.init();
    tilemap.init();
}

/*
    Update components:
    - Camera
*/
void Game::updateCamera(Camera2D& cam, const Tilemap& tilemap, int screenWidth, int screenHeight)
{
    tileSize = tilemap.tileSize;
    mapWidth = tilemap.mapWidth * tileSize;
    mapHeight = tilemap.mapHeight * tileSize;

    cam.target = (Vector2){player.position.x + 64, player.position.y + 64};

    // Calculate map boundaries in pixels
    mapLeft = 0;
    mapRight = mapWidth - screenWidth;
    mapTop = 0;
    mapBottom = mapHeight - screenHeight;

    // Clamp camera position inside map
    if (cam.target.x < mapLeft + cam.offset.x)
        cam.target.x = mapLeft + cam.offset.x;
    else if (cam.target.x > mapRight + cam.offset.x)
        cam.target.x = mapRight + cam.offset.x;

    if (cam.target.y < mapTop + cam.offset.y)
        cam.target.y = mapTop + cam.offset.y;
    else if (cam.target.y > mapBottom + cam.offset.y)
        cam.target.y = mapBottom + cam.offset.y;
}

/*
    Update states:
    - Game
*/
void Game::updateGame()
{
    // TODO: player, enemy, world, camera, music, etc.
    player.update(mapWidth, mapHeight);
    updateCamera(camera, tilemap, sWidth, sHeight);
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
    tilemap.render();
    player.render();
}

// Main render
void Game::render()
{
    BeginDrawing();

    // Begin 2D mode to use camera
    BeginMode2D(camera);

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
