#include "ShortestPath.h"
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
#include<list>
using namespace std;
void ShortestPath::Add_Graph(int num_nodes, int num_edges) {
    vector<vector<pair<int, int>>> dij(num_nodes + 1);
    string city;
    int num = 1;
    int u, v, c;// from to distance
    for (int i = 0; i < num_edges; i++) {
        cin >> city;
        if (cityName[city] < 1) {
            cityName[city] = num;
            numcity[num] = city;
            num++;
        }
        u = cityName[city];
        cin >> city;
        if (cityName[city] < 1) {
            cityName[city] = num;
            numcity[num] = city;
            num++;
        }
        cin >> c;
        v = cityName[city];
        dij[u].push_back({ v, c });
        dij[v].push_back({ u, c });
    }
}
void ShortestPath::Update_Graph_using_dijkstra(int current_node_source, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, 1000005), previous_sourse(n, -1);
    dist[current_node_source] = 0;
    previous_sourse[current_node_source] = current_node_source;
    priority_queue<pair<int, int>> next;
    next.push({ 0, current_node_source });
    while (!next.empty()) {
        int u = next.top().second;
        next.pop();
        if (isvisited[u])
            continue;
        isvisited[u] = 1;
        int mn = 1e9, res = -1;
        for (auto child : graph[u]) {
            int v = child.first;  // name city
            int c = child.second; // distance
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                previous_sourse[v] = u;
                next.push({ -dist[v], v });
            }
        }
    }

    cout << "=================================" << endl;

    cout << "DISTANCE FROM " << numcity[x] << " TO " << numcity[y] << " IS "
        << " ==> "
        << "[ " << dist[y] << " KM "
        << "]" << endl;
    cout << "=================================" << endl;
    cout << " AND THE PREVIOUS CITY IS : [" << numcity[previous_sourse[y]] << "]"
        << endl;
    int curNode = y;
    while (true) {
        path.push_back(curNode);
        if (curNode == x) {
            break;
        }
        curNode = previous_sourse[curNode];
    }

    cout << "=================================" << endl;
    cout << "THE PATH FROM " << numcity[x] << " TO " << numcity[y] << " IS : [";

    for (int i = path.size() - 1; i >= 0; i--) {
        if (i == 0) {
            cout << path[i] << " : " << numcity[path[i]] << "";
        }
        else {
            cout << path[i] << " : " << numcity[path[i]] << "   ";
        }
    }
    cout << "]" << endl;
}
void ShortestPath::Results(vector<vector<pair<int, int>>>& dij) {
    string from_city, to_city;
    cout << "Where are you now : ";
    cin >> from_city;
    x = cityName[from_city];
    cout << "Where are you want to go : ";
    cin >> to_city;
    y = cityName[to_city];
    Update_Graph_using_dijkstra(cityName[from_city], dij);
}
void ShortestPath::Delete_Graph(vector<vector<pair<int, int>>>& graph) {
    graph.clear();
}