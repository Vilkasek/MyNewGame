#include "Tile.hpp"

struct Tilemap
{
    // Map dimensions
    const int mapWidth = 10;
    const int mapHeight = 10;

    // Tile size
    const int tileSize = 512;

    // Create 2D array
    Tile tiles[10][10];

    // Initialize map tiles
    void init()
    {
        for (int x = 0; x < mapWidth; x++)
        {
            for (int y = 0; y < mapHeight; y++)
            {
                tiles[x][y].init();
            }
        }
    }

    // Render all storaged inside array tiles
    void render()
    {
        for (int x = 0; x < mapWidth; x++)
        {
            for (int y = 0; y < mapHeight; y++)
            {
                DrawTextureEx(tiles[x][y].tex, { (float)x * tileSize, (float)y * tileSize }, 0.f, 4.f, WHITE);
            }
        }
    }

    // Unloading from memory all tiles
    void deinit()
    {
        for (int x = 0; x < mapWidth; x++)
        {
            for (int y = 0; y < mapHeight; y++)
            {
                tiles[x][y].deinit();
            }
        }
    }
};
