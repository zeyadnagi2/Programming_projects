#include "ThirdPage.h"
ThirdPage::ThirdPage(float width, float height)
{

	font.loadFromFile("OpenSans-Regular.TTF");
	for (int i = 0; i < 11; i++) {
		menu[i].setFont(font);
		if (i != 0)
			menu[i].setFillColor(sf::Color::Black);
		else {
			menu[i].setFillColor(sf::Color::Blue);
		}
		menu[i].setPosition(sf::Vector2f(0, height / (MAX_NUMBER_OF_ITEMS + 1) * i));
	}
	menu[0].setString("Display graph");
	menu[1].setString("Add city");
	menu[2].setString("Add Edge");
	menu[3].setString("Delete Graph");
	menu[4].setString("Delete City");
	menu[5].setString("Delete Edge ");
	menu[6].setString("Update distance betwean two Edges");
	menu[7].setString("Get shortest distance betwean two cities (Dijkstra)");
	menu[8].setString("Get shortest path betwean two cities (bfs)");
	menu[9].setString("Get shortest path betwean two cities (bellman)");
	menu[10].setString("Return");
	menu[10].setPosition(sf::Vector2f(355, height / (MAX_NUMBER_OF_ITEMS + 1) * 10.5));
	selectedItemIndex = 0;
}

void ThirdPage::setcolors() {
	for (int i = 0; i < 11; i++) {
		menu[i].setFont(font);
		if (i != 0)
			menu[i].setFillColor(sf::Color::Black);
		else {
			menu[i].setFillColor(sf::Color::Blue);
		}
	}
}
ThirdPage::~ThirdPage()
{
}

void ThirdPage::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void ThirdPage::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void ThirdPage::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
