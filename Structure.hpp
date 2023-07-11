#include "raylib.h"

struct Structure
{
    // Texture and collision box
    Texture2D tex = { 0 };
    Rectangle collBox = { 0 };

    // Position
    Vector2 pos = { 0 };

    // Initialing function
    void init();

    // Rendering function
    void render();

    void deinit()
    {
        UnloadTexture(tex);
    }
};