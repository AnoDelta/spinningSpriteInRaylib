#include <stdio.h>
#include "raylib.h"

#define WINDOWNAME "your budget animation"
#define WINDOWWIDTH 700
#define WINDOWHEIGHT 500

int main()
{
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, WINDOWNAME);

    SetTargetFPS(165);

    Texture texture = LoadTexture("Char Concept with detail.png");

    float rotation = 0.0f;

    float x = WINDOWWIDTH / 2 - texture.width / 2;
    float y = WINDOWHEIGHT / 2 - texture.height / 2;

    Vector2 direction = {1.0f,1.0f};

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTexturePro(
                texture,
                (Rectangle)
                {0,0,texture.width,texture.height},
                (Rectangle)
                {x += 1.0f,
                WINDOWHEIGHT / 2 - texture.height / 2,
                texture.width,
                texture.height},
                (Vector2){texture.width / 2,texture.height / 2},
                rotation += 50.0f,
                WHITE);

        // changes the direciton of the player if they hit the side of the wall



        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
