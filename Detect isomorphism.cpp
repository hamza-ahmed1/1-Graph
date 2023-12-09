

#include <iostream>
using namespace std;
#include<stack>
#include<queue>
//Program to cheak whether graphs are isomorphic or not :
class Graph
{
private:
	int** matrix;
	int edges;
	int vertices;
	friend bool Is_isomorphic(Graph G1, Graph G2);//Function that determine graphs are isomorphic ro not
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
		//int edges = 0;
		//int* deg_seq = new int[vertices] {0};

		for (int i = 0; i < vertices; i++)
		{
			cout << "Vertex " << i << " is connected to :";
			for (int j = 0; j < vertices; j++) {
				if (matrix[i][j])
				{
					cout << j << "   ";
			//		edges++;
					//deg_seq[i]++;
				}
			}
			cout << endl;
		}

		//cout << "Edges are :" << edges/2 << endl;
		cout << endl;
	/*	for (int i = 0; i < vertices; i++)
		{
			cout << deg_seq[i] << "    ";
		}*/


			

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

};

bool Is_isomorphic(Graph G1, Graph G2)
{
	// Step 1:cheak both have same vertices 
	if (G1.Get_vertices() != G2.Get_vertices())
	{
		return false;
	}
	//Step 2:cheak both have same edges
	if (G1.Get_edges() != G2.Get_edges())
	{
		return false;
	}

	//Step 3: both must have same degree sequence
	int* deg_seq1 = new int[G1.Get_vertices()] {0};
	int* deg_seq2 = new int[G2.Get_vertices()] {0};
	int size = G1.Get_vertices() > G2.Get_vertices() ? G1.Get_vertices() : G2.Get_vertices();
	int* vertex_pair = new int[size]{0};

	for (int i = 0; i < G1.Get_vertices(); i++)
	{
		
		for (int j = 0; j < G1.Get_vertices(); j++) {
			if (G1.matrix[i][j])
			{
				deg_seq1[i]++;
			

			}
		}
	}


	for (int i = 0; i < G2.Get_vertices(); i++)
	{

		for (int j = 0; j < G2.Get_vertices(); j++) {
			if (G2.matrix[i][j])
			{
				deg_seq2[i]++;
				
			}
		}
	}

	//fro every vertex of G1 degree there must be same vertex in G2 graph with same degree : means vertex_pair[i]=2 for i= 0,1,2,3..

	for (int i = 0; i < G1.Get_vertices(); i++)
	{
		int cur_ver = deg_seq1[i];
		bool found = false;
		for (int j = 0; j< G2.Get_vertices(); j++)
		{
			if (deg_seq2[j] == cur_ver)
			{
				found = true;
			}
		}
		if (found == false)
		{
			return false;
		}
	}

	return true;


	
}
int main()
{
	Graph g1(5);
	g1.Add_edge(0,1);
	g1.Add_edge(0,2);
	g1.Add_edge(0,3);
	//g.Add_edge(0, 3);
	g1.Print();



	Graph g2(5);
	g2.Add_edge(1, 0);
	g2.Add_edge(1, 2);
	g2.Add_edge(1, 3);

	g2.Print();


	if (Is_isomorphic(g1, g2))
	{
		cout << "Graphs are isomorphic" << endl;

		exit(0);
	}
	cout << "Graphs are not isomorphic" << endl;


}



