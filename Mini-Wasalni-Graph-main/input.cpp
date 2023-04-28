#include "input.h"
#include<SFML/Graphics.hpp>
#include<string>
using namespace std;
using namespace sf;
input::input()
{
}
input::~input()
{
}
string input::inputreturn(Event event) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        return "A";
    }
    else if (Keyboard::isKeyPressed(Keyboard::B)) {

        return "B";
    }
    else if (Keyboard::isKeyPressed(Keyboard::C)) {
        return "C";
    }
    else if (Keyboard::isKeyPressed(Keyboard::D)) {
        return "D";
    }
    else if (Keyboard::isKeyPressed(Keyboard::E)) {
        return "E";
    }
    else if (Keyboard::isKeyPressed(Keyboard::F)) {
        return "F";
    }
    else if (Keyboard::isKeyPressed(Keyboard::G)) {
        return "G";
    }
    else if (Keyboard::isKeyPressed(Keyboard::H)) {
        return "H";
    }
    else if (Keyboard::isKeyPressed(Keyboard::I)) {
        return "I";
    }
    else if (Keyboard::isKeyPressed(Keyboard::J)) {
        return "J";
    }
    else if (Keyboard::isKeyPressed(Keyboard::K)) {
        return "K";
    }
    else if (Keyboard::isKeyPressed(Keyboard::L)) {
        return "L";
    }
    else if (Keyboard::isKeyPressed(Keyboard::M)) {
        return "M";
    }
    else if (Keyboard::isKeyPressed(Keyboard::N)) {
        return "N";
    }
    else if (Keyboard::isKeyPressed(Keyboard::O)) {
        return "O";
    }
    else if (Keyboard::isKeyPressed(Keyboard::P)) {
        return "P";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Q)) {
        return "Q";
    }
    else if (Keyboard::isKeyPressed(Keyboard::R)) {
        return"R";
    }
    else if (Keyboard::isKeyPressed(Keyboard::S)) {
        return "S";
    }
    else if (Keyboard::isKeyPressed(Keyboard::T)) {
        return"T";
    }
    else if (Keyboard::isKeyPressed(Keyboard::U)) {
        return "U";
    }
    else if (Keyboard::isKeyPressed(Keyboard::V)) {
        return "V";
    }
    else if (Keyboard::isKeyPressed(Keyboard::W)) {
        return "W";
    }
    else if (Keyboard::isKeyPressed(Keyboard::X)) {
        return "X";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Y)) {
        return "Y";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Z)) {
        return "Z";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        return " ";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num0)) {
        return "0";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num1)) {
        return "1";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
        return "2";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num3)) {
        return "3";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num4)) {
        return "4";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num5)) {
        return "5";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num6)) {
        return "6";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num7)) {
        return "7";
    }
    else if (Keyboard::isKeyPressed(Keyboard::Num8)) {
        return "8";

    }
    else if (Keyboard::isKeyPressed(Keyboard::Num9)) {
        return "9";
    }
}