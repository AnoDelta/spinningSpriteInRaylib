#include <stdio.h>
#include "raylib.h"

// SETTINGS
// (made to make customiziation easier)

#define WINDOWNAME "your budget animation"
#define WINDOWWIDTH 700
#define WINDOWHEIGHT 500

#define FPS 165

#define SPINSPEED 2.0f

int main()
{
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, WINDOWNAME);

    SetTargetFPS(FPS);

    // SPRITE DATA
    Texture texture = LoadTexture("Char Concept with detail.png");

    float rotation = 0.0f;

    float x = WINDOWWIDTH / 2 - texture.width / 2;
    float y = WINDOWHEIGHT / 2 - texture.height / 2;

    float dx = 1.0f;
    float dy = 1.0f;

    //MAIN LOOP
    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Draws the hitbox
        DrawRectangle(
                x,
                y,
                texture.width,
                texture.height,
                WHITE);

        // Draws the image using raylib
        DrawTexturePro(
                texture,

                // The part of the image we are taking
                (Rectangle)
                {0,0,texture.width,texture.height},

                // The place we draw in on the screen
                (Rectangle)
                {(x += dx) + texture.width / 2,
                (y += dy) + texture.height / 2,
                texture.width,
                texture.height},

                // The location where we spin the sprite
                (Vector2){texture.width / 2,texture.height / 2},

                rotation += SPINSPEED,
                WHITE); // <- the color modification on the sprite

        // changes the direciton of the player if they hit the side of the wall
        if (x + texture.width > WINDOWWIDTH)
        {
            x = WINDOWWIDTH - texture.width;
            dx *= -1;
        }
        else if (x < 0)
        {
            x = 0;
            dx *= -1;
        }

        if (y + texture.height > WINDOWHEIGHT)
        {
            y = WINDOWHEIGHT - texture.height;
            dy *= -1;
        }
        else if (y < 0)
        {
            y = 0;
            dy *= -1;
        }

        EndDrawing();
    }

    // ENDING THE PROGRAM
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
