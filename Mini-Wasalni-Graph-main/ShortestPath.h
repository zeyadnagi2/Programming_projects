#pragma once
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<sstream>
using namespace std;
class ShortestPath
{
public:
	bool isvisited[1000005];
	map<string, int> cityName;
	map<int, string> numcity;
	vector<int> path;
	int x, y;
public:
	void Add_Graph(int num_nodes, int num_edges);
	void Update_Graph_using_dijkstra(int current_node_source, vector<vector<pair<int, int>>>& graph);
	void Results(vector<vector<pair<int, int>>>& dij);
	void Delete_Graph(vector<vector<pair<int, int>>>& graph);
};

