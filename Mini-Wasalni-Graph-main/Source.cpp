#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<string>
#include<sstream>
#include<iostream>
#include <vector>
#include <thread>
#include <string>
#include <math.h>
#include "Map.h"
#include "Route.h"
#include"ShortestPath.h"
#include"saving.h"
#include "Graph.h"
#include"Menu.h"
#include"Secondpage.h"
#include"input.h"
#include"Thirdpage.h"
#define ll long long
#define pi  3.141592654
#define rep(i,n) for (int i = 0;i < n;i++)
#define per(i,n) for (int i =n;i >= 0;i--)
#define sor(vec) sort(vec.begin(),vec.end());
#define txt_input freopen("input.txt", "r", stdin);
#define txt_output freopen("output.txt", "w", stdout)

ll mod = 1000000007;
bool thirdcheck = false;
using namespace std;
//map<string, vector<pair<ll, string>>>bfs_short; // name country and distance 

using namespace std;
using namespace sf;
Text text;
int distnce;
bool isvisited[1000005];
map<string, int> cityName;
map<int, string> numcity;
vector<int> path, ansr;
map < string, vector<pair<ll, string>>>Data_graph;
map<int, string>res;
int x, y;
int main() {
	Font font;
	SoundBuffer welcome,con;
	welcome.loadFromFile("test2.wav");
	con.loadFromFile("test1.wav");
	Sound sound_welcome,sound_con;
	sound_welcome.setBuffer(welcome);
	sound_con.setBuffer(con);
	font.loadFromFile("OpenSans-Regular.TTF");
	Text textscore, ID, numcity;
	numcity.setFillColor(Color::Blue);
	numcity.setCharacterSize(34);
	numcity.setStyle(Text::Bold);
	numcity.setPosition(10, 300);
	numcity.setFont(font);
	textscore.setFillColor(Color::Blue);
	textscore.setCharacterSize(34);
	textscore.setStyle(Text::Bold);
	textscore.setPosition(470, 500);
	textscore.setFont(font);
	ID.setFont(font);
	ID.setFillColor(Color::Blue);
	ID.setStyle(Text::Bold);
	ID.setCharacterSize(34);
	RenderWindow window(VideoMode(800, 890), "Mini.Wasalni");
	sound_welcome.play();
	window.setKeyRepeatEnabled(true);
	Menu menu(window.getSize().x, window.getSize().y);
	sf::Texture backgroundphoto,mapback;
	backgroundphoto.loadFromFile("images.jpg");
	mapback.loadFromFile("Map.jpg");
	Sprite sback, spritebackground,mapsprit;
	spritebackground.setTexture(backgroundphoto);
	mapsprit.setTexture(mapback);
	spritebackground.scale(1.5,2.5);
	mapsprit.scale(0.7, 1.3);
	Secondpage second(window.getSize().x, window.getSize().y);
	ThirdPage third(window.getSize().x, window.getSize().y);
	bool menuon = true, select = false, addGraph = false;
	ID.setCharacterSize(24);
	ID.setPosition(350, 500);
	Text id;
	Event eve, eveadd;
	string s="Id : ";
	input in;
	bool show = false;
	Graph graph;
	saving save;
	vector<string>ans_vec;
	map<int, string>citys;
	Graph test;
	int idgraph = -1;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					if (menuon)
						menu.MoveUp();
					else {
						if (thirdcheck) {
							third.MoveUp();
						}
						else {
							second.MoveUp();
						}
					}
					break;

				case sf::Keyboard::Down:
					if (menuon)
						menu.MoveDown();
					else
					{
						if (thirdcheck) {
							third.MoveDown();
						}
						else {
							second.MoveDown();
						}
					}
					break;

				case sf::Keyboard::Return:
					int state;
					if (menuon) {
						state = menu.GetPressedItem();
					}
					else {
						if (thirdcheck)
							state = third.GetPressedItem();
						else
							state = second.GetPressedItem();
					}
					switch (state)
					{
					case 0:
						if (menuon) {
							
							std::cout << "Add or change gragh button has been pressed" << std::endl;
							menuon = false;
						}
						else
						{
							if (thirdcheck) {
								graph.show_graph(Data_graph);
							}
							else
								std::cout << "Add gragh button has been pressed" << std::endl, addGraph = true;
						}
						break;
					case 1:
						if (menuon)
							window.close();
						else {
							if (thirdcheck) {
								graph.add_city(Data_graph);
							}
							else {
								select = true;
							}
						}
						break;
					case 2:
						if (menuon)
							window.close();
						else {
							if (thirdcheck) {
								graph.add_city(Data_graph);
							}
							else {
								menuon = true;
							}
						}
						break;
					case 3:
						graph.deleting_graph(Data_graph);
						break;
					case 4:
						graph.delete_city(Data_graph);
						break;
					case 5:
						graph.delete_edge(Data_graph);
						break;
					case 6:
						graph.update(Data_graph);
						break;
					case 7: {
						system("CLS");
						sound_con.play();
						cout << "Enter to cites to know shortest path  :   ";
						string source, destination; cin >> source >> destination;
						ans_vec.clear();
						test.Dijkstra(source, destination, Data_graph, res, ans_vec);
						string str;
						Map drawing(citys.size(), window,citys);
						Route bestroute;
						bestroute.ans = test.result;
						bestroute.setroad(drawing);
						while (true) {
							window.clear();
							window.draw(mapsprit);
							drawing.drawMap(window);
							bestroute.drawRoads(window);
							window.display();
							cin >> str;
							if (str == "exit") {
								break;
							}
						}
					}
						  break;
					case 8: {
						system("CLS");
						sound_con.play();
						cout << "Enter to cites to know shortest path  :   ";
						string source, destination; cin >> source >> destination;
						test.bfs(source, destination, Data_graph);
						string str;
						Map drawing(citys.size(), window, citys);
						Route bestroute;
						bestroute.ans = test.result;
						bestroute.setroad(drawing);
						while (true) {
							window.clear();
							window.draw(mapsprit);
							drawing.drawMap(window);
							bestroute.drawRoads(window);
							window.display();
							cin >> str;
							if (str == "exit") {
								break;
							}
						}

						break;
					}
					case 9: {
						system("CLS");
						sound_con.play();
						cout << "Enter to cites to know shortest path  :   ";
						string source, destination; cin >> source >> destination;
						test.bellman(source, destination, Data_graph);
						string str;
						Map drawing(citys.size(), window, citys);
						Route bestroute;
						bestroute.ans = test.result;
						bestroute.setroad(drawing);
						while (true) {
							window.clear();
							window.draw(mapsprit);
							drawing.drawMap(window);
							bestroute.drawRoads(window);
							window.display();
							cin >> str;
							if (str == "exit") {
								break;
							}
						}
						break;
					}
					case 10:
						string stat;
						while (true)
						{
							sound_con.play();
							system("CLS");
							cout << "Enter 1 if you want to save changes\n";
							cout << "Enter 2 if you dont want to save changes\n";
							cin >> stat;
							bool check = true;
							rep(i, stat.size())
							{
								if (stat[i] != '1' && stat[i] != '2' && stat.size() != 1)
									check = false;
							}
							if (check)
								break;
						}
						if (stat == '1')
						{
							system("CLS");
							cout << "                               saving graph successfully                                \n";
							saving save;
							save.number_grpahs();

							string str_id = to_string(save.index);
							if (s=="Id : ") {
								save.write_graph(str_id, Data_graph);
								cout << "Hamasalah" << endl;
							}
							else
								save.write_graph(s, Data_graph);
						}
						Data_graph.clear();
						window.clear();
						menuon = true;
						thirdcheck = false;
						addGraph = false;
						s = "Id : ";
						third.selectedItemIndex = 0;
						third.setcolors();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(spritebackground);
		if (menuon) {
			menu.draw(window);
		}
		else {
			if (thirdcheck) {
				third.draw(window);
			}
			else {
				second.draw(window);
				if (addGraph) {
					sound_con.play();
					Graph graph;
					test = graph;
					test.add_graph(Data_graph,citys);
					window.display();
					thirdcheck = true;
				}

				else {
					window.draw(ID);
					while (select) {
						while (window.pollEvent(eve))
						{
							if (eve.type == Event::TextEntered)
							{
								if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
									if (s.size())
										s.pop_back();
									textscore.setString(s);
									window.clear();
									window.draw(spritebackground);
									second.draw(window);
									window.draw(ID);
									window.draw(textscore);
									window.display();

								}
								else if (Keyboard::isKeyPressed(Keyboard::Enter))
								{
									reverse(s.begin(), s.end());
									rep(i, 5)s.pop_back();
									reverse(s.begin(), s.end());
									save.read_graph(s, Data_graph);
									test.city = save.citys;
									citys = save.citys;
									select = false;
									thirdcheck = true;
									break;
								}
								else {
									s += in.inputreturn(eve);
									textscore.setString(s);
									window.clear();
									window.draw(spritebackground);
									second.draw(window);
									window.draw(ID);
									window.draw(textscore);
									window.display();
								}
							}

						}

					}
				}
			}
		}
		window.display();
	}
}
/*
	3
	cairo giza 20
	giza aswan 30
	cairo aswan 130

*/