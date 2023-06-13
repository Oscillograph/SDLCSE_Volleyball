#ifndef GLOBALS_H
#define GLOBALS_H

namespace Volleyball {
	// menus constants
	namespace Game_States {
		typedef enum {
			GAMESTATE_TITLE,
			GAMESTATE_MENU,
			GAMESTATE_GAME,
			GAMESTATE_ENTER_NEW_SCORE,
			GAMESTATE_VIEW_SCORES,
			GAMESTATE_CREDITS,
			GAMESTATE_EXIT,
			GAMESTATE_TOTAL
		} game_states;
	}
	
	namespace Menu {
		typedef enum {
			MAIN_START,
			MAIN_CONTROLS,
			MAIN_SETUP,
			MAIN_SCORES,
			MAIN_EXIT,
			MAIN_TOTAL
		} main_menu_items;
		
		typedef enum {
			SETUP_PLAYERS,
			SETUP_SOUNDS,
			SETUP_VOLUME,
			SETUP_SCREEN,
			SETUP_LANGUAGE,
			SETUP_TOTAL
		} setup_menu_items;
		
		typedef enum {
			CONTROLS_P1UP,
			CONTROLS_P1LEFT,
			CONTROLS_P1RIGHT,
			CONTROLS_P2UP,
			CONTROLS_P2LEFT,
			CONTROLS_P2RIGHT,
			CONTROLS_TOTAL
		} controls_menu_items;
	}
	
	struct Tscores {
		int place;
		std::string name;
		int score;
	};
	
	std::string game_file_settings = "settings.txt";
	std::string game_file_scores = "scores.txt";
	std::string game_file_language[2] = {"langRU.txt", "langEN.txt"};
	
	std::map<std::string, std::string> settings; // this is where we store settings
	std::map<std::string, int> controls; // this is where we store controls
	std::map<std::string, std::string> language; // this is where we store language data
	Tscores scores[5];
	
	void init_globals(){
		// settings
		settings["Players"] = "HvC";
		settings["Sounds"] = "on";
		settings["Volume"] = "100";
		settings["Screen"] = "1200x768";
		settings["Language"] = "RU";
		
		settings["ControlsP1Up"] = 'w';
		settings["ControlsP1Left"] = 'a';
		settings["ControlsP1Right"] = 'd';
		settings["ControlsP2Up"] = "Up";
		settings["ControlsP2Left"] = "Left";
		settings["ControlsP2Right"] = "Right";
		
		// controls
		controls["P1Up"] = SDLK_w;
		controls["P1Left"] = SDLK_a;
		controls["P1Right"] = SDLK_d;
		controls["P2Up"] = SDLK_UP;
		controls["P2Left"] = SDLK_LEFT;
		controls["P2Right"] = SDLK_RIGHT;
		
		// language RU
		language["Game_Player"] = "Игрок";
		language["Game_Human"] = "Человек";
		language["Game_Computer"] = "Компьютер";
		language["Game_Score"] = "Счёт";
		
		language["MMenu_Title"] = "Меню";
		language["MMenu_Start"] = "Игра";
		language["MMenu_Controls"] = "Управление";
		language["MMenu_Setup"] = "Настройки";
		language["MMenu_Scores"] = "Рекорды";
		language["MMenu_Exit"] = "Выход";
		
		language["SMenu_Title"] = "Настройки";
		language["SMenu_PlayersHvH"] = "Игроки: Чел и Чел";
		language["SMenu_PlayersHvC"] = "Игроки: Чел и Комп";
		language["SMenu_PlayersCvC"] = "Игроки: Комп и Комп";
		language["SMenu_SoundsOn"] = "Звуки ВКЛ";
		language["SMenu_SoundsOff"] = "Звуки ОТКЛ";
		language["SMenu_Volume"] = "Громкость";
		language["SMenu_Screen640x400"] = "Разрешение 640x400";
		language["SMenu_Screen1200x768"] = "Разрешение 1200x768";
		language["SMenu_Screen1600x800"] = "Разрешение 1600x808";
		language["SMenu_LanguageRU"] = "Язык: Русский";
		language["SMenu_LanguageEN"] = "Language: English";
	}
	
	// Game constants
	const float VELOCITY_MAX = 100.0f;
	const float ACCELERATION_MAX = 100.0f;
}

#endif
