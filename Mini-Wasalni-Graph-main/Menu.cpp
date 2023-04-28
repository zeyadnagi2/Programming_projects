#include "Menu.h"


Menu::Menu(float width, float height)
{

	font.loadFromFile("OpenSans-Regular.TTF");

	menu[0].setFont(font);
	menu[0].setCharacterSize(30);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("Add or Change Gragh");
	menu[0].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.6));


	menu[1].setFont(font);
	menu[1].setCharacterSize(30);
	menu[1].setStyle(sf::Text::Bold);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.4));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS-1; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS-1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}