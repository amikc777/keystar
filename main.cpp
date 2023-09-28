#include <iostream>
#include <raylib.h>

// Hold off on the Note class now, and just get a Note rendered on the grand staff.

/*class Note {
public:
    Vector2 position;  // Position of the note on the screen

    Note(float x, float y) : position{ x, y } {}

    // void Render() const {
    //     // Draw a circle for the note at the specified position
    //     DrawCircleV(position, 20, RED);
    // }

    // Set the position of the note
    void SetPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }
};
*/
class Renderer {
public:
    Renderer(const char* imagePath) {
        Texture = LoadTexture(imagePath);
    }

    ~Renderer() {
        UnloadTexture(Texture);
    }

    void Draw(int x, int y) {
        DrawTexture(Texture, x, y, WHITE);
    }

private:
    Texture2D Texture;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "KeyStar: The Guitar-Hero Style Piano App");

    Renderer grandStaffRenderer("assets//grandstaff.png");
    Renderer noteTexture("assets//testnote.png");

    // Note testNote(0, 0);
    // testNote.SetPosition(150, 200); // Adjust position based on your requirement

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        grandStaffRenderer.Draw(0, 0);  // Render the grand staff
        noteTexture.Draw(150, 200);
        // testNote.Render();  // Render the test note

        EndDrawing();
    }

    CloseWindow();

    return 0;
}