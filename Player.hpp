// Including raylib
#include "raylib.h"

// Including string for testing
#include <iostream>

// We need this to save direction info
enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

// Player structure
struct Player
{
    // Movement speed and stamina for actions
    float speed = 7.f;
    float stamina = 1.f;

    // Textures array
    Texture2D tex[4] = { 0 };

    // Position and velocity
    Vector2 position = { 0 };
    Vector2 velocity = { 0 };

    // Init direction
    Direction dir = Direction::LEFT;

    // Init Player
    void init()
    {
        // Load textures to array
        tex[0] = LoadTexture("./Graphics/Player/Idle/Player-Right.png");
        tex[1] = LoadTexture("./Graphics/Player/Idle/Player-Left.png");
        tex[2] = LoadTexture("./Graphics/Player/Idle/Player-Up.png");
        tex[3] = LoadTexture("./Graphics/Player/Idle/Player-Down.png");

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
        // Sprinting
        if(IsKeyDown(KEY_LEFT_SHIFT) && stamina > 0) 
        {
            speed = 15.f;
        }
        else speed = 7.f;

        // Vertical movement and changing direction
        if(IsKeyDown(KEY_W)) 
        {
            velocity.y = -1;
            dir = Direction::UP;
        }
        else if(IsKeyDown(KEY_S)) 
        {
            velocity.y = 1;
            dir = Direction::DOWN;
        }
        else velocity.y = 0;

        // Horizontal movement and changing direction
        if(IsKeyDown(KEY_A)) 
        {
            velocity.x = -1;
            dir = Direction::LEFT;
        }
        else if(IsKeyDown(KEY_D)) 
        {
            velocity.x = 1;
            dir = Direction::RIGHT;
        }
        else velocity.x = 0;

        // Changing position
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

    // Render Player
    void render()
    {
        // Drawing Player texture depended on direction
        switch(dir)
        {
            case Direction::RIGHT:
                DrawTextureEx(tex[0], position, 0.f, 2.f, WHITE);
                break;
            case Direction::LEFT:
                DrawTextureEx(tex[1], position, 0.f, 2.f, WHITE);
                break;
            case Direction::UP:
                DrawTextureEx(tex[2], position, 0.f, 2.f, WHITE);
                break;
            case Direction::DOWN:
                DrawTextureEx(tex[3], position, 0.f, 2.f, WHITE);
                break;
        }
    }

    // Deinitialization
    void deinit()
    {
        for(auto i : tex) UnloadTexture(i);
    }
};