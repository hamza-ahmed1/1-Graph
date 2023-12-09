// 1-Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<vector>

class Graph
{
	 int no_of_vertices;
	vector<pair<int,int>> *arr;

public:
	Graph(int n)
	{
		no_of_vertices = n + 1;
		arr = new vector<pair<int, int>>[no_of_vertices]; // we have succefully created the list of list or adjacency list:
		
	}
	void create_edge()
	{

		cout << "Enter edge position as (from,to) format :  " << endl;
		int m;
		int n;
		cin >> m >> n;
		arr[m].push_back({ m, n });
		


	}

	void Display()
	{
		for (int i = 1; i < no_of_vertices; ++i) {
			cout << "Vertex " << i << ": ";
			for (const auto& p : arr[i]) {
				cout << "(" << p.first << ", " << p.second << ") ";
			}
			cout << endl;
		}

	}

};



int main()
{
	Graph g(5);
	g.create_edge();
	g.create_edge();
	g.Display();

}


