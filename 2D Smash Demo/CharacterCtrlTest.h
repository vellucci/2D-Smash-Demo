#include "Common.h"

class CharacterCtrlTest
{
	public:
		CharacterCtrlTest();
		~CharacterCtrlTest();

		void moveChar(sf::Vector2f velocity);
		void Jump(sf::Vector2f velocity);
		void Draw(sf::RenderWindow& window);

	private:
		const float fallSpeed;
		int groundHeight;
		sf::Vector2f velocity;

		float moveSpeed;
		float airSpeed;
		float jumpSpeed;
		bool jumping; 

		sf::RectangleShape rect;
};