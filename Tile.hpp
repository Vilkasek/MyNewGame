#include "raylib.h"

struct Tile
{
    Texture2D tex = { 0 };

    void init()
    {
        tex = LoadTexture("./Graphics/Environment/Ground.png");
    }

    void deinit()
    {
        UnloadTexture(tex);
    }
};