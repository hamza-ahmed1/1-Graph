

#include <iostream>
using namespace std;
#define INF 999




struct dataset
{
	int weight;
	int vertex;
};

class Min_Heap
{
	dataset* arr;
	int size;
	int cur_size = 0;
public:
	Min_Heap(int size)
	{
		this->size = size;
		arr = new dataset[size];
		arr[0].weight = -1;
	}

	//insertion :
	void insert(int weight,int vertex)
	{
		cur_size = cur_size + 1;
		int index = cur_size;
		arr[cur_size].weight = weight;
		arr[cur_size].vertex = vertex;

		//Heapification:
		while (index>1)//until i found you means parent index!
		{
			int parent = index / 2;
			if (arr[parent].weight > arr[index].weight)//cheak if parent's weight < child's weight if not then swap
			{
				swap(arr[parent], arr[index]);
				index = parent;//jump upward
			}
			else
			{
				return; //if parent's weight < child's weight if not then return 
			}
		}

	}
	//get top element:
	dataset get_top()
	{
		if (cur_size == 0)
		{
			return { -1, -1 };
		}
		if (cur_size > 1)
		{
			
			
			dataset top_element = arr[1];//save top element as min
			arr[1] = arr[cur_size];//change that element with last one
			--cur_size;// dec original size
			int index = 1;
			while (index < cur_size)
			{
				int l = 2 * index;
				int r = 2 * index + 1;

				if (l<cur_size && arr[l].weight < arr[index].weight)
				{
					swap(arr[l], arr[index]);
					index = l;
				}
				else if (r < cur_size && arr[r].weight < arr[index].weight)
				{
					swap(arr[r], arr[index]);
					index = r;
				}
				else
				{
					return top_element;
				}


			}
			return top_element;
		}
	}
	void Heapify(int i)
	{
		int size1 = size;
		int smallest = i;
		int l = 2 * i +1;
		int r = 2 * i;
		if (l < size1 && arr[l].weight < arr[smallest].weight)
			smallest = l;
		if (r < size1 && arr[r].weight < arr[smallest].weight)
			smallest = r;

		if (smallest != i)
		{
			swap(arr[i].weight, arr[smallest].weight);
			swap(arr[i].vertex, arr[smallest].vertex);
			Heapify(smallest);
		}
	}
	
