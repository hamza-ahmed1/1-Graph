class Node
{
public:
	int data;       // To store the destination vertex
	int weight;     // To store the weight of the edge
	Node* nextnode; // Pointer to the next node in the linked list

	Node(int data, int weight) : data(data), weight(weight), nextnode(nullptr) {}
};

class Graph {
	Node** adjacencylist;
	int V;

public:
	Graph(int V) : V(V)
	{
		adjacencylist = new Node * [V];
		for (int i = 0; i < V; i++) {
			adjacencylist[i] = nullptr; // Initialize each list as empty
		}
	}

	// Function to add edge in a graph 
	void addEdge(int from, int to, int weight)
	{
		Node* newnode = new Node(to, weight);
		newnode->nextnode = adjacencylist[from];
		adjacencylist[from] = newnode;

		 newnode = new Node(from, weight);
		newnode->nextnode = adjacencylist[to];
		adjacencylist[to] = newnode;
	}


	bool is_cyclic(int cur, bool* visited, bool* rec_stack)
	{
		rec_stack[cur] = true;
		visited[cur] = true;

		Node *temp = adjacencylist[cur];

		while (temp!=nullptr)
		{
			if (rec_stack[temp->data])
			{
				return true;//cycle detected
			}
			else if(!visited[temp->data])
			{
				is_cyclic(temp->data, visited, rec_stack);
			}
		}
		rec_stack[cur] = false;
		 return false;  // No cycle
	}

		
};


// Driver code 
int main()
{
	Graph g(4);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);
	g.addEdge(2, 0, 6);
	g.addEdge(0, 3, 5);

	// Function call 
	//g.kruskals_mst();

	bool* visited = new bool[4] {false};
	bool* recStack = new bool[4] {false};

	cout << g.is_cyclic(0, visited, recStack);
	return 0;
}
