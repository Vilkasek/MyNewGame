// Include tile for build map
#include "Tile.hpp"

// Include vector for dynamic array
#include <vector>

// Map struct
struct Tilemap
{
    // We need object to put into array
    Tile tile;

    // Position of tile
    Vector2 position = { 0 };

    // Initialize map
    void init() 
    {
        // Init tile object
        tile.init();

        // Initial position
        position = { 0, 0 };

        // Save tiles into array
        // for(int i = 0; i <= 10; i++) tiles[i] = tile;
    }

    // Rendering tilemap
    void render(int i) 
    {
        // Render map tile
        DrawTextureEx(tile.tex, (Vector2){position.x + (tile.tex.width * 6 * i), position.y}, 0.f, 6.f, WHITE);
    }

    // Deinit
    void deinit()
    {
        tile.deinit();
    }
};