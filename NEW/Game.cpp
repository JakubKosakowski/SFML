#include "Game.h"

void Game::initVariable() {
	this->window = nullptr;
}

void Game::initWindow() {
	this->videomode.width = 800;
	this->videomode.height = 600;

	this->window = new sf::RenderWindow(this->videomode, "Tytul", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts() {
	if (!this->font.loadFromFile("Fonts/Minecraft.ttf")) {
		cout << "Font Error!" << endl;
		system("pause");
	}
}

void Game::initTextures() {
	if (!this->texture.loadFromFile("Textures/back.jpg")) {
		cout << "Texture Error!" << endl;
		system("pause");
	}
}

void Game::initMusic() {
	if (!this->music.openFromFile("Sounds/Background.ogg")) {
		cout << "Music Error!" << endl;
		system("pause");
	}
}

void Game::setBackground() {
	this->background.setTexture(&this->texture);
}

void Game::setText() {
	this->text.setFont(this->font);
	this->text.setString("Przykladowy tekst");
	this->text.setCharacterSize(24);
	this->text.setPosition(100.f, 200.f);
}

void Game::setBackgroundMusic() {
	this->music.setPosition(0, 1, 10);
	this->music.setPitch(2);
	this->music.setVolume(60);
	this->music.setLoop(true);
	this->music.play();
}

Game::Game() {
	this->initVariable();
	this->initWindow();
	this->initFonts();
	this->initTextures();
	this->initMusic();
	this->setBackground();
	this->setBackgroundMusic();
	this->setText();
}
Game::~Game() {
	delete this->window;
}

const bool Game::running() const {
	return this->window->isOpen();
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		if (this->ev.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::renderText(sf::RenderTarget& target) {
	target.draw(this->text);
}

void Game::renderBackground(sf::RenderTarget& back) {
	back.draw(this->background);
}

void Game::update() {
	this->pollEvents();

}

void Game::render() {
	this->window->clear();

	this->renderBackground(*this->window);
	this->renderText(*this->window);

	this->window->display();
}
