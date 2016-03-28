#include "MyContactListener.h"

MyContactListener::MyContactListener()
{

}

MyContactListener::~MyContactListener()
{

}

void MyContactListener::BeginContact(b2Contact* contact)
{
	//check if fixture A was the foot sensor
	void* fixtureUserData = contact->GetFixtureA()->GetUserData();
	if ((int)fixtureUserData == 3)
		fixturesUnderfoot.insert(contact->GetFixtureB());//A is foot so B is ground

	//check if fixture B was the foot sensor
	fixtureUserData = contact->GetFixtureB()->GetUserData();
	if ((int)fixtureUserData == 3)
		fixturesUnderfoot.insert(contact->GetFixtureA());//B is foot so A is ground
}

void MyContactListener::EndContact(b2Contact* contact)
{
	//check if fixture A was the foot sensor
	void* fixtureUserData = contact->GetFixtureA()->GetUserData();
	if ((int)fixtureUserData == 3)
		fixturesUnderfoot.erase(contact->GetFixtureB());//A is foot so B is ground

	//check if fixture B was the foot sensor
	fixtureUserData = contact->GetFixtureB()->GetUserData();
	if ((int)fixtureUserData == 3)
		fixturesUnderfoot.erase(contact->GetFixtureA());//B is foot so A is ground
}