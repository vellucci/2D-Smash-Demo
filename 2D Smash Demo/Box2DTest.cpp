#include "Box2DTest.h"

Box2DTest::Box2DTest() : scale(30), xSpeed(0), ySpeed(0),
jumping(false), m_jumpTimeout(0)
{
	window.create(sf::VideoMode(1400, 700), "SFML works!");
	groundTexture.loadFromFile("images/Box2D test/ground.png");
	boxTexture.loadFromFile("images/Box2D test/box.png");
}

Box2DTest::~Box2DTest()
{

}

void Box2DTest::CreateGround(b2World& World, float X, float Y)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(X / 30.f, Y / 30.f);
	BodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox((1400.f) / scale, (16.f / 2) / scale); // Creates a box shape. Divide your desired width and height by 2.
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &Shape; // Sets the shape
	Body->CreateFixture(&FixtureDef); // Apply the fixture definition
}

void Box2DTest::CreateBox(b2World& World, int MouseX, int MouseY)
{
	BodyDef.position = b2Vec2(MouseX / scale, MouseY / scale);
	BodyDef.type = b2_dynamicBody;
	body = World.CreateBody(&BodyDef);

	b2CircleShape  Shape;
	Shape.m_p.Set(0, 0); //position, relative to body position
	Shape.m_radius = 1; //radius
	//Shape.Set((32.f / 2) / scale, (32.f / 2) / scale);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 5.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);
	body->SetFixedRotation(true);
}

void Box2DTest::MoveSideways(sf::Time deltaTime)
{
	b2Vec2 vel = body->GetLinearVelocity();
	float force = 0; 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !jumping)
	{
		vel.x = 8;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !jumping)
	{
		vel.x = -8; 
	}
	else
	{
		vel.x *= 0.98;
	}

	body->SetLinearVelocity(vel);
}

void Box2DTest::Jump(sf::Time deltaTime)
{
	b2Vec2 vel = body->GetLinearVelocity();
	float force = 0; 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !jumping)
	{
		m_jumpTimeout = 6;
		//vel.y = -10;
		//body->SetLinearVelocity(vel);

		if (m_jumpTimeout > 0)
		{
  
		}
	}
	else
	{
 		//vel.y = 10;
		//body->SetLinearVelocity(vel);
	}

}

void Box2DTest::MainLoop(b2World& World, sf::RenderWindow& window)
{
	for (b2Body* BodyIterator = World.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if (BodyIterator->GetType() == b2_dynamicBody)
		{
			sf::Sprite sprite;
			sprite.setTexture(boxTexture);
			sprite.setOrigin(16.f, 16.f);
			sprite.setPosition(scale *BodyIterator->GetPosition().x, scale * BodyIterator->GetPosition().y);
			sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
			window.draw(sprite);
		}
		else
		{
			sf::Sprite groundSprite;
			groundSprite.setTexture(groundTexture);
			groundSprite.setOrigin(500.f, 8.f);
			groundSprite.setPosition(BodyIterator->GetPosition().x * scale , BodyIterator->GetPosition().y * scale);
			groundSprite.setRotation(180 / b2_pi * BodyIterator->GetAngle());
			window.draw(groundSprite);
		}
	}
}

void Box2DTest::Update(sf::Time deltaTime)
{
	MoveSideways(deltaTime);
	Jump(deltaTime);
}

void Box2DTest::Run(b2World& World, int minimum_frame_per_seconds)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time TimePerFrame = sf::seconds(1.f / minimum_frame_per_seconds);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		timeSinceLastUpdate = clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			Update(TimePerFrame);
		}

		Update(timeSinceLastUpdate);

		//simulate world
		World.Step(1 / 60.f, 8, 3);

		window.clear(sf::Color::White);
		MainLoop(World, window);
		window.display();
	}
}