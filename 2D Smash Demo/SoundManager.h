#pragma once
#ifndef SoundManager_H
#define SoundManager_H
#include "Common.h"

class SoundManager
{
	public:
		SoundManager();
		~SoundManager(); 

		// . std::map<std::string, unique_ptr<SoundManager>> sounds;
		vector<unique_ptr<SoundManager>> sounds; 

		void Init(string filename);
		void PlaySound();
		void LoadSound(string filename);

	private:
		sf::SoundBuffer buffer;
		sf::Sound sound; 
		string src;
};

#endif