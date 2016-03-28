#pragma once
#ifndef IntroScreen_H
#define IntroScreen_H
#include "ResourceLoader.h"

class IntroScreen
{
	public:
		IntroScreen();
		~IntroScreen(); 

		void ShowIntroScreen(sf::RenderWindow& window, sf::Event& event);

		bool close;
	private:
		sf::Sprite sprite;
		sf::Text text;
		sf::Sound enterPress; 
};

#endif 