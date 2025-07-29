#include <raylib.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Pong Game (Against Computer)");

    Vector2 ballPos = { screenWidth/2, screenHeight/2 };
    Vector2 ballSpeed = { 5,5};
    Vector2 playerPos = { 50, screenHeight/2 - 30 };
    Vector2 computerPos = { screenWidth - 60, screenHeight/2 - 30 };
    
    int playerScore = 0;
    int computerScore = 0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose() && playerScore < 10 && computerScore < 10)    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        ballPos.x += ballSpeed.x;
        ballPos.y += ballSpeed.y;

        if (ballPos.y < 0 || ballPos.y > screenHeight - 10) ballSpeed.y *= -1;

        Rectangle ballRec = { ballPos.x, ballPos.y, 10, 10 };
        Rectangle playerRec = { playerPos.x, playerPos.y, 10, 60 };
        Rectangle computerRec = { computerPos.x, computerPos.y, 10, 60 };

        if (CheckCollisionRecs(ballRec, playerRec)) ballSpeed.x *= -1.1f;
        if (CheckCollisionRecs(ballRec, computerRec)) ballSpeed.x *= -1.1f;

        if (ballPos.x > screenWidth)
        {
            Vector2 newBallPos = { screenWidth/2, screenHeight/2 };
            ballPos = newBallPos;
            ballSpeed.x *= -1;
            playerScore++;
        }
        else if (ballPos.x < 0)
        {
            Vector2 newBallPos = { screenWidth/2, screenHeight/2 };
            ballPos = newBallPos;
            ballSpeed.x *= -1;
            ballSpeed = (Vector2){5,5.2}; // reset ball speed
            computerScore++;
        }
        computerPos.y = ballPos.y - 63;
		
		if (IsKeyDown(KEY_UP)) playerPos.y -= 5;
        if (IsKeyDown(KEY_DOWN)) playerPos.y += 5;
		
		if (playerPos.y < 0) playerPos.y = 0;
        if (playerPos.y > screenHeight - 60) playerPos.y = screenHeight - 60;

        if (computerPos.y < 0) computerPos.y = 0;
        if (computerPos.y > screenHeight - 60) computerPos.y = screenHeight - 60;
		
        //----------------------------------------------------------------------------------
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            

            DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);
            DrawRectangle(playerPos.x, playerPos.y, 10, 60, BLUE);
            DrawRectangle(computerPos.x, computerPos.y, 10, 60, RED);
            DrawRectangle(ballPos.x - 5,ballPos.y - 5 ,10,10,GOLD);
            DrawText(TextFormat("Player Score: %i", playerScore), 10, 10, 20, BLUE);
		    DrawText(TextFormat("Computer Score: %i", computerScore), screenWidth - 300, 10, 20, RED);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow();        // Close window and OpenGL context
//--------------------------------------------------------------------------------------

return 0;

}