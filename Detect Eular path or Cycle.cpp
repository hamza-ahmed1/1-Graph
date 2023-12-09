

#include <iostream>
using namespace std;

class Graph
{
private:
	int** matrix;
	int edges;
	int vertices;
	
public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		matrix = new int* [vertices];

		for (int i = 0; i < vertices; i++)
		{
			matrix[i] = new int[vertices] {0};
		}

		edges = 0;

	}


#pragma region Add edge
	void Add_edge(int from,int to)
	{
		matrix[from][to] = 1;
		matrix[to][from] = 1;
		edges++;
	}
#pragma endregion
#pragma region remove edge
	void remove_edge(int from, int to)
	{
		matrix[from][to] = 0;
		matrix[to][from] = 0;
		edges--;
	}
#pragma endregion

#pragma region Print Graph
	void Print()
	{
		

		for (int i = 0; i < vertices; i++)
		{
			cout << "Vertex " << i << " is connected to :";
			for (int j = 0; j < vertices; j++) {
				if (matrix[i][j])
				{
					cout << j << "   ";
				}
			}
			cout << endl;
		}

		cout << endl;

	}


	

#pragma endregion

	int Get_vertices()
	{
		return vertices;

	}

	int Get_edges()
	{
		return edges;
	}

#pragma region Functions that  detect Eular path or circuit
	void Has_Eularpath_OR_Eularcircuit_OR_Not_Both()
	{
		bool has_circuit = true;
		bool has_path = true;
		int odd_degrees = 0;
		//Step 1: Set degree Sequence
		int* deg_seq = new int[vertices] {0};
	
		
		

		for (int i = 0; i < vertices; i++)
		{

			for (int j = 0; j <vertices; j++) {
				if (matrix[i][j])
				{
					deg_seq[i]++;


				}
			}
		}

		//Cheak for Eular Circuit : every degree must be even :

		for (int i = 0; i < vertices; i++)
		{
			if (deg_seq[i] % 2 != 0)
			{
				has_circuit = false;
				odd_degrees++;
			}
		}
		if (odd_degrees > 2)
		{
			has_path = false;
		}

		//Printing Results:
		if (has_path && has_circuit)
		{
			cout << "Graph has both Eular circuit and Path" << endl;
		}
		else if(has_path && !has_circuit)
		{
			cout << "Graph has only Eular path" << endl;
		}
		else
		{
			cout << "Graph neither has Eular path nor has Eular circuit" << endl;
		}


	}
#pragma endregion


};


int main()
{
	Graph g1(5);
	g1.Add_edge(0,1);
	g1.Add_edge(0,2);
	g1.Add_edge(0,3);
	g1.Print();

	g1.Has_Eularpath_OR_Eularcircuit_OR_Not_Both();



	



}



