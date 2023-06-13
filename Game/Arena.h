#ifndef ARENA_H
#define ARENA_H

#include "../SDLCrystalSerpentEngine.h"

namespace Volleyball{
	void addBall(cGame* CSE, float x, float y){
		SDL_FRect bSize;
		float bMass;
		
		//bMass = 1.0f + 0.1f * ((rand() % 10) - 5);
		bMass = 1.0f;
		bSize.w = 20 * bMass;
		bSize.h = 20 * bMass;
		bSize.x = x - 0.5f*bSize.w;
		bSize.y = y - 0.5f*bSize.h;
		
		CSE->Ball = CSE->newProps("Ball Entity");
		auto* hitBox = &(CSE->getHitBoxComponent(CSE->Ball));
		hitBox->type = SDLCSE::Objects::HIT_BOX_CIRCLE;
		hitBox->points.push_back({
			bSize.x + bSize.w/2, 
			bSize.y + bSize.h/2
			});
		hitBox->radius = bSize.w/2;
		
		auto* physics2D = &(CSE->getPhysics2DComponent(CSE->Ball));
		physics2D->centerOfMass = hitBox->points[0];
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			ACCELERATION_MAX
		};
		physics2D->canMove = true;
		physics2D->canBounce = true;
		physics2D->canPush = true;
		
		auto* ballSprite = &(CSE->getSpriteComponent(CSE->Ball));
		auto* ValleyballSprite = &(CSE->getSpriteComponent(CSE->Valleyball));
		ballSprite->sprite = ValleyballSprite->sprite;
		ballSprite->display = true;
		ballSprite->place = {
			bSize.x, 
			bSize.y, 
			bSize.w, 
			bSize.h
		};
		ballSprite->window = {
			0, 
			0, 
			20, 
			20
		};
		ballSprite->geometryCorrection = {
			ballSprite->place.x - physics2D->centerOfMass.x,
			ballSprite->place.y - physics2D->centerOfMass.y
		};
		
