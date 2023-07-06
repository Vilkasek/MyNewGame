// Including raylib
#include "raylib.h"

// Player structure
struct Player
{
    // We need this to save direction info
    enum class Direction
    {
        LEFT,
    };

    // Movement speed
    float speed = 7;

    // Texture
    Texture2D tex = { 0 };

    // Position and velocity
    Vector2 position = { 0 };
    Vector2 velocity = { 0 };

    // Init direction
    Direction dir = Direction::LEFT;

    // Init Player
    void init()
    {
        // Load texture
        tex = LoadTexture("./Graphics/Player/Idle/Bot.png");

        // Starting position
        position = { 500.f, 300.f };

        // Initial velocity
        velocity = { 0.f, 0.f };

        // Initial direction
        Direction dir = Direction::LEFT;
    }

    // Update Player
    void update()
    {
        // vertical movement
        if(IsKeyDown(KEY_W)) velocity.y = -1;
        else if(IsKeyDown(KEY_S)) velocity.y = 1;
        else velocity.y = 0;

        // Horizontal movement
        if(IsKeyDown(KEY_A)) velocity.x = -1;
        else if(IsKeyDown(KEY_D)) velocity.x = 1;
        else velocity.x = 0;

        // Changing position
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    // Render Player
    void render()
    {
        // Drawing Player texture
        DrawTextureEx(tex, position, 0.f, 2.f, WHITE);
    }

    // Deinitialization
    void deinit()
    {
        UnloadTexture(tex);
    }
};