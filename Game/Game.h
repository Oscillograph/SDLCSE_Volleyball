#ifndef GAME_H
#define GAME_H

#include "../SDLCrystalSerpentEngine.h"

class cGame : public SDLCSE::cCrystalSerpentEngine{
	public:	
	int mouseXold, mouseYold;
	float mouseVx, mouseVy;
	int game_state;
	
	SDL_FRect world;
	
	float Vxmin, Vymin, 
	Vxmax, Vymax; // min and max speeds in meters
	
	// game entities
	SDLCSE::CSE_Entity Valleyball, Player1, Player2, Ball, Wall, Floor;
	
	cGame(){
		// initialize it
		scaleX = 4.0f; // 1 meter per pixel on Ox axis
		scaleY = 4.0f; // 1 meter per pixel on Oy axis
		
		Vxmin = 0.0f; Vxmax = 400.0f;
		Vymin = 0.0f; Vymax = 400.0f;
		
		world = {0.0f, 0.0f, 20.0f, 20.0f}; // 20x20 meters is the size of the game world
		
		game_state = Volleyball::Game_States::GAMESTATE_GAME;
		
		Volleyball::init_globals();
	}
	
	// how we will react to user input
	void onKeyboardUpdate(int32_t keyCode, uint32_t keyStatus) override {
		switch(keyCode){
		case SDLK_ESCAPE:
			quit = true;
			break;
		case SDLK_SPACE:
			registry.clear();
			break;
		}
		
		if (game_state == Volleyball::Game_States::GAMESTATE_GAME){
			auto view = registry.view<SDLCSE::Components::controlKeyBoard>();
			if (view.size() > 0){
				for (auto entity : view){
					Volleyball::Systems::moveByKeyBoard(&(getControlKeyBoardComponent(entity)),
						&(getPhysics2DComponent(entity)),
						&(getAnimationComponent(entity)),
						keyCode,
						keyStatus);
				}
			}
		}
		
		if (game_state == Volleyball::Game_States::GAMESTATE_MENU){
			switch(keyCode){
				case SDLK_UP: // navigate up or change value
					break;
				case SDLK_DOWN: // navigate down or change value
					break;
				case SDLK_RETURN: // enter menu or change its value
					break;
				case SDLK_ESCAPE: // go to upper level or exit if there's none
					break;
				default:
					break;
			}
		}
		
		if (game_state == Volleyball::Game_States::GAMESTATE_ENTER_NEW_SCORE){
			/*
			bool EnterPressed = InputSystem->promptString(); // listen until Enter is pressed
			if (EnterPressed){
				save_new_score(InputSystem->user_string);
				game_state = Volleyball::Game_States::GAMESTATE_VIEW_SCORES;
			}
			*/
		}
	}
	
	void onWorldUpdate() override{		
		auto view = registry.view<SDLCSE::Components::physics2D>();
		for (auto entity : view){
			Physics2D->getTime(entity, &registry);
			Physics2D->move(entity, &registry);
			Physics2D->timeReset(entity, &registry);
			
			auto* physicsComponent = &(getPhysics2DComponent(entity));
			
			// ограничим максимальную скорость объектов
			float rel = SDLCSE::Math::length(physicsComponent->velocity) / Volleyball::VELOCITY_MAX;
			if (rel > 1){
				physicsComponent->velocity.x = physicsComponent->velocity.x / rel;
				physicsComponent->velocity.y = physicsComponent->velocity.x / rel;
			}
			
			// защитим игроков от попадания за пределы экрана
			if ((Player2 == entity) || (Player1 == entity)){
				if (physicsComponent->centerOfMass.x > (winWidth-10)){
					physicsComponent->centerOfMass.x = winWidth-10;
				}
				
				if (physicsComponent->centerOfMass.x < 10){
					physicsComponent->centerOfMass.x = 10;
				}
				
				if (physicsComponent->centerOfMass.y > (winHeight-20)){
					physicsComponent->centerOfMass.y = winHeight-20;
					physicsComponent->velocity.y = 0.0f;
					physicsComponent->acceleration.y = 0.0f;
					
					// установим и запустим верную анимацию
					auto* animationComponent = &(getAnimationComponent(entity));
					if (physicsComponent->velocity.x == 0.0f){
						animationComponent->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
					}
					if (Player1 == entity){
						if (physicsComponent->velocity.x < 0.0f){
							animationComponent->set(SDLCSE::Objects::GAME_OBJECT_STATE_WALK);
						}
						if (physicsComponent->velocity.x > 0.0f){
							animationComponent->set(SDLCSE::Objects::GAME_OBJECT_STATE_RUN);
						}
					}
					if (Player2 == entity){
						if (physicsComponent->velocity.x < 0.0f){
							animationComponent->set(SDLCSE::Objects::GAME_OBJECT_STATE_RUN);
						}
						if (physicsComponent->velocity.x > 0.0f){
							animationComponent->set(SDLCSE::Objects::GAME_OBJECT_STATE_WALK);
						}
					}	
					animationComponent->start();
				}
			}
		}
		Physics2D->processCollisionsEvenDumber(&registry);
	}
};

#endif
