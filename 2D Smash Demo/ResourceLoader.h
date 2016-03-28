#pragma once
#ifndef ResourceLoader_H
#define ResourceLoader_H
#include "Common.h"

class ResourceLoader
{
	public:
		static ResourceLoader* Instance()
		{
			if (instance == 0)
			{
				instance = new ResourceLoader();
				return instance;
			}
			return instance;
		}

		/*add a texture from a file and get a reference through the id*/
		void LoadTexture(const std::string& name, const std::string &filename);
		sf::Texture& getTexRef(const std::string& texture);

		/*add a sound buffer from a file and get a reference through the id*/
		void LoadBuffer(const std::string& name, const std::string &filename);
		sf::SoundBuffer& getBufferRef(const std::string& texture);

		/*add a font from a file and get a reference through the id/change font properties*/
		void LoadFont(const std::string& name, const std::string &filename);
		sf::Font& getFontRef(const string& texture);
		void SetFontProperties(string font, sf::Text& text, string txt, int posX, int posY, int charSize, sf::Color color, bool setOrigin);
		void UpdateText(sf::Text& text, const char* cstr, sf::Color color, bool setOrigin);

		void EmptyMaps();

	private:
		ResourceLoader();
		~ResourceLoader();

		static ResourceLoader* instance;

		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::SoundBuffer> buffers;
		std::map<std::string, sf::Font> fonts;

};

typedef ResourceLoader ResourceLoader;

#endif
