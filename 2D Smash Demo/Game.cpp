#include "Game.h"

Game::Game()
{
	ResourceLoader::Instance()->LoadFont("main font", "fonts/DFHeiE.ttc");
	mainWindow.setFramerateLimit(60);
}

Game::~Game()
{

}

void Game::Start()
{
	mainWindow.create(sf::VideoMode(1400, 700, 32), "2D Smash Demo");

	gameState = introScreen;

	while (!IsExiting())
	{ 
		GameLoop();
	}

	mainWindow.close(); 
}

bool Game::IsExiting()
{
	if (gameState == exited)
		return true;
	else
		return false; 
}

void Game::GameLoop()
{
	sf::Event currEvent; 
	switch (gameState)
	{
		case introScreen:
			//show intro screen
			ShowIntroScreen(currEvent);
			break;
		case mainMenu:
			//show main menu
			ShowMenu(currEvent);
		 	break;
		case charSelection:
			//show character selection screen
			break;
		case training:
			break;
		case playing:
			//main game
			MainGame(currEvent);
			break; 
	}
}



void Game::MainGame(sf::Event& currEvent)
{
	while (mainWindow.pollEvent(currEvent))
	{
		if(currEvent.type == sf::Event::Closed)
		{
			gameState = exited;
		}
		else if (currEvent.type == sf::Event::KeyPressed)
		{
			if (currEvent.key.code == sf::Keyboard::Escape)
			{
				gameState = introScreen;
			}
		}
	}
	mainWindow.clear();
	//draw here
	mainWindow.display(); 
}

void Game::ShowIntroScreen(sf::Event& currEvent)
{
	IntroScreen introScreen; 
	introScreen.ShowIntroScreen(mainWindow, currEvent); //when this function returns...
	if (!introScreen.close)
		gameState = mainMenu; //change value of gamestate
	else
		gameState = exited; 
}

void Game::ShowMenu(sf::Event& currEvent)
{
	MainMenu menu;
	menu.DrawMenu(mainWindow, currEvent);

	//check if the user x's out the window
	if (menu.close)
		gameState = introScreen; 

	int option = menu.ChooseOption();
	//change gameState based on what user chose at the menu
	if (option == 1)
	{
		//gameState = charSelection;
	}	
	else if (option == 2)
	{
		//gameState = training;	   
	}
	else if (option == 3)
	{
		gameState = introScreen; 
	}
		
}
