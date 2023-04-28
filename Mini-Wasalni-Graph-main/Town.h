#pragma once
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;
class Town
{
public:
	Town(int x, int y, int index);
	~Town();
	void draw(sf::RenderWindow& window,Text t);
	float distance(Town* t);
	int getX();
	int getY();
public:
	sf::Text text;
	sf::Font font;
	float PI = 3.14159265f;
	int x, y, index;
	sf::CircleShape* circle;
	string name;
};