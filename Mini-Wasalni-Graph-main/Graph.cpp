#include<SFML/Graphics.hpp>
#include<iostream>
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
#include "Map.h"
#include "Graph.h"
#include "saving.h"
using namespace std;
using namespace sf;
#define ll long long
#define rep(i,n) for (int i = 0;i < n;i++)
Node::Node()
{
	value;
	next = 0;
}
Node::Node(map<string, vector<pair<long long, string>>> val)
{
	value = val;
	next = 0;
}
Graph::Graph() {
	Head = Tail = 0;
	count = 0;
}


void Graph::add_graph(map<string, vector<pair<long long, string>>>& bfs_short,map<int,string>&citys)
{
	//< pair<string, pair<string, int>>> data_file;
	string direct;
	while (true)
	{
		system("CLS");
		cout << "Enter 1 if the graph is directed \n";
		cout << "Enter 2 if the graph is undirected \n";
		cin >> direct;
		bool check = true;
		rep(i, direct.size())
		{
			if (direct[i] != '1' && direct[i] != '2' && direct.size() != 1)
				check = false;
		}
		if (check)
			break;
	}
	string str_n;
	while (true)
	{
		system("CLS");
		cout << "please Enter number of cites  :   ";
		cin >> str_n;
		bool check = true;
		rep(i, str_n.size())
		{
			if (str_n[i] < '0' || str_n[i] > '9')
				check = false;
		}
		if (check)
			break;
	}
	int n = stoi(str_n);
	int cnt = 0;
	cout << endl;
	rep(i, n) {
		string name_city1, name_city2; int distance;
		cout << "Enter name two cities     :  "; cin >> name_city1 >> name_city2;
		if (cityName[name_city1] < 1) {
			cityName[name_city1]++;
			citys[cnt] = name_city1;
			cnt++;
		}
		if (cityName[name_city2] < 1) {
			cityName[name_city2]++;
			citys[cnt] = name_city2;
			cnt++;
		}
		cout << "Enter distance between two city    "; cin >> distance;
		//data_file.push_back({ name_city1,{name_city2,distance} });
		bfs_short[name_city1].push_back({ distance, name_city2 });
		if (direct == "2")
			bfs_short[name_city2].push_back({ distance , name_city1 });
	}
	city = citys;
	Namenum.clear();
	saving save;
	save.number_grpahs();
	string sb = to_string(save.index);
	save.write_graph(sb, bfs_short);
	//linked_list_Graph(bfs_short);
}


void Graph::add_city(map<string, vector<pair<ll, string>>>& bfs_short)
{
	cout << endl;
	string name_city1, name_city2; int distance;
	cout << "Enter name two cities     :  "; cin >> name_city1 >> name_city2;
	cout << "Enter distance between two city    "; cin >> distance;
	bfs_short[name_city1].push_back({ distance , name_city2 });
	bfs_short[name_city2].push_back({ distance , name_city1 });
}

void Graph::choice(int id, map<string, vector<pair<long long, string>>>& bfs_short)
{
	while (true) {
		cout << "Enter 1 to display graph \n";
		cout << "Enter 2 to Add city \n";
		cout << "Enter 3 to Add Edge \n";
		cout << "Enter 4 to Delete Graph \n";
		cout << "Enter 5 to Delete City \n";
		cout << "Enter 6 to Delete Edge \n";
		cout << "Enter 7 to update distance betwean two Edges \n";
		cout << "Enter 8 to get shortest distance betwean two cities (Dijkstra) \n";
		cout << "Enter 9 to get shortest path betwean two cities (bfs) \n";
		cout << "Enter 10 to get shortest path betwean two cities (bellman) \n";
		cout << "Enter 11 to Exit \n";
		int number; cin >> number;
		index = id;
		if (number == 1)
		{
			show_graph(bfs_short);
		}
		else if (number == 2 || number == 3)
		{
			add_city(bfs_short);
		}
		else if (number == 4)
		{
			deleting_graph(bfs_short);
		}
		else if (number == 5)
		{
			delete_city(bfs_short);
		}
		else if (number == 6) {
			delete_edge(bfs_short);
		}
		else if (number == 7)
		{
			update(bfs_short);
		}
		else if (number == 8)
		{
			system("CLS");
			cout << "Enter to cites to know shortest path  :   ";
			string source, destination; cin >> source >> destination;
			//Dijkstra(source, destination, bfs_short);
		}
		else if (number == 9)
		{
			system("CLS");
			cout << "Enter to cites to know shortest path  :   ";
			string source, destination; cin >> source >> destination;
			bfs(source, destination, bfs_short);
		}
		else if (number == 10)
		{
			system("CLS");
			cout << "Enter to cites to know shortest path  :   ";
			string source, destination; cin >> source >> destination;
			bellman(source, destination, bfs_short);
		}
		else if (number == 11)
		{
			cout << "Enter 1 if you want to save changes\n";
			cout << "Enter 2 if you dont want to save changes\n";
			int state; cin >> state;
			if (state == 1)
			{
				saving save;
				string sa = to_string(id);
				save.write_graph(sa, bfs_short);
			}
			bfs_short.clear();
			break;
		}
	}
}

