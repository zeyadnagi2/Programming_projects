#pragma once
#include<SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;
class input
{
public:
	input();
	~input();
	string inputreturn(Event event);
};

