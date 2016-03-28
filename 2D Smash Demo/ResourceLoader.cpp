#include "ResourceLoader.h"

ResourceLoader* ResourceLoader::instance = NULL;

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

/*--------------Functions to load and reference textures---------------*/
void ResourceLoader::LoadTexture(const std::string& name, const std::string &filename)
{
	sf::Texture texture;	
	texture.loadFromFile(filename);

	this->textures[name] = texture; 
	return; 
}

sf::Texture& ResourceLoader::getTexRef(const std::string& texture)
{
	return this->textures.at(texture);
}
/*-----------------------------------------------------*/

/*-----------------functions to load and reference sound buffers-----------*/
void ResourceLoader::LoadBuffer(const std::string& name, const std::string &filename)
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile(filename);
	
	this->buffers[name] = buffer;
	return;
}

sf::SoundBuffer& ResourceLoader::getBufferRef(const std::string& buffer)
{
	return this->buffers.at(buffer);
}
/*-------------------------------------------------------*/


/*-----------functions for loading and managing font files------*/
void ResourceLoader::LoadFont(const std::string& name, const std::string &filename)
{
	sf::Font font;
	font.loadFromFile(filename);

	this->fonts[name] = font;
	return;
}

sf::Font& ResourceLoader::getFontRef(const std::string& font)
{
	return this->fonts.at(font);
}

void ResourceLoader::SetFontProperties(string font, sf::Text& text, string txt, int posX, int posY, int charSize, sf::Color color, bool setOrigin)
{
	text.setFont(getFontRef(font));
	text.setString(txt);
	text.setCharacterSize(charSize);
	text.setPosition(posX, posY);
	text.setColor(color);

	if (setOrigin)
		text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
}

//will update the string of the text if needed and color and will keep the text centered if specified
void ResourceLoader::UpdateText(sf::Text& text, const char* txt, sf::Color color, bool setOrigin)
{
	if (txt != NULL)
		text.setString(txt);

	if (setOrigin)
		text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);

	text.setColor(color); 
}
/*-----------------------------------------------*/