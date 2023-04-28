#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class saving
{
public:
	map<string, int>cityName;
	map<string, int>Namenum;
	map<int, string> citys;
	int index = 1;
	void write_graph(string number, map<string, vector<pair<long long, string>>>data_graph);
	void read_graph(string number, map<string, vector<pair<long long, string>>>& data_graph);
	void write_graph(int number);
	void number_grpahs();
};

