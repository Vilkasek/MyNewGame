#include "raylib.h"

struct Tile
{
    // Initialize texture variable
    Texture2D tex = { 0 };

    // Init tile
    void init()
    {
        // Load texture from file
        tex = LoadTexture("./Graphics/Environment/Ground.png");
    }

    // Unloading texture
    void deinit()
    {
        UnloadTexture(tex);
    }
};