// Including raylib and directions
#include "raylib.h"
#include "Directions.hpp"

// Including string for testing
#include <iostream>

// Defining things for animation
#define MAX_FR_DELAY 20
#define MIN_FR_DELAY 1

// Player structure
struct Player
{
    // Movement speed, stamina for actions, 
    // health
    float speed = 7.f;
    float stamina = 1.f;
    float health = 1.f;

    // Animation frames
    int animFrames = 0;
    
    // Level and experience
    int level = 1;
    int exp = 0;

    // Image to import animated sprite
    Image iAnims[4] = { 0 };

    // Textures array
    Texture2D idleTex[4] = { 0 };

    // Position and velocity
    Vector2 position = { 0 };
    Vector2 velocity = { 0 };

    // Collision box
    Rectangle collBox = { 0 };

    // Init direction
    Direction dir = Direction::LEFT;

    // Init Player
    void init()
    {
        // Load textures to array
        idleTex[0] = LoadTexture("./Graphics/Player/Idle/Player-Right.png");
        idleTex[1] = LoadTexture("./Graphics/Player/Idle/Player-Left.png");
        idleTex[2] = LoadTexture("./Graphics/Player/Idle/Player-Up.png");
        idleTex[3] = LoadTexture("./Graphics/Player/Idle/Player-Down.png");

        // Starting position
        position = { 500.f, 300.f };

        // Initial velocity
        velocity = { 0.f, 0.f };

        // Init collbox
        collBox = {position.x + 40, position.y, 48, 128};

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
        // and clamp player
        if(IsKeyDown(KEY_W) && collBox.y > 0) 
        {
            velocity.y = -1;
            dir = Direction::UP;
        }
        else if(IsKeyDown(KEY_S) && collBox.y + collBox.height < 720) 
        {
            velocity.y = 1;
            dir = Direction::DOWN;
        }
        else velocity.y = 0;

        // Horizontal movement and changing direction
        // and clamp player
        if(IsKeyDown(KEY_A) && collBox.x > 0) 
        {
            velocity.x = -1;
            dir = Direction::LEFT;
        }
        else if(IsKeyDown(KEY_D) && collBox.x + collBox.width < 1280)
        {
            velocity.x = 1;
            dir = Direction::RIGHT;
        }
        else velocity.x = 0;

        // Changing position
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

        // Udpating collbox position
        collBox.x = position.x + 40;
        collBox.y = position.y;
    }

    // Render Player
    void render()
    {
        // Drawing Player texture depended on direction
        switch(dir)
        {
            case Direction::RIGHT:
                DrawTextureEx(idleTex[0], position, 0.f, 2.f, WHITE);
                break;
            case Direction::LEFT:
                DrawTextureEx(idleTex[1], position, 0.f, 2.f, WHITE);
                break;
            case Direction::UP:
                DrawTextureEx(idleTex[2], position, 0.f, 2.f, WHITE);
                break;
            case Direction::DOWN:
                DrawTextureEx(idleTex[3], position, 0.f, 2.f, WHITE);
                break;
        }

        // For testing render collbox
        // DrawRectangle(collBox.x, collBox.y, collBox.width, collBox.height, WHITE);
    }

    // Deinitialization
    void deinit()
    {
        // For each loop for unloading things
        for(auto i : idleTex) UnloadTexture(i);
    }
};