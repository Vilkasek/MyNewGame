#include "Tile.hpp"

struct Tilemap
{
    const int mapWidth = 10;
    const int mapHeight = 10;
    const int tileSize = 512;

    Tile tiles[10][10];

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
