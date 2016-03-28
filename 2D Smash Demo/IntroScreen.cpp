#include "IntroScreen.h"

IntroScreen::IntroScreen()
{
	string titleTxt = "Press Enter to Continue";

	//loader->LoadTexture("images/menuSprites/titleScreen.png", texture, sprite);
	ResourceLoader::Instance()->LoadTexture("IntroScreen", "images/menuSprites/titleScreen.png");
	sprite.setTexture(ResourceLoader::Instance()->getTexRef("IntroScreen"));

	//load audio
	ResourceLoader::Instance()->LoadBuffer("pressEnter", "audio/intro_screen_enter.wav");
	enterPress.setBuffer(ResourceLoader::Instance()->getBufferRef("pressEnter"));
	
	//set the texts
	ResourceLoader::Instance()->SetFontProperties("main font", text, titleTxt, 1400 / 2, 550, 50, sf::Color::White, true);

	close = false; 
}

IntroScreen::~IntroScreen()
{
	
}

void IntroScreen::ShowIntroScreen(sf::RenderWindow& window, sf::Event& currEvent)
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
			else if (currEvent.type == sf::Event::KeyPressed) //Input from keyboard
			{
				if (currEvent.key.code == sf::Keyboard::Return) //if user presses enter
				{
					return;			
				}
				else if (currEvent.key.code == sf::Keyboard::Up)
				{
					
				}
				else if (currEvent.key.code == sf::Keyboard::Escape) //if escaped is pressed
				{
					close = true;
					return; 
				}
			}
			else if (sf::Joystick::isButtonPressed(0, 0)) //Input from controller (A button)
			{
				return;
			}
		}

		window.clear(); 
		window.draw(sprite);
		window.draw(text);
		window.display();
	}
}