#ifndef Game_H
#define Game_H
#include "Common.h"
#include "IntroScreen.h"
#include "MainMenu.h"
class Game
{
	public:
		Game();
		~Game();

		void Start();
		bool IsExiting();

		//used for menus
		void ShowIntroScreen(sf::Event& currEvent);
		void ShowMenu(sf::Event& currEvent);
		void CharSelection(sf::Event& currEvent);

		//main gameplay happens here
		void MainGame(sf::Event& currEvent); 

		//Loop that will switch between game states
		void GameLoop();

		enum GameState {
			introScreen, mainMenu, charSelection,
			paused, training, playing, exited
		};

	private:
		sf::RenderWindow mainWindow; 
	    GameState gameState; 
};

#endif
