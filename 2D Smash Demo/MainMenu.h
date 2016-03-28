#pragma once
#ifndef MainMenu_H
#define MainMenu_H
#include "ResourceLoader.h"

#define MENU_ITEMS 3

class MainMenu
{
	public:
		MainMenu();
		~MainMenu();

		void DrawMenu(sf::RenderWindow& window, sf::Event& currEvent);
		void MoveUp(); //move up the menu
		void MoveDown(); //move down the menu
		int ChooseOption();

		bool close; 
		int option; 
	private:

		int selectedItem; 
		sf::Text menuItems[MENU_ITEMS];
		sf::Texture texture;
		sf::Sprite background;

		sf::Sound menuSwitch; 
};

#endif
