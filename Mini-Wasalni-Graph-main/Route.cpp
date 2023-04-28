#include <iostream>
#include <algorithm>
#include "Route.h"
#include<vector>
Route::Route()
{
}
void Route::setroad(Map& map) {
	this->map = &map;
	this->townCount = map.getTownCount();
	this->order = new int[townCount];
	this->color = sf::Color::Magenta;
	for (int i = 0; i < townCount; ++i)
	{
		order[i] = i;
	}
	for (int i = 0; i < ans.size()-1; ++i)
	{
			roads.push_back(new Road(map.getTowns().at(order[ans[i]]), map.getTowns().at(order[ans[i+1]]), color));
	}
}
void Route::drawRoads(sf::RenderWindow& window)
{
	for (int i = 0; i <roads.size(); ++i)
	{
		roads.at(i)->draw(window);
	}
}

void Route::updateRoads()
{
	for (int i = 0; i < townCount - 1; ++i)
	{
		delete roads.at(i);
		roads.at(i) = new Road(map->getTowns().at(order[i]), map->getTowns().at(order[i + 1]), this->color);
	}
	delete roads.at(townCount - 1);
	roads.at(townCount - 1) = new Road(map->getTowns().at(order[townCount - 1]), map->getTowns().at(order[0]), color);
}

float Route::calcDistance()
{
	float d = 0;
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		d += map->getTowns().at(order[i])->distance(map->getTowns().at(order[i + 1]));
	}
	d += map->getTowns().at(order[ans.size() - 1])->distance(map->getTowns().at(order[0]));
	return d;
}

Route::~Route()
{
	for (unsigned int i = 0; i < roads.size(); ++i)
	{
		delete roads.at(i);
	}
}