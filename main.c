#include <stdio.h>
#include "raylib.h"

#define WINDOWNAME "your budget animation"
#define WINDOWWIDTH 700
#define WINDOWHEIGHT 500

#define SPINSPEED 2.0f

int main()
{
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, WINDOWNAME);

    SetTargetFPS(165);

    Texture texture = LoadTexture("Char Concept with detail.png");

    float rotation = 0.0f;

    float x = WINDOWWIDTH / 2 - texture.width / 2;
    float y = WINDOWHEIGHT / 2 - texture.height / 2;

    float dx = 1.0f;
    float dy = 1.0f;

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Draws the hitbox
        // Draws the image
        DrawTexturePro(
                texture,
                (Rectangle)
                {0,0,texture.width,texture.height},
                (Rectangle)
                {x += dx, y += dy,
                texture.width,
                texture.height},
                (Vector2){texture.width / 2,texture.height / 2},
                rotation += SPINSPEED,
                WHITE);

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

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
