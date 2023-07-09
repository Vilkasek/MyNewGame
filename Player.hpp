#include "raylib.h"
#include "raymath.h"
#include "Directions.hpp"

struct Player
{
    // Variables for movement
    float speed = 7.f;
    float stamina = 1.f;
    float health = 1.f;

    // Variables for animations
    int animFrames[4] = {0, 0, 0, 0};
    int currFrame = 0;
    int delay = 5;
    int frameCount = 0;

    // Prepare to create leveling system
    int level = 1;
    int exp = 0;

    // Variables for storing textures
    Image iAnims[4] = { 0 };
    Texture2D walkTex[4] = { 0 };
    Texture2D idleTex[4] = { 0 };

    // Offset for animation data
    unsigned int offset = 0;

    // Movement vectors
    Vector2 position = { 0 };
    Vector2 velocity = { 0 };

    // Collision box
    Rectangle collBox = { 0 };

    // Directions
    Direction dir = Direction::LEFT;

    void init()
    {
        // Load animations
        iAnims[0] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Right.gif", &animFrames[0]);
        iAnims[1] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Left.gif", &animFrames[1]);
        iAnims[2] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Up.gif", &animFrames[2]);
        iAnims[3] = LoadImageAnim("./Graphics/Player/Walk/Player-Anim-Down.gif", &animFrames[3]);

        // Load textures
        idleTex[0] = LoadTexture("./Graphics/Player/Idle/Player-Right.png");
        idleTex[1] = LoadTexture("./Graphics/Player/Idle/Player-Left.png");
        idleTex[2] = LoadTexture("./Graphics/Player/Idle/Player-Up.png");
        idleTex[3] = LoadTexture("./Graphics/Player/Idle/Player-Down.png");

        // Load animated textures
        for(int i = 0; i < 4; i++)
        {
            walkTex[i] = LoadTextureFromImage(iAnims[i]);
        }

        // Set default position, velocity and create collison box
        position = { 500.f, 300.f };
        velocity = { 0.f, 0.f };
        collBox = {position.x + 40, position.y, 48, 128};

        // Default direction
        dir = Direction::LEFT;
    }

    // Updating animations
    void animation(int i)
    {
        frameCount++;

        if(frameCount >= delay)
        {
            currFrame++;

            if(currFrame >= animFrames[i])
                currFrame = 0;

            offset = iAnims[i].width * iAnims[i].height * 4 * currFrame;

            UpdateTexture(walkTex[i], ((unsigned char *)iAnims[i].data) + offset);

            frameCount = 0;
        }
    }

    void update(int mapW, int mapH)
    {
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

        if(IsKeyDown(KEY_W) && collBox.y > 0)
        {
            velocity.y = -1;
            dir = Direction::UP;
            animation(2);
        }
        else if(IsKeyDown(KEY_S) && collBox.y + 128 < mapH)
        {
            velocity.y = 1;
            dir = Direction::DOWN;
            animation(3);
        }
        else velocity.y = 0;

        if(IsKeyDown(KEY_A) && collBox.x > 0)
        {
            velocity.x = -1;
            dir = Direction::LEFT;
            animation(1);
        }
        else if(IsKeyDown(KEY_D) && collBox.x + collBox.width < mapW)
        {
            velocity.x = 1;
            dir = Direction::RIGHT;
            animation(0);
        }
        else velocity.x = 0;

        velocity = Vector2Normalize(velocity);

        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

        collBox.x = position.x + 40;
        collBox.y = position.y;
    }

    void render()
    {
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
    }

    void deinit()
    {
        for(auto i : walkTex) UnloadTexture(i);
        for(auto i : idleTex) UnloadTexture(i);
        for(auto i : iAnims) UnloadImage(i);
    }
};
