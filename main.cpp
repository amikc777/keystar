#include <iostream>
#include <raylib.h>

class GrandStaffRenderer { 
    public:
        GrandStaffRenderer(const char* imagePath) {
           grandStaffTexture = LoadTexture(imagePath);
        }
        ~GrandStaffRenderer(){
            UnloadTexture(grandStaffTexture);
        }

        void Draw() {
            DrawTexture(grandStaffTexture, 0, 0, WHITE);
        }
private:
    Texture2D grandStaffTexture;
};

int main(){
    const int screenWidth = 800;
    const int screenHeight = 600; 
    InitWindow(screenWidth, screenHeight, "KeyStar: The Guitar-Hero Style Piano App");

    // Reminder to insert the filepath of the asset being used.
    GrandStaffRenderer grandStaffRenderer("GrandStaff.jpg"); 

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        grandStaffRenderer.Draw(); // Image of the Grand Staff gets drawn.
        EndDrawing();
    }
    CloseWindow();
}
