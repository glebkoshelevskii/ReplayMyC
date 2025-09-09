#include "trace.h"
#include "raylib.h"
#include "raylib_deserialization.h"
#include "raylib_serialization.h"
#include "raylib_init.h"
#include <cmath>
#include <cstring>
#include <iostream>

int main(int argc, char *argv[]) {
  // Check command line arguments
  rmc_mode_t mode = TMC_MODE_CAPTURE;
  const char *trace_file = "trace.bin";

  if (argc > 1) {
    if (strcmp(argv[1], "replay") == 0) {
      mode = TMC_MODE_REPLAY;
      if (argc > 2) {
        trace_file = argv[2];
      }
    } else if (strcmp(argv[1], "capture") == 0) {
      mode = TMC_MODE_CAPTURE;
      if (argc > 2) {
        trace_file = argv[2];
      }
    }
  }
  init_raylib();
  auto result = rmc_init(mode, trace_file);
  if (!result.is_valid) {
    std::cerr << "Failed to initialize tracing: " << result.description << std::endl;
    return 1;
  }

  if (mode == TMC_MODE_CAPTURE) {
    auto start_result = rmc_start_tracing();
    if (!start_result.is_valid) {
      std::cerr << "Failed to start tracing: " << start_result.description << std::endl;
      return 1;
    }
  } else {
    // Replay mode
    std::cout << "Starting replay from " << trace_file << std::endl;
    auto replay_result = rmc_replay_trace();
    if (!replay_result.is_valid) {
      std::cerr << "Failed to replay trace: " << replay_result.description << std::endl;
      return 1;
    }
    rmc_deinit();
    return 0;
  }

  // Window configuration
  const int screenWidth = 800;
  const int screenHeight = 450;

  // Use serialization calls in capture mode
  InitWindow(screenWidth, screenHeight, "raylib - Simple Test Application");
  SetTargetFPS(60);
  serialize_InitWindow(screenWidth, screenHeight,
                       "raylib - Simple Test Application");
  serialize_SetTargetFPS(60);

  // Game state variables
  Vector2 ballPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  Vector2 ballSpeed = {5.0f, 4.0f};
  float ballRadius = 20.0f;

  Color ballColor = MAROON;
  int bounceCount = 0;

  // Main game loop
  while (!WindowShouldClose()) {
    serialize_WindowShouldClose();
    // Update
    //----------------------------------------------------------------------------------
    ballPosition.x += ballSpeed.x;
    ballPosition.y += ballSpeed.y;

    // Check collision with screen bounds
    if ((ballPosition.x >= (screenWidth - ballRadius)) ||
        (ballPosition.x <= ballRadius)) {
      ballSpeed.x *= -1.0f;
      bounceCount++;
      // Change ball color on bounce
      serialize_GetRandomValue(50, 255);
      serialize_GetRandomValue(50, 255);
      serialize_GetRandomValue(50, 255);
      ballColor = {(unsigned char)GetRandomValue(50, 255),
                   (unsigned char)GetRandomValue(50, 255),
                   (unsigned char)GetRandomValue(50, 255), 255};
    }

    if ((ballPosition.y >= (screenHeight - ballRadius)) ||
        (ballPosition.y <= ballRadius)) {
      ballSpeed.y *= -1.0f;
      bounceCount++;
      serialize_GetRandomValue(50, 255);
      serialize_GetRandomValue(50, 255);
      serialize_GetRandomValue(50, 255);
      ballColor = {(unsigned char)GetRandomValue(50, 255),
                   (unsigned char)GetRandomValue(50, 255),
                   (unsigned char)GetRandomValue(50, 255), 255};
    }

    // Draw (with tracing)
    //----------------------------------------------------------------------------------
    serialize_BeginDrawing();
    BeginDrawing();

    serialize_ClearBackground(RAYWHITE);
    ClearBackground(RAYWHITE);

    // Draw bouncing ball
    serialize_DrawCircleV(ballPosition, ballRadius, ballColor);
    DrawCircleV(ballPosition, ballRadius, ballColor);

    // Draw some shapes
    serialize_DrawRectangle(10, 10, 120, 60, BLUE);
    DrawRectangle(10, 10, 120, 60, BLUE);
    serialize_DrawRectangleLines(10, 10, 120, 60, DARKBLUE);
    DrawRectangleLines(10, 10, 120, 60, DARKBLUE);

    // Draw text
    serialize_DrawText("raylib Test Application", 10, 15, 20, DARKBLUE);
    DrawText("raylib Test Application", 10, 15, 20, DARKBLUE);
    serialize_DrawText("Ball bounces and changes color", 10, 35, 10, DARKBLUE);
    DrawText("Ball bounces and changes color", 10, 35, 10, DARKBLUE);
    // Note: TextFormat requires special handling due to return value
    const char *bounceText = TextFormat("Bounces: %i", bounceCount);
    serialize_DrawText(bounceText, 10, 50, 10, DARKBLUE);
    DrawText(bounceText, 10, 50, 10, DARKBLUE);

    // Draw FPS
    serialize_DrawFPS(10, screenHeight - 30);
    DrawFPS(10, screenHeight - 30);

    // Draw instructions
    serialize_DrawText("ESC to exit", screenWidth - 100, screenHeight - 30, 20,
                       GRAY);
    DrawText("ESC to exit", screenWidth - 100, screenHeight - 30, 20, GRAY);

    serialize_EndDrawing();
    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  serialize_CloseWindow();
  CloseWindow();

  // Stop tracing
  auto end_result = rmc_end_tracing();
  if (!end_result.is_valid) {
    std::cerr << "Warning: Failed to end tracing properly" << std::endl;
  }
  
  rmc_deinit();

  return 0;
}