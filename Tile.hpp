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
        tex = LoadTexture("./Graphics/Environment/Groung.png");
    }
};