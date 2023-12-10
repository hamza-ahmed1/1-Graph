#pragma region Prims Algorithm:
	void Prims()
	{
		//Datastuctures that needed
		int* parent = new int[vertices];
		bool* mstset = new bool[vertices];
		Min_Heap pq(vertices);

		int* key = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			key[i] = 1e9;
			mstset[i] = false;	
		}
		//working:
		//start from 0 vertices:
		key[0] = 0;
		pq.insert(0,0);//(vertex,weight)

		//the MST will have V-1 vertices:
		for (int i = 0; i < vertices-1; i++)
		{
			//extract minimum key vertex from priority queue:
			int u = pq.top().vertex;
			pq.pop();
			mstset[u] = true;//means we are cheaking the vth vertex
			
			for (int v = 0; i < vertices; i++)
			{
				if (adjacencylist[u][v].weight && !mstset[v] && adjacencylist[u][v].weight < key[v])
				{
					key[v] = adjacencylist[u][v].weight;
					pq.insert(v, key[v]);
					parent[v] = u;//for tracking parent:

				}
			}
		}
		cout << endl;

		for (int i = 0; i < vertices; i++)
		{

			        cout << parent[i] << " - " << i << " \t" <<" \n";
		}
	}
#pragma endregion

