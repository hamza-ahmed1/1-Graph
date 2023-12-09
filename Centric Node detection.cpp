

#include <iostream>
using namespace std;
#define INF 999
/// <summary>
/// My Logic :
/// 1-stored all weights in V*V matrix
/// 2-Implement Floyd Warshall Algorithm To find all shortest path to all nodes from all nodes
/// 3-campare all paths sum from respective vertices
/// 4-Print That vertex which consists shortest path towards all nodes
/// </summary>

#pragma region Node class which is helper class for Graph class
class Node
{
public:
	int data;
	Node* nextnode;
	int weight;
	Node(int data,int weight)
	{
		this->weight = weight;
		this->data = data;
		nextnode = NULL;
	}
};
#pragma endregion


#pragma region Graph class for implimenting graph
class Graph
{
private:
	Node** adjacencylist;// we are storing the graph in adjacency list
	int vertices;
	
public:
	Graph(int vertices)
	{
		adjacencylist = new Node * [vertices];
		this->vertices = vertices;


		for (int i = 0; i < vertices; i++)
		{
			adjacencylist[i] = NULL;
		}



	}


#pragma region Add edge
	void Add_edge(int from,int to,int weight)
	{
		//step 1:create a new node at to
		Node* newnode = new Node(to,weight);
		//step 2:connect it with form
		newnode->nextnode = adjacencylist[from];
		//step 3:connect both
		adjacencylist[from] = newnode;
	
		//If graph is bidirectional :
			////step 1:create a new node at to
				//Node* newnode = new Node(from, weight);
			////step 2:connect it with form
				//newnode->nextnode = adjacencylist[to];
			////step 3:connect both
				//adjacencylist[to] = newnode;
	}
#pragma endregion





#pragma region Print Adjacency List:
	void Print_AL()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << "Vertex " << i << " connected to :";
			Node* cur = adjacencylist[i];
			while (cur!=NULL)
			{
				cout << " (" << cur->data << ", " << cur->weight << ")" << "   ,  ";
				cur = cur->nextnode;
			}
			cout << endl;
		}
	}
#pragma endregion



#pragma region Floyd Warshall Algorithm To find all shortest path to all nodes from all nodes : 
	void  Floyd_Warshall_Algorithm() {
		int** weighted_graph;
		weighted_graph= new int*[vertices];
	//	1 - stored all weights in V * V matrix
		for (int i = 0; i < vertices; ++i) {
			weighted_graph[i] = new int[vertices] {INF, INF, INF, INF, INF};
			weighted_graph[i][i] = 0;
			Node* cur = adjacencylist[i];
				while (cur)
				{
				
					weighted_graph[i][cur->data] = cur->weight;
					cur = cur->nextnode;

				}
		}
		/// 2-Implement Floyd Warshall Algorithm To find all shortest path to all nodes from all nodes
		for (int via = 0; via < vertices; via++)
		{
			for (int i = 0; i < vertices; i++)
			{
				for (int j = 0; j < vertices; j++)
				{
					weighted_graph[i][j] = min(weighted_graph[i][j], weighted_graph[i][via] + weighted_graph[via][j]);
				}
			}
		}
		/// 3-campare all paths sum from respective vertices
		int* sum_of_all_paths = new int[vertices] {0, 0, 0, 0};
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				sum_of_all_paths[i] += weighted_graph[i][j];
			}
		}

		cout << endl;
		cout << endl;

		int min = INF;
		int node = 0;
		for (int i = 0; i < vertices; i++)
		{
			cout << "Path from vertex " << i << " To all remaining nodes is   : ";
			if (sum_of_all_paths[i] < min)
			{
				min = sum_of_all_paths[i];
				node = i;
			}
			cout << sum_of_all_paths[i] << "    " << endl;
		}
		cout << endl;
		cout << endl;
		/// 4-Print That vertex which consists shortest path towards all nodes
		cout << "Central node :" << node << " with distance of :" << min << endl;
		
	}
#pragma endregion
};
#pragma endregion




//Driver Program
int main()
{
	Graph g1(4);
	g1.Add_edge(0,3,5);
	g1.Add_edge(0,1,3);
	g1.Add_edge(1,0,2);
	g1.Add_edge(1, 3, 4);
	g1.Add_edge(3, 2, 2);
	g1.Add_edge(2, 1, 1);

	g1.Print_AL(); //simple priting 
	g1.Floyd_Warshall_Algorithm(); //this will print that vertex which has shortest path towards all nodes(means center node) 
}



