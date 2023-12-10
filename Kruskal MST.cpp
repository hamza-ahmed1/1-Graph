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
	}

	void kruskals_mst()
	{
		// Initialize the DSU 
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the constructed MST" << endl;
		for (int i = 0; i < V; i++) {
			Node* cur = adjacencylist[i];
			while (cur != nullptr) {
				int x = i;            // Source vertex
				int y = cur->data;     // Destination vertex
				int z = cur->weight;   // Weight of the edge

				// Take this edge in MST if it does not form a cycle 
				if (s.find(x) != s.find(y)) {
					s.unite(x, y);
					ans += z;
					cout << x << " -- " << y << " == " << z << endl;
				}

				cur = cur->nextnode;
			}
		}
		cout << "Minimum Cost Spanning Tree: " << ans;
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
	g.kruskals_mst();

	return 0;
}
