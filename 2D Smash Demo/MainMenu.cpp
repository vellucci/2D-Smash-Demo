#include "MainMenu.h"

MainMenu::MainMenu()
{
	ResourceLoader::Instance()->LoadTexture("menuBackground", "images/menuSprites/menuBackground.png");
	background.setTexture(ResourceLoader::Instance()->getTexRef("menuBackground"));

	//set all the text for the menu options
	ResourceLoader::Instance()->SetFontProperties("main font", menuItems[0], "Fight", 1400 / 2, 200, 70, sf::Color::Red, true);
	ResourceLoader::Instance()->SetFontProperties("main font", menuItems[1], "Training", 1400 / 2, 300, 70, sf::Color::White, true);
	ResourceLoader::Instance()->SetFontProperties("main font", menuItems[2], "Exit", 1400 / 2, 400, 70, sf::Color::White, true);

	//set needed sound effects
	ResourceLoader::Instance()->LoadBuffer("menuSwitch", "audio/main_menu/menu_switch.wav");
	menuSwitch.setBuffer(ResourceLoader::Instance()->getBufferRef("menuSwitch"));

	close = false; 
	selectedItem = 0; 
}

MainMenu::~MainMenu()
{
}

void MainMenu::DrawMenu(sf::RenderWindow& window, sf::Event& currEvent)
{
	while (true)
	{
		while (window.pollEvent(currEvent))
		{
			if (currEvent.type == sf::Event::Closed)
			{
				close = true;
				return;
			}
			else if (currEvent.type == sf::Event::KeyPressed)
			{
				if (currEvent.key.code == sf::Keyboard::Down ) //move down the menu options
				{
					MoveDown();		
				}
				else if (currEvent.key.code == sf::Keyboard::Up ) //move up the menu options
				{
					MoveUp();			
				}
				else if (currEvent.key.code == sf::Keyboard::Return) // if enter is pressed
				{
					ChooseOption();
					return; 
				}
				else if (currEvent.key.code == sf::Keyboard::Escape)
				{
					close = true;
					return; 
				}
			}
		}
		
		window.clear();
		window.draw(background);
		for (int i = 0; i < MENU_ITEMS; i++)
			window.draw(menuItems[i]);
		window.display();
	}
}

//Move up the menu and change the color of the menu items based on which the user is on
void MainMenu::MoveUp()
{
	if (selectedItem > 0)
	{
		ResourceLoader::Instance()->UpdateText(menuItems[selectedItem], NULL, sf::Color::White, true);
		selectedItem--;
		ResourceLoader::Instance()->UpdateText(menuItems[selectedItem], NULL, sf::Color::Red, true);
		menuSwitch.play();
	}
}

//Same as MoveUp but goes down the menu
void MainMenu::MoveDown()
{
	if (selectedItem + 1 < MENU_ITEMS)
	{
		ResourceLoader::Instance()->UpdateText(menuItems[selectedItem], NULL, sf::Color::White, true);
		selectedItem++;
		ResourceLoader::Instance()->UpdateText(menuItems[selectedItem], NULL, sf::Color::Red, true);
		menuSwitch.play();
	}
}

//return a number based on the menu option selected
int MainMenu::ChooseOption()
{
	switch (selectedItem)
	{
		case 0: //user clicks on fight 
			option = 1;
			break;
		case 1: //user clicks on training
			option = 2;
			break; 
		case 2: //user exits
			option = 3;
			break; 
	}

	return option; 
}