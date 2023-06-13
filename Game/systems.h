#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "./globals.h"

namespace Volleyball {
	namespace Systems {
		void moveByKeyBoard(SDLCSE::Components::controlKeyBoard *controls,
							SDLCSE::Components::physics2D *physics,
							SDLCSE::Components::animation *animation,
							int32_t keyCode,
							uint32_t keyStatus){
			if (keyCode == controls->KBControls[SDLCSE::Commands::KBCommand_Jump]){
				// прыгаем?
				if ((keyStatus == SDL_KEYDOWN) && 
					(physics->acceleration.y != ACCELERATION_MAX) && // если не оттлокнулись уже 
					(physics->velocity.y != VELOCITY_MAX)){ // если не падаем
					animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_JUMP);
					animation->start();
					physics->velocity.y = -VELOCITY_MAX;
					physics->acceleration.y = ACCELERATION_MAX;
				} else { // падаем?
					if (keyStatus == SDL_KEYUP){
						animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_JUMP);
						animation->start();
						physics->velocity.y = VELOCITY_MAX;
						physics->acceleration.y = 0.0f;
					}
				}
				return;
			}
			if (keyCode == controls->KBControls[SDLCSE::Commands::KBCommand_Left]){
				// движемся влево
				if ((keyStatus == SDL_KEYDOWN) && (physics->velocity.x != -VELOCITY_MAX)){ 
					animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_WALK);
					animation->start();
					physics->velocity.x = -VELOCITY_MAX;
				} else { // останавливаемся
					if (keyStatus == SDL_KEYUP){
						animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
						animation->start();
						physics->velocity.x = 0.0f;
					}
				}
				return;
			}
			if (keyCode == controls->KBControls[SDLCSE::Commands::KBCommand_Right]){
				// движемся вправо
				if ((keyStatus == SDL_KEYDOWN) && (physics->velocity.x != VELOCITY_MAX)){ 
					animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_RUN);
					animation->start();
					physics->velocity.x = VELOCITY_MAX;
				} else { // останавливаемся
					if (keyStatus == SDL_KEYUP){
						animation->set(SDLCSE::Objects::GAME_OBJECT_STATE_IDLE);
						animation->start();
						physics->velocity.x = 0.0f;
					}
				}
				return;
			}
			return;
		}
	}
}

#endif
