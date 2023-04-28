#include <math.h>
#include "Town.h"
Town::Town(int x, int y, int index)
{
	this->x = x;
	this->y = y;
	this->index = index;
	this->circle = new sf::CircleShape(8);
	circle->setFillColor(sf::Color::Black);

	circle->setOrigin(8, 8);
	circle->setPosition(x, y);
}

void Town::draw(sf::RenderWindow& window,sf::Text text)
{
	window.draw(sf::CircleShape(*circle));
	window.draw(sf::Text(text));
}

float Town::distance(Town* t)
{
	return sqrt(pow(this->x - t->x, 2) + pow(this->y - t->y, 2));
}

int Town::getX()
{
	return this->x;
}
int Town::getY()
{
	return this->y;
}

Town::~Town()
{
	delete this->circle;
}