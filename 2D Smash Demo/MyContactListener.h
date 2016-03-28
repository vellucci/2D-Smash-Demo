#include "Common.h"

class MyContactListener: public b2ContactListener
{
	public:
		MyContactListener();
		~MyContactListener();

		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);

		 set<b2Fixture*> fixturesUnderfoot;

	private:

};