void Graph::update(map<string, vector<pair<long long, string>>>& bfs_short)
{
	cout << "Enter name two cites you want to update distance betwean them \n";
	string city1, city2; cin >> city1 >> city2;

	cout << "Enter distance to update distance \n";
	int distance; cin >> distance;
	for (int i = 0; i < bfs_short[city1].size(); i++)
	{
		if (bfs_short[city1][i].second == city2)
			bfs_short[city2][i].first = distance;
	}
	for (int i = 0; i < bfs_short[city2].size(); i++)
		if (bfs_short[city2][i].second == city1)
			bfs_short[city1][i].first = distance;


}
void Graph::deleting_graph(map<string, vector<pair<long long, string>>>& bfs_short)
{
	for (auto i : bfs_short)
	{
		bfs_short[i.first].clear();
	}
}
void Graph::delete_city(map<string, vector<pair<long long, string>>>& bfs_short)
{
	cout << "Enter namce city you want to delete\n";

	string delete_city; cin >> delete_city;

	for (auto j : bfs_short[delete_city])
	{
		string city2 = delete_city, city1 = j.second;
		int index1 = -1, size = 0;
		for (auto i : bfs_short[city1])
		{
			if (i.second == city2) {
				index1 = size;
				break;
			}

			size++;
		}
		if(index==-1)
			bfs_short[city1].erase(bfs_short[city1].begin() + index1, bfs_short[city1].begin() + index1 + 1);

	}
	bfs_short[delete_city].clear();
}
void Graph::delete_edge(map<string, vector<pair<long long, string>>>& bfs_short)
{
	cout << "Enter to citeies you want to delete edge betwean them \n";
	string city1, city2; cin >> city1 >> city2;
	int index1 = -1, size = 0;
	for (auto i : bfs_short[city1])
	{
		if (i.second == city2) {
			index1 = size;
			break;
		}

		size++;
	}
	if(index==-1)
		bfs_short[city1].erase(bfs_short[city1].begin() + index1, bfs_short[city1].begin() + index1 + 1);
	index1 = -1, size = 0;
	for (auto i : bfs_short[city2])
	{
		if (i.second == city1) {
			index1 = size;
			break;
		}

		size++;
	}
	if (index == -1)
		bfs_short[city2].erase(bfs_short[city2].begin() + index1, bfs_short[city2].begin() + index1 + 1);
}
void Graph::show_graph(map<string, vector<pair<ll, string>>>& bfs_short)
{
	for (auto i : bfs_short)
	{
		for (auto j : i.second)
		{
			cout << " city  " << setw(5) << i.first << setw(5) << "  have route with   " << setw(5) << j.second << setw(5) << ", distance betwean them  " << setw(5) << j.first << endl;
		}
	}
}
void Graph::Dijkstra(string source, string destination, map<string, vector<pair<ll, string>>>& bfs_short, map<int, string>& res, vector<string>& ans_vec) {
	map<string, ll> dis;
	map<string, string>parent;
	for (auto i : bfs_short)
		dis[i.first] = INT64_MAX;

	dis[source] = 0;
	priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<>> pq;
	pq.emplace(0, source);

	while (pq.size())
	{
		ll route = pq.top().first;
		string to = pq.top().second;
		pq.pop();

		if (route > dis[to])continue;
		for (auto i : bfs_short[to])
		{
			ll new_route = i.first + route;
			string new_to = i.second;

			if (new_route < dis[new_to])
			{
				pq.emplace(new_route, new_to);
				dis[new_to] = new_route;
				parent[new_to] = to;
			}
		}
	}
	stack<string>ans;
	string current = destination;
	while (parent[current].size() != 0)
	{
		ans.push(current);
		current = parent[current];
	}
	int counter = 0;
	ans.push(source);
	Namenum.clear();
	for (int i = 0; i < city.size(); i++) {
		Namenum[city[i]] = i;
		cout << Namenum[city[i]] << endl;
	}
	cout << "Distance is >> " << dis[destination] << endl;
	while (ans.size())
	{
		res[counter++] = ans.top();
		result.push_back(Namenum[ans.top()]);
		cout << result[result.size() - 1]<<" ";
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << endl;


}


void Graph::bfs(string source, string destination, map<string, vector<pair<ll, string>>>& bfs_short) {
	map<string, int> vis, level;
	map<string, string>parent;
	vector<pair<ll, string>>res;
	bool found = false;

	queue<string>q;
	q.push(source);
	vis[source] = 1;
	while (q.size())
	{
		string front = q.front();
		for (auto i : bfs_short[front])
		{
			if (!vis[i.second]) {
				vis[i.second]++;
				level[i.second] = level[front] + 1;
				if (i.second == destination)
				{
					res.push_back(i);
					found = true;
					break;
				}
				q.push(i.second);
			}
		}
		if (found)break;
		q.pop();
	}

	string test = destination;
	while (test != source) {
		for (auto i : bfs_short[test])
		{
			if (level[test] == level[i.second] + 1)
			{
				res.push_back(i);
				test = i.second;
				break;
			}
		}
	}
	for (int i = 0; i < city.size(); i++) {
		Namenum[city[i]] = i;
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		result.push_back(Namenum[res[i].second]);
		cout << res[i].second << " ";
		cout << result[result.size() - 1] << " ";
	}
	cout << endl;

}
void Graph::bellman(string source, string destination, map<string, vector<pair<ll, string>>>& bfs_short)
{
	map<string, ll> dis;
	map<string, string>parent;
	for (auto i : bfs_short)
		dis[i.first] = INT64_MAX;

	dis[source] = 0;
	for (int i = 0; i < bfs_short.size() - 1; i++)
	{
		bool check = false;
		for (auto i : bfs_short)
		{
			for (auto j : i.second)
			{
				string source = i.first;
				string distination = j.second;
				int distance = j.first;
				if (dis[source] != INT64_MAX && dis[source] + distance < dis[distination])
				{
					dis[distination] = dis[source] + distance;
					parent[distination] = source;
					check = true;
				}
			}
		}
		if (!check)break;
	}
	for (auto i : bfs_short)
	{
		for (auto j : i.second)
		{
			string source = i.first;
			string distination = j.second;
			int distance = j.first;

			if (dis[source] != INT64_MAX && dis[source] + distance < dis[distination])
			{
				cout << "Sorry the graph have -ve edge cycle\n";
			}
		}
	}

	stack<string>ans;
	string current = destination;
	while (parent[current].size() != 0)
	{
		ans.push(current);
		current = parent[current];
	}
	ans.push(source);
	for (int i = 0; i < city.size(); i++) {
		Namenum[city[i]] = i;
	}
	while (ans.size())
	{
		result.push_back(Namenum[ans.top()]);
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << endl;

}


void Graph::linked_list_Graph(map<string, vector<pair<long long, string>>>& bfs_short) {
	Node* newNode = new Node(bfs_short);
	if (Head == 0)
		Head = Tail = newNode;
	else
	{
		Tail->next = newNode;
		Tail = newNode;
	}
	count++;
}