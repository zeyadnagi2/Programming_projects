#include "Secondpage.h"

Secondpage::Secondpage(float width, float height)
{

	font.loadFromFile("OpenSans-Regular.TTF");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("Add Gragh");
	menu[0].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Choose What do you want");
	menu[1].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Return");
	menu[2].setPosition(sf::Vector2f(width / 2 - 100, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}


Secondpage::~Secondpage()
{
}

void Secondpage::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Secondpage::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Secondpage::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}