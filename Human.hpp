// Including raylib and directions
#include "raylib.h"
#include "Directions.hpp"

// Human structure
struct Human
{
    // Movement speed and health
    float speed = { 0 };
    float health = { 0 };

    // Level
    int level = { 0 };

    // Direction
    Direction dir = Direction::RIGHT;

    // Human updating
    void update() {}

    // Human render
    void render() {}

    // Human deinit
    void deinit() {}
};