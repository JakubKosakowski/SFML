#pragma once

#ifndef Game_H
#define Game_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode videomode;

	sf::Event ev;

	sf::Text text;
	sf::Font font;
	sf::Texture texture;
	sf::Music music;
	sf::RectangleShape background;

	bool endgame;

	void initVariable();
	void initWindow();
	void initTextures();
	void initFonts();
	void initMusic();
	void setBackground();
	void setText();
	void setBackgroundMusic();

public:
	Game();
	~Game();

	const bool running() const;

	void pollEvents();
	void renderText(sf::RenderTarget &target);
	void renderBackground(sf::RenderTarget& target);
	void update();
	void render();
};

#include "Game.cpp"

#endif