		auto* Animation = &(CSE->addAnimationComponent(CSE->Ball));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE,
			new SDLCSE::animationFrames({0, 0}, {60, 0}, 20, 20, 4, true));
		Animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
		Animation->start();
	}
	
	void addObjects(cGame* CSE){
		float winX = (float)(CSE->winX);
		float winY = (float)(CSE->winY);
		float winWidth = (float)(CSE->winWidth);
		float winHeight = (float)(CSE->winHeight);
		
		std::string fontSource = "./Game/Data/fonts/my8bit2.png";
		CSE->FontManager->load(fontSource);
		CSE->Graphics->getSymbols8bit();
		
		// Create objects
		SDLCSE::CSE_Entity entity;
		
		// 0. Border
		// top
		entity = CSE->newProps("Border Top Entity");
		auto* hitBox = &(CSE->getHitBoxComponent(entity));
		hitBox->type = SDLCSE::Objects::HIT_BOX_LINE;
		hitBox->points.push_back({
			0.0f, 
			0.0f
			});
		hitBox->points.push_back({
			winWidth, 
			0.0f
			});
		
		auto* physics2D = &(CSE->getPhysics2DComponent(entity));
		physics2D->centerOfMass = {
			0.5f*(hitBox->points[1].x + hitBox->points[0].x), 
			0.5f*(hitBox->points[1].y + hitBox->points[0].y)
		};
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			-0.0f
		};
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		CSE->removeSpriteComponent(entity);
		
		// right
		entity = CSE->newProps("Border Right Entity");
		hitBox = &(CSE->getHitBoxComponent(entity));
		hitBox->type = SDLCSE::Objects::HIT_BOX_LINE;
		hitBox->points.push_back({
			winWidth, 
			0.0f
			});
		hitBox->points.push_back({
			winWidth, 
			winHeight
			});
		
		physics2D = &(CSE->getPhysics2DComponent(entity));
		physics2D->centerOfMass = {
			0.5f*(hitBox->points[1].x + hitBox->points[0].x), 
			0.5f*(hitBox->points[1].y + hitBox->points[0].y)
		};
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			-0.0f
		};
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		CSE->removeSpriteComponent(entity);
		
		// bottom
		entity = CSE->newProps("Border Bottom Entity");
		hitBox = &(CSE->getHitBoxComponent(entity));
		hitBox->type = SDLCSE::Objects::HIT_BOX_LINE;
		hitBox->points.push_back({
			winWidth, 
			winHeight
			});
		hitBox->points.push_back({
			0.0f, 
			winHeight
			});
		
		physics2D = &(CSE->getPhysics2DComponent(entity));
		physics2D->centerOfMass = {
			0.5f*(hitBox->points[1].x + hitBox->points[0].x), 
			0.5f*(hitBox->points[1].y + hitBox->points[0].y)
		};
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			-0.0f
		};
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		CSE->removeSpriteComponent(entity);
		
		// left
		entity = CSE->newProps("Border Left Entity");
		hitBox = &(CSE->getHitBoxComponent(entity));
		hitBox->type = SDLCSE::Objects::HIT_BOX_LINE;
		hitBox->points.push_back({
			0.0f, 
			winHeight
			});
		hitBox->points.push_back({
			0.0f, 
			0.0f
			});
		
		physics2D = &(CSE->getPhysics2DComponent(entity));
		physics2D->centerOfMass = {
			0.5f*(hitBox->points[1].x + hitBox->points[0].x), 
			0.5f*(hitBox->points[1].y + hitBox->points[0].y)
		};
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			-0.0f
		};
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		CSE->removeSpriteComponent(entity);
		
		// 1. Sprite
		CSE->Valleyball = CSE->newProps("Volleyball Sprite Entity");
		CSE->removeHitBoxComponent(CSE->Valleyball);
		CSE->removePhysics2DComponent(CSE->Valleyball);
		
		auto* ValleyballSprite = &(CSE->getSpriteComponent(CSE->Valleyball));
		ValleyballSprite->sprite = new SDLCSE::cTexture("./Game/Data/img/Sprites.png", CSE->renderer, {0x00, 0x00, 0x00});
		ValleyballSprite->display = false;
		ValleyballSprite->place = {
			0, 
			0, 
			(float)(ValleyballSprite->sprite->getWidth()), 
			(float)(ValleyballSprite->sprite->getHeight())
		};
		ValleyballSprite->window = {
			0, 
			0, 
			CSE->winWidth, 
			CSE->winHeight
		};
		
		// 2. Player 1
		CSE->Player1 = CSE->newProps("Player 1");
		
		auto* Player1Sprite = &(CSE->getSpriteComponent(CSE->Player1));
		Player1Sprite->sprite = ValleyballSprite->sprite;
		Player1Sprite->display = true;
		Player1Sprite->place = {
			winWidth/4, 
			winHeight - 30, 
			20.0f, 
			30.0f
		};
		Player1Sprite->window = {
			80, 
			0, 
			20, 
			30
		};
		
		hitBox = &(CSE->getHitBoxComponent(CSE->Player1));
		hitBox->type = SDLCSE::Objects::HIT_BOX_CIRCLE;
		hitBox->points.push_back({
			Player1Sprite->place.x + 10, 
			Player1Sprite->place.y + 10
			});
		hitBox->radius = 10;
		
		physics2D = &(CSE->getPhysics2DComponent(CSE->Player1));
		physics2D->centerOfMass = hitBox->points[0];
		physics2D->mass = 3.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			0.0f, 
			0.0f
		};
		physics2D->canMove = true;
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		Player1Sprite->geometryCorrection = {
			Player1Sprite->place.x - physics2D->centerOfMass.x,
			Player1Sprite->place.y - physics2D->centerOfMass.y
		};
		
		auto* Animation = &(CSE->addAnimationComponent(CSE->Player1));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE,
			new SDLCSE::animationFrames({80, 0}, {80, 0}, 20, 30, 1, false));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_WALK,
			new SDLCSE::animationFrames({140, 0}, {80, 0}, -20, 30, 8, true));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_RUN,
			new SDLCSE::animationFrames({80, 0}, {140, 0}, 20, 30, 8, true));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_JUMP,
			new SDLCSE::animationFrames({160, 0}, {160, 0}, 20, 30, 1, true));
		
		Animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
		Animation->start();
		
		auto* Control = &(CSE->addControlKeyBoardComponent(CSE->Player1));
		Control->KBControls[SDLCSE::Commands::KBCommand_Jump] = Volleyball::controls["P1Up"];
		Control->KBControls[SDLCSE::Commands::KBCommand_Left] = Volleyball::controls["P1Left"];
		Control->KBControls[SDLCSE::Commands::KBCommand_Right] = Volleyball::controls["P1Right"];
		
		// 2. Player 2
		CSE->Player2 = CSE->newProps("Player 2");
		
		auto* Player2Sprite = &(CSE->getSpriteComponent(CSE->Player2));
		Player2Sprite->sprite = ValleyballSprite->sprite;
		Player2Sprite->display = true;
		Player2Sprite->place = {
			3*winWidth/4, 
			winHeight - 30, 
			20.0f, 
			30.0f
		};
		Player2Sprite->window = {
			80, 
			0, 
			20, 
			30
		};
		
		hitBox = &(CSE->getHitBoxComponent(CSE->Player2));
		hitBox->type = SDLCSE::Objects::HIT_BOX_CIRCLE;
		hitBox->points.push_back({
			Player2Sprite->place.x + 10, 
			Player2Sprite->place.y + 10
			});
		hitBox->radius = 10;
		
		physics2D = &(CSE->getPhysics2DComponent(CSE->Player2));
		physics2D->centerOfMass = hitBox->points[0];
		physics2D->mass = 3.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			0.0f, 
			0.0f
		};
		physics2D->canMove = true;
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		Player2Sprite->geometryCorrection = {
			Player2Sprite->place.x - physics2D->centerOfMass.x,
			Player2Sprite->place.y - physics2D->centerOfMass.y
		};
		
		Animation = &(CSE->addAnimationComponent(CSE->Player2));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE,
			new SDLCSE::animationFrames({260, 0}, {260, 0}, 20, 30, 1, false));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_WALK,
			new SDLCSE::animationFrames({260, 0}, {200, 0}, -20, 30, 8, true));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_RUN,
			new SDLCSE::animationFrames({200, 0}, {260, 0}, 20, 30, 8, true));
		Animation->add(SDLCSE::Objects::GAME_OBJECT_STATE_JUMP,
			new SDLCSE::animationFrames({180, 0}, {180, 0}, 20, 30, 1, true));
		
		Animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
		Animation->start();
		
		Control = &(CSE->addControlKeyBoardComponent(CSE->Player2));
		Control->KBControls[SDLCSE::Commands::KBCommand_Jump] = Volleyball::controls["P2Up"];
		Control->KBControls[SDLCSE::Commands::KBCommand_Left] = Volleyball::controls["P2Left"];
		Control->KBControls[SDLCSE::Commands::KBCommand_Right] = Volleyball::controls["P2Right"];
		
		// 4. Add Ball
		addBall(CSE, winWidth/2, winHeight/4);
		
		// 5. Wall
		// right
		CSE->Wall = CSE->newProps("Wall");
		hitBox = &(CSE->getHitBoxComponent(CSE->Wall));
		hitBox->type = SDLCSE::Objects::HIT_BOX_LINE;
		hitBox->points.push_back({
			winWidth/2, 
			winHeight
			});
		hitBox->points.push_back({
			winWidth/2, 
			winHeight/2
			});
		
		physics2D = &(CSE->getPhysics2DComponent(CSE->Wall));
		physics2D->centerOfMass = {
			0.5f*(hitBox->points[1].x + hitBox->points[0].x), 
			0.5f*(hitBox->points[1].y + hitBox->points[0].y)
		};
		physics2D->mass = 1.0f;
		physics2D->velocity = {
			0.0f, 
			0.0f
		};
		physics2D->acceleration = {
			-0.0f, 
			-0.0f
		};
		physics2D->canBounce = false;
		physics2D->canPush = true;
		
		auto* WallSprite = &(CSE->getSpriteComponent(CSE->Wall));
		WallSprite->sprite = ValleyballSprite->sprite;
		/*
		WallSprite->place = {
			physics2D->centerOfMass.x-2,
			physics2D->centerOfMass.y-2,
			5,
			4
		};
		*/
		WallSprite->place = {
			hitBox->points[1].x-2,
			hitBox->points[1].y-2,
			5,
			hitBox->points[0].y,
		};
		WallSprite->window = {
			72,
			26,
			5,
			4
		};
		WallSprite->display = true;
		WallSprite->geometryCorrection = {
			WallSprite->place.x - physics2D->centerOfMass.x,
			WallSprite->place.y - physics2D->centerOfMass.y
		};
		
		// 6. Game Stats Texts
		auto playerName1 = CSE->newText("Score_P1", {20.0f, 0.0f, 80.0f, 20.0f}, U"Счёт Раз", SDLCSE::Colors::RGBA_White8);
		auto playerName2 = CSE->newText("Score_P2", {220.0f, 0.0f, 80.0f, 20.0f}, U"Счёт Два", SDLCSE::Colors::RGBA_White8);
	}
}

#endif
