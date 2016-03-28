#include "CharacterCtrlTest.h"

CharacterCtrlTest::CharacterCtrlTest() : moveSpeed(10.f), airSpeed(1.0f),
jumpSpeed(10.0f), fallSpeed(8.0f), jumping(false), groundHeight(600)
{
	rect.setSize(sf::Vector2f(30, 30));
	rect.setPosition(200, 200);
	rect.setFillColor(sf::Color::Blue);
}

CharacterCtrlTest::~CharacterCtrlTest()
{

}

void CharacterCtrlTest::moveChar(sf::Vector2f velocity)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{	
			velocity.x += moveSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity.x = -moveSpeed; 
	}

	if (rect.getPosition().y + rect.getSize().y < groundHeight)
	{
		velocity.y += fallSpeed;
	}
	else if (rect.getPosition().y + rect.getSize().y == groundHeight)
	{
		jumping = false; 
	}
	else
	{
		rect.setPosition(rect.getPosition().x, groundHeight - rect.getSize().y);
	}

	rect.move(velocity.x, velocity.y);
}

void CharacterCtrlTest::Jump(sf::Vector2f velocity)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumping)
	{
		velocity.y = -jumpSpeed;
		jumping = true; 
	}
			
}
void CharacterCtrlTest::Draw(sf::RenderWindow& window)
{
	window.draw(rect); 
}
