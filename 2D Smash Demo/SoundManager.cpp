#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
	
}

void SoundManager::Init(string filename)
{
	src = filename; 
	if (!buffer.loadFromFile(filename))
	{
		cout << "Cannot load sound file: " + filename << endl; 
		return;
	}
		
	sound.setBuffer(buffer);

	//sounds.insert(std::make_pair("filename", new SoundManager()));
}

void SoundManager::PlaySound()
{
	sound.play(); 
}

void SoundManager::LoadSound(string filename)
{
	//sounds.insert(std::make_pair("filename", new SoundManager()));
}


