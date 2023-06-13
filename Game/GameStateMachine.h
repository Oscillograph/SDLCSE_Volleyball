#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

namespace Volleyball {
	// the state machine is a ring
	struct state_machine {
		int id;
		int next;
		int previous;
	};
	
	class class_GameStateMachine{
	public:
		class_GameStateMachine(){
			states[0] = {Game_States::GAMESTATE_TITLE, 1, 6};
			states[1] = {Game_States::GAMESTATE_MENU, 2, 0};
			states[2] = {Game_States::GAMESTATE_GAME, 3, 1};
			states[3] = {Game_States::GAMESTATE_ENTER_NEW_SCORE, 4, 2};
			states[4] = {Game_States::GAMESTATE_VIEW_SCORES, 5, 3};
			states[5] = {Game_States::GAMESTATE_CREDITS, 1, 4};
			states[6] = {Game_States::GAMESTATE_EXIT, 0, 5};
		};
		
		~class_GameStateMachine(){};
		
		state_machine states[10];
		
		// get an id of the current state
		int getState(){
			return current_state.id;
		};
		
		// set current state manually
		void setState(int state){
			for (int i=0; i<10; i++){
				if (states[i].id == state){
					current_state = states[i];
					return;
				}
			}
		};
		
		// reset the state
		void reset(int state){};
		
		// start the state
		void start(int state){};
		
		// exit from the state
		void exit(int state){};
		
	private:
		state_machine current_state;
	};
}

#endif
