/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Agent.h"
#include "Behavior.h"
#include "KeyboardBehavior.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition({ 100.0f, 100.0f });
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addedBehavior(keyboardBehavior);

	Agent* enemy = new Agent();
	enemy->setPosition({ 500.0f, 500.0f });
	SeekBehavior* seekBehavior = new  SeekBehavior();
	seekBehavior->setTarget(player);
	enemy->addedBehavior(seekBehavior);	
	Agent* enemy1 = new Agent();
	FleeBehavior* fleeBehavior = new FleeBehavior();
	fleeBehavior->setTarget(player);
	enemy1->setPosition({ 250.0f, 250.0f });
	enemy1->addedBehavior(fleeBehavior);
	WanderBehavior* wanderBehavior = new WanderBehavior();
	Agent* wanderer = new Agent();
	wanderer->setPosition({ 400.0f, 400.0f });
	wanderer->addedBehavior(wanderBehavior);

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		player->update(GetFrameTime());
		enemy->update(GetFrameTime());
		enemy1->update(GetFrameTime());
		wanderer->update(GetFrameTime());
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		player->draw();
		enemy->draw();
		enemy1->draw();
		wanderer->draw();

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}