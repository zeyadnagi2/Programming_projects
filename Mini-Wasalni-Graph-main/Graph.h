#pragma once
#include <iostream>
#include <iomanip>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<string>
#include "Graph.h"
using namespace std;


class Node
{
public:

	Node* next;
	map<string, vector<pair<long long, string>>> value;

	Node();
	Node(map<string, vector<pair<long long, string>>> value);
};

class Graph
{
	int count = 0;
	Node* Head;
	Node* Tail;
public:
	map<string, int>cityName;
	map<string, int>Namenum;
	map<int, string>city;
	vector<int>result;
	int index = 0;
	void add_graph(map<string, vector<pair<long long, string>>>& bfs_short, map<int, string>&citys);
	void deleting_graph(map<string, vector<pair<long long, string>>>& bfs_short);
	void add_city(map<string, vector<pair<long long, string>>>& bfs_short);
	void delete_city(map<string, vector<pair<long long, string>>>& bfs_short);
	void delete_edge(map<string, vector<pair<long long, string>>>& bfs_short);
	void update(map<string, vector<pair<long long, string>>>& bfs_short);
	void show_graph(map<string, vector<pair<long long, string>>>& bfs_short);
	void Dijkstra(string source, string destination, map<string, vector<pair<long long, string>>>& bfs_short, map<int, string>& res, vector<string>& ans_vec);
	void bellman(string source, string destination, map<string, vector<pair<long long, string>>>& bfs_short);
	void bfs(string source, string destination, map<string, vector<pair<long long, string>>>& bfs_short);
	//void add_edge(map<string, vector<pair<string, int>>>& bfs_short);
	void choice(int id, map<string, vector<pair<long long, string>>>& bfs_short);
	void linked_list_Graph(map<string, vector<pair<long long, string>>>& bfs_short);
	Graph();
};