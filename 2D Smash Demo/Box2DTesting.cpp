#include "Game.h"
#include "Box2DTest.h"
#include "CharacterCtrlTest.h"
int mainTEST()
{
	sf::RenderWindow window(sf::VideoMode(1400, 700), "SFML works!");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	b2Vec2 gravity(0.f, 11.f);
	b2World world(gravity);

	Box2DTest box;
	box.CreateGround(world, 200.f, 600.f);
	box.CreateBox(world, 300.f, 300.f);

	int minimum_frame_per_seconds = 60; 

	//int mouseX = sf::Mouse::getPosition(window).x;
	//int mouseY = sf::Mouse::getPosition(window).y;

	box.Run(world, minimum_frame_per_seconds);

	return 0;
}