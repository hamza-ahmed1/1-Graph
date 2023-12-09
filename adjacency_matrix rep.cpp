// 1-Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Graph
{
	int no_of_verties;
	int **arr;//thats why space complexcity is n2

public:
	Graph(int n)
	{
		no_of_verties = n + 1;
		arr = new int* [no_of_verties];
		for (int i = 0; i < no_of_verties; i++)
		{
			arr[i] = new int[no_of_verties] {0};
		}
	}
	void create_edge()
	{

		cout << "Enter edge position as (from,to) format :  " << endl;
		int m;
		int n;
		cin >> m>> n;
		arr[m][n] = 1;


	}

	void Display()
	{
		for (int i = 1; i < no_of_verties; i++)
		{
			for (int j = 1; j < no_of_verties; j++) {
				cout << arr[i][j] << "    ";
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


