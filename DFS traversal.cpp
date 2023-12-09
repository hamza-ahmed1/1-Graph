#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<stack>
using namespace std;

class Graph {
private:
    const int vertices;
    vector<int> *adj;

    vector<int> bfs;
    vector<int>dfs;
    int* visited = new int[vertices] { 0 };
    

public:
    Graph(int v):vertices(v+1) {
        adj = new vector<int>[v+1];

     }

    void add_edge(int from, int to)
    {
        adj[from].push_back(to); //add item to ith list index
        adj[to].push_back(from);//because this is undirectional graph so a---b means b--a
    }
    void print()
    {
        for (int i = 1; i < vertices; i++)
        {
            cout << i << "    : ";
            cout << "{ ";
            for (const auto& p : adj[i]) {
                cout << p << ",";
            }
            cout << " }";
            cout << endl;
        }
    }
      
    void BFS_traversal()
    {
       
        queue<int> q;
        q.push(1);//we are starting from vertex 1 
        visited[1]=1; // mark that vertex as visited


        //print list from queue's front
       
        while (!q.empty())//run until queue become empty  
        {
        int top = q.front();
        q.pop();
        bfs.push_back(top);
            //traverse that top list all element and push to queue if not visited
        for  (auto it:adj[top])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }

        }

        for (const auto& p : bfs) {
            cout << p << ",";
        }

    }

    void DFS(int node)
    {

        stack<int> q;
        q.push(1);//we are starting from vertex 1 
        visited[1] = 1; // mark that vertex as visited


        //print list from queue's front

        while (!q.empty())//run until queue become empty  
        {
            int top = q.top();
            q.pop();
            bfs.push_back(top);
            //traverse that top list all element and push to queue if not visited
            for (auto it : adj[top])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }

        }

        for (const auto& p : bfs) {
            cout << p << ",";
        }

      
       

    }

    //another way for DFS :
    /*
       void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
    */
    //void print1()
    //{
    //    for (const auto& p : dfs)
    //    {
    //        cout << p << "    ";
    //    }
    //}

        
    
};

int main() {
  
    Graph g(5);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(3, 2);
    g.add_edge(4, 1);
    g.add_edge(5, 2);
    g.print();

    g.DFS(1);
    //g.print1();
    return 0;
}

