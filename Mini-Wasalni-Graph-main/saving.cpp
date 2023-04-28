#include "saving.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void saving::number_grpahs()
{
    ifstream read;
    read.open("graphs_num.txt");
    read >> index;
    read.close();
}
void saving::read_graph(string number, map<string, vector<pair<long long, string>>>& data_graph)
{
    ifstream read;
    read.open(number + ".txt");
    string data_file;
    int cnt = 0;
    while (getline(read, data_file))
    {
        int count = 0, distance = 0;
        string city1 = "", city2 = "", tmp = "";
        for (int i = 0; i < data_file.size(); i++)
        {
            if (data_file[i] == ' ' && count == 0)
            {
                city1 = tmp;
                count++;
                tmp = "";
            }
            else if (data_file[i] == ' ' && count == 1)
            {
                city2 = tmp;
                tmp = "";
                count++;
            }
            else {
                tmp += data_file[i];
            }
        }
        distance = stoi(tmp);

        data_graph[city1].push_back({ distance,city2 });
        //data_graph[city2].push_back({ distance,city1 });
        if (cityName[city1] < 1) {
            cityName[city1]++;
            citys[cnt] = city1;
            cnt++;
        }
        if (cityName[city2] < 1) {
            cityName[city2]++;
            citys[cnt] = city2;
            cnt++;
        }
    }
}
void saving::write_graph(string number, map<string, vector<pair<long long, string>>> data_graph)
{
    number_grpahs();
    ofstream read;
    read.open(number+ ".txt");
    for (auto i : data_graph) {
        for (auto j : i.second)
            read << i.first << " " << j.second << " " << j.first << endl;
    }
    index += 1;
    read.close();
    ofstream write;
    write.open("graphs_num.txt");
    write << index;
    write.close();
}