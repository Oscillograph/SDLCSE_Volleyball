// include SDL Crystal Serpent Engine
#include "./SDLCrystalSerpentEngine.h"
#include "./Game/globals.h"
#include "./Game/GameStateMachine.h"
#include "./Game/systems.h"
#include "./Game/Game.h"
#include "./Game/Arena.h"

// --- -- - namespaces: - -- ---
//   SDLCSE - the game engine
//    Volleyball - the game

int main(int argc, char** args) {
	// prepare engine initialization
	float winX = 150.0f;
	float winY = 150.0f;
	float winWidth = 320.0f;
	float winHeight = 200.0f;
	
	std::string winTitle = "Воллейболл - " + SDLCSE::GameEngineName + " v" + SDLCSE::GameEngineVersion;

	// THIS IS THE ENGINE ENTRY POINT
	cGame Game;
	Game.Init(winTitle, winX, winY, winWidth, winHeight, 0);
	
	// Fill the game world with objects
	Volleyball::addObjects(&Game);
	
	// Start the game cycle and enjoy the magic done by Crystal Serpent Engine
	Game.Start();
	
	return 0;
}
