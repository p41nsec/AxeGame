#include "raylib.h"

int main(){
    int width {800};
    int height {450};
    int circle_Radius{25};
    int axe_lenght{50};
    InitWindow(width, height, "Axe Game");
    //circle coordinates
    int circle_x {200};
    int circle_y{200};
    //circle coordinates
    int l_circle_x{circle_x - circle_Radius};
    int r_circle_x{circle_x + circle_Radius};
    int u_circle_y{circle_y - circle_Radius};
    int b_circle_y{circle_y + circle_Radius};
    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_lenght};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_lenght};

    int direction{10};
    bool collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(collision_with_axe){
            DrawText("Game Over! press R to restart",400,200,20,RED);
            if (IsKeyDown(KEY_R)){
                collision_with_axe = false;
            }
        }else {
            //game logic start
            //update the edges 
            l_circle_x = circle_x - circle_Radius;
            r_circle_x = circle_x + circle_Radius;
            u_circle_y = circle_y - circle_Radius;
            b_circle_y = circle_y + circle_Radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_lenght;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_lenght;
            //update collision with axe
            collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x);

            DrawCircle(circle_x,circle_y,circle_Radius,BLUE);
            DrawRectangle(axe_x,axe_y,axe_lenght,axe_lenght,RED);

            //move axe
            axe_y += direction;
            if (axe_y > height || axe_y < 0){
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width){
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0){
                circle_x -= 10;
            }

            //game logic end
        }
        EndDrawing();
    }
}