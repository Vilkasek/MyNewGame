#include "raylib.h"

struct Structure
{
    // Texture and collision box
    Texture2D tex = { 0 };
    Rectangle collBox = { 0 };

    void render();
};