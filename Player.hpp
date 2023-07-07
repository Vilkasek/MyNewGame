// Including raylib, raylib math and directions
#include "raylib.h"
#include "raymath.h"
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

    // Animation frames and current frame
    int animFrames[4] = {0, 0, 0, 0};
    int currFrame = 0;

    // Delay frame and frame counter
    int delay = 5;
    int frameCount = 0;
    
    // Level and experience
    int level = 1;
    int exp = 0;

    // Image to import animated sprite
    Image iAnims[4] = { 0 };

    // Textures array
    Texture2D idleTex[4] = { 0 };
    Texture2D walkTex[4] = { 0 };

    // Data offset
    unsigned int offset = 0;

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
        // Load images to array
        iAnims[0] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Right.gif", &animFrames[0]);
        iAnims[1] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Left.gif", &animFrames[1]);
        iAnims[2] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Up.gif", &animFrames[2]);
        iAnims[3] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Down.gif", &animFrames[3]);

        // Load textures to arrays
        idleTex[0] = LoadTexture("./Graphics/Player/Idle/Player-Right.png");
        idleTex[1] = LoadTexture("./Graphics/Player/Idle/Player-Left.png");
        idleTex[2] = LoadTexture("./Graphics/Player/Idle/Player-Up.png");
        idleTex[3] = LoadTexture("./Graphics/Player/Idle/Player-Down.png");

        for(int i = 0; i < 4; i++) walkTex[i] = LoadTextureFromImage(iAnims[i]);

        // Starting position
        position = { 500.f, 300.f };

        // Initial velocity
        velocity = { 0.f, 0.f };

        // Init collbox
        collBox = {position.x + 40, position.y, 48, 128};

        // Initial direction
        Direction dir = Direction::LEFT;
    }

    // Animation function
    void animation(int i)
    {
        // Counting frames
        frameCount++;

        if(frameCount >= delay)
        {
            // Change current frame
            currFrame++;

            // Protecting from move frames too far
            if(currFrame >= animFrames[i]) currFrame = 0;

            // Get memory offset
            offset = iAnims[i].width * iAnims[i].height * 4 * currFrame;

            // Udpate texture
            UpdateTexture(walkTex[i], ((unsigned char *)iAnims[i].data) + offset);

            // Frame reset
            frameCount = 0;
        }
    }

    // Update Player
    void update()
    {
        // Sprinting
        if(IsKeyDown(KEY_LEFT_SHIFT) && stamina > 0) 
        {
            speed = 15.f;
            delay = 2;
        }
        else
        {
            speed = 7.f;
            delay = 5;
        }
        // Vertical movement and changing direction
        // and clamp player
        if(IsKeyDown(KEY_W) && collBox.y > 0) 
        {
            velocity.y = -1;
            dir = Direction::UP;

            // Update good animation
            animation(2);
        }
        else if(IsKeyDown(KEY_S) && collBox.y + collBox.height < 720) 
        {
            velocity.y = 1;
            dir = Direction::DOWN;

            // Update good animation
            animation(3);
        }
        else velocity.y = 0;

        // Horizontal movement and changing direction
        // and clamp player
        if(IsKeyDown(KEY_A) && collBox.x > 0) 
        {
            velocity.x = -1;
            dir = Direction::LEFT;

            // Update good animation
            animation(1);
        }
        else if(IsKeyDown(KEY_D) && collBox.x + collBox.width < 1280)
        {
            velocity.x = 1;
            dir = Direction::RIGHT;

            // Update good animation
            animation(0);
        }
        else velocity.x = 0;

        // Normalizing velocity
        velocity = Vector2Normalize(velocity);

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
                if(velocity.x > 0) DrawTexture(walkTex[0], position.x, position.y, WHITE);
                else DrawTextureEx(idleTex[0], position, 0.f, 2.f, WHITE);
                break;
            case Direction::LEFT:
                if(velocity.x < 0) DrawTexture(walkTex[1], position.x, position.y, WHITE);
                else DrawTextureEx(idleTex[1], position, 0.f, 2.f, WHITE);
                break;
            case Direction::UP:
                if(velocity.y < 0) DrawTexture(walkTex[2], position.x, position.y, WHITE);
                else DrawTextureEx(idleTex[2], position, 0.f, 2.f, WHITE);
                break;
            case Direction::DOWN:
                if(velocity.y > 0) DrawTexture(walkTex[3], position.x, position.y, WHITE);
                else DrawTextureEx(idleTex[3], position, 0.f, 2.f, WHITE);
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
        for(auto i : walkTex) UnloadTexture(i);
        for(auto i : iAnims) UnloadImage(i);
    }
};
