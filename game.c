#include "raylib.h"

int main(){
    InitWindow (800, 600, "love jump!");
    SetTargetFPS(60);

    int y = 300;
    int ys = 15;

    int tx = 800;

    while( ! WindowShouldClose() ){
        BeginDrawing();
            y = y - ys;
            if (IsKeyPressed(KEY_SPACE)){
                ys = 15;
            }
            y = y - ys ;
            if (600-40 < y){
                y = 600 - 40;
                ys = 0;
            }else{
                ys = ys - 1;
            }

            tx = tx - 2;
            int n = CheckCollisionCircles((Vector2){400,y}, 40, (Vector2){tx, 600-40}, 40);

            if(n){
                break;
            }
            ClearBackground(GREEN);
            DrawCircle(tx, 600-40, 40, WHITE);
            DrawCircle(400,y,40,YELLOW);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;

}