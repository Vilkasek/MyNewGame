// Include raylib
#include <raylib.h>

// Tile struct
struct Tile
{
    // Texture variable
    Texture2D tex = { 0 };

    // Initialize
    void init()
    {
        // Load texture
        tex = LoadTexture("./Graphics/Environment/Ground.png");
    }

    // Deinit
    void deinit()
    {
        // Unload texture
        UnloadTexture(tex);
    }
};