	bool is_empty()
	{
		if (cur_size < 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void pop()
	{
		dataset a = get_top();
	}
	void Print()
	{
		for (int i = 0; i <= cur_size; i++)
		{
			cout << arr[i].weight << "      ";
		}
		cout << endl;
	}
};
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


#pragma region Using Dijkstra Algo
	void Dijkstra()
	{
		Min_Heap pq(vertices);

		int* dis = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			dis[i] = 1e9;
		}

		dis[0] = 0;//we are taking source node as 0
		pq.insert(0, 0);

		while (!pq.is_empty())
		{
			dataset top = pq.get_top();
			int distance = top.weight;
			int node = top.vertex;

			Node* cur = adjacencylist[node];
			while (cur)
			{
				int weight = cur->weight;
				int edge = cur->data;
				if (distance + weight < dis[edge])
				{
					dis[edge] = distance + weight;
					pq.insert(dis[edge], edge);
				}
				cur = cur->nextnode;
			}
		}

		cout << "Printing Distance" << endl;

		for (int  i = 0; i < vertices; i++)
		{
			cout << dis[i] << "    ";
		}
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

};
int main()
{

	Graph g1(4);
	g1.Add_edge(0, 3, 5);
	g1.Add_edge(0, 1, 3);
	g1.Add_edge(1, 0, 2);
	g1.Add_edge(1, 3, 4);
	g1.Add_edge(3, 2, 2);
	g1.Add_edge(2, 1, 1);

	g1.Print_AL(); //simple priting 
	g1.Dijkstra();

	//Min_Heap m(5);
	//m.insert(2, 1);
	//m.insert(5, 2);
	//m.insert(3, 1);
	//m.insert(1, 1);

	//m.Print();

	//dataset a = m.get_top();
	//cout << "weight :" << a.weight << endl;

	//m.Print();

	//dataset a1 = m.get_top();
	//cout << "weight :" << a1.weight << endl;

	//m.Print();

	return 0;
}






//
//
//
//
//#pragma region Node class which is helper class for Graph class
//class Node
//{
//public:
//	int data;
//	Node* nextnode;
//	int weight;
//	Node(int data,int weight)
//	{
//		this->weight = weight;
//		this->data = data;
//		nextnode = NULL;
//	}
//};
//#pragma endregion
//
//
//
//
//#pragma region Graph class for implimenting graph
//class Graph
//{
//private:
//	Node** adjacencylist;// we are storing the graph in adjacency list
//	int vertices;
//	
//public:
//	Graph(int vertices)
//	{
//		adjacencylist = new Node * [vertices];
//		this->vertices = vertices;
//
//
//		for (int i = 0; i < vertices; i++)
//		{
//			adjacencylist[i] = NULL;
//		}
//
//
//
//	}
//
//
//#pragma region Add edge
//	void Add_edge(int from,int to,int weight)
//	{
//		//step 1:create a new node at to
//		Node* newnode = new Node(to,weight);
//		//step 2:connect it with form
//		newnode->nextnode = adjacencylist[from];
//		//step 3:connect both
//		adjacencylist[from] = newnode;
//	
//		//If graph is bidirectional :
//			////step 1:create a new node at to
//				//Node* newnode = new Node(from, weight);
//			////step 2:connect it with form
//				//newnode->nextnode = adjacencylist[to];
//			////step 3:connect both
//				//adjacencylist[to] = newnode;
//	}
//#pragma endregion
//
//
//
//
//
//#pragma region Print Adjacency List:
//	void Print_AL()
//	{
//		for (int i = 0; i < vertices; i++)
//		{
//			cout << "Vertex " << i << " connected to :";
//			Node* cur = adjacencylist[i];
//			while (cur!=NULL)
//			{
//				cout << " (" << cur->data << ", " << cur->weight << ")" << "   ,  ";
//				cur = cur->nextnode;
//			}
//			cout << endl;
//		}
//	}
//#pragma endregion
//
//
//
//#pragma region Floyd Warshall Algorithm To find all shortest path to all nodes from all nodes : 
//	void  Floyd_Warshall_Algorithm() {
//		int** weighted_graph;
//		weighted_graph= new int*[vertices];
//	//	1 - stored all weights in V * V matrix
//		for (int i = 0; i < vertices; ++i) {
//			weighted_graph[i] = new int[vertices] {INF, INF, INF, INF, INF};
//			weighted_graph[i][i] = 0;
//			Node* cur = adjacencylist[i];
//				while (cur)
//				{
//				
//					weighted_graph[i][cur->data] = cur->weight;
//					cur = cur->nextnode;
//
//				}
//		}
//		/// 2-Implement Floyd Warshall Algorithm To find all shortest path to all nodes from all nodes
//		for (int via = 0; via < vertices; via++)
//		{
//			for (int i = 0; i < vertices; i++)
//			{
//				for (int j = 0; j < vertices; j++)
//				{
//					weighted_graph[i][j] = min(weighted_graph[i][j], weighted_graph[i][via] + weighted_graph[via][j]);
//				}
//			}
//		}
//		/// 3-campare all paths sum from respective vertices
//		int* sum_of_all_paths = new int[vertices] {0, 0, 0, 0};
//		for (int i = 0; i < vertices; i++)
//		{
//			for (int j = 0; j < vertices; j++)
//			{
//				sum_of_all_paths[i] += weighted_graph[i][j];
//			}
//		}
//
//		cout << endl;
//		cout << endl;
//
//		int min = INF;
//		int node = 0;
//		for (int i = 0; i < vertices; i++)
//		{
//			cout << "Path from vertex " << i << " To all remaining nodes is   : ";
//			if (sum_of_all_paths[i] < min)
//			{
//				min = sum_of_all_paths[i];
//				node = i;
//			}
//			cout << sum_of_all_paths[i] << "    " << endl;
//		}
//		cout << endl;
//		cout << endl;
//		/// 4-Print That vertex which consists shortest path towards all nodes
//		cout << "Central node :" << node << " with distance of :" << min << endl;
//		
//	}
//#pragma endregion
//};
//#pragma endregion
//
//
//
//
////Driver Program
//int main()
//{
//	Graph g1(4);
//	g1.Add_edge(0,3,5);
//	g1.Add_edge(0,1,3);
//	g1.Add_edge(1,0,2);
//	g1.Add_edge(1, 3, 4);
//	g1.Add_edge(3, 2, 2);
//	g1.Add_edge(2, 1, 1);
//
//	g1.Print_AL(); //simple priting 
//	g1.Floyd_Warshall_Algorithm(); //this will print that vertex which has shortest path towards all nodes(means center node) 
//}
//


