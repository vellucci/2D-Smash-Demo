#include "ResourceLoader.h"

class Box2DTest
{
	public:
		Box2DTest();
		~Box2DTest(); 

		void CreateGround(b2World& World, float X, float Y);
		void CreateBox(b2World& World, int MouseX, int MouseY); // Spawns a box at MouseX, MouseY

		void MainLoop(b2World& World, sf::RenderWindow& window);
		void MoveSideways(sf::Time deltaTime);
		void Jump(sf::Time deltaTime);
		void Update(sf::Time deltaTime);
		void Run(b2World& World, int minimum_frame_per_seconds);
		bool CanJump(); 

	private:
		sf::Texture groundTexture;
		sf::Texture boxTexture;
		sf::Sprite boxSprite;

		b2BodyDef BodyDef;
		b2Body* body; 

		float xSpeed;
		float ySpeed;
		bool jumping; 
		const float scale;
		int m_jumpTimeout;

		sf::RenderWindow window;

};