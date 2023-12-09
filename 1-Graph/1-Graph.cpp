#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<stack>
using namespace std;
// GRAPH WITH VECTORS :
//class Graph {
//private:
//    const int vertices;
//    vector<int> *adj;
//
//    vector<int> bfs;
//    vector<int>dfs;
//    int* visited = new int[vertices] { 0 };
//    
//
//public:
//    Graph(int v):vertices(v+1) {
//        adj = new vector<int>[v+1];
//
//     }
//
//    void add_edge(int from, int to)
//    {
//        adj[from].push_back(to); //add item to ith list index
//        adj[to].push_back(from);//because this is undirectional graph so a---b means b--a
//    }
//    void print()
//    {
//        for (int i = 1; i < vertices; i++)
//        {
//            cout << i << "    : ";
//            cout << "{ ";
//            for (const auto& p : adj[i]) {
//                cout << p << ",";
//            }
//            cout << " }";
//            cout << endl;
//        }
//    }
//      
//    void BFS_traversal()
//    {
//       
//        queue<int> q;
//        q.push(1);//we are starting from vertex 1 
//        visited[1]=1; // mark that vertex as visited
//
//
//        //print list from queue's front
//       
//        while (!q.empty())//run until queue become empty  
//        {
//        int top = q.front();
//        q.pop();
//        bfs.push_back(top);
//            //traverse that top list all element and push to queue if not visited
//        for  (auto it:adj[top])
//        {
//            if (!visited[it])
//            {
//                visited[it] = 1;
//                q.push(it);
//            }
//        }
//
//        }
//
//        for (const auto& p : bfs) {
//            cout << p << ",";
//        }
//
//    }
//
//    void DFS(int node)
//    {
//
//        stack<int> q;
//        q.push(1);//we are starting from vertex 1 
//        visited[1] = 1; // mark that vertex as visited
//
//
//        //print list from queue's front
//
//        while (!q.empty())//run until queue become empty  
//        {
//            int top = q.top();
//            q.pop();
//            bfs.push_back(top);
//            //traverse that top list all element and push to queue if not visited
//            for (auto it : adj[top])
//            {
//                if (!visited[it])
//                {
//                    visited[it] = 1;
//                    q.push(it);
//                }
//            }
//
//        }
//
//        for (const auto& p : bfs) {
//            cout << p << ",";
//        }
//
//      
//       
//
//    }
//
//    //another way for DFS :
//    /*
//       void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
//        vis[node] = 1; 
//        ls.push_back(node); 
//        // traverse all its neighbours
//        for(auto it : adj[node]) {
//            // if the neighbour is not visited
//            if(!vis[it]) {
//                dfs(it, adj, vis, ls); 
//            }
//        }
//    }
//    */
//    //void print1()
//    //{
//    //    for (const auto& p : dfs)
//    //    {
//    //        cout << p << "    ";
//    //    }
//    //}
//
//        
//    
//};

#pragma region Graph with linked list

class Node
{
public:
    Node* next;
    int data;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

};

class Graph
{
public:
    Node** adjacencylist;
    int vertices;
    Graph(int size)
    {
        vertices = size;
        adjacencylist = new Node * [size];
        //set all list inti to NULL

        for (int i = 0; i < size; i++)
        {
            adjacencylist[i] = nullptr;
        }

    }


    void insert(int from, int to)
    {
        Node* newnode = new Node(to);
        newnode->next = adjacencylist[from];
        adjacencylist[from] = newnode;

        newnode = new Node(from);
        newnode->next = adjacencylist[to];
        adjacencylist[to] = newnode;
    }

    void Print()
    {
        for (int i = 0; i < vertices; ++i) {
                        cout << "Vertex " << i << " is connected to: ";
                        Node* current = adjacencylist[i];
                        while (current != nullptr) {
                           cout << current->data << " ";
                            current = current->next;
                        }
                        cout <<endl;
                    }
    }

    void BFS()
    {
        int* vis= new int[vertices] {0};

        queue<int> q;
        vis[0] = 1;//mark starting vertex as visited
        q.push(0); //pust it into queue

        while (!q.empty())
        {
            int data = q.front();
                q.pop();
            cout << data << "   "; //printing and pop out section

            
            
                Node* temp = adjacencylist[data];// get that list from list of list
                while (temp)
                {
                    int cur_val = temp->data;
                    if (vis[cur_val] != 1)// push element of the cur list into queue if they not visited yet
                    {
                        vis[cur_val] = 1;
                        q.push(cur_val);
                    }
                    temp = temp->next;
                }

            
        }
                cout << endl;

    }


    void DFS()
    {
        int* vis = new int[vertices] {0};
        stack<int> s;
        vis[0] = 1;
        s.push(0);

        while (!s.empty())
        {
            int data = s.top();
            s.pop();
            cout << data << "     ";

            Node* temp = adjacencylist[data];
            while (temp)
            {
                int cur_val = temp->data;
                if (vis[cur_val] != 1)
                {
                    vis[cur_val] = 1;
                    s.push(cur_val);
                }
                temp = temp->next;
            }
        }
        cout << endl;

    }
};
#pragma endregion


int main() {
  
    //LL l;
    //l.insert(1);
    //l.insert(2);
    //l.insert(3);
    //l.Print();

    Graph g(5);
    g.insert(0, 1);
    g.insert(4, 1);
    g.insert(2, 3);
    g.insert(1, 3);

    g.Print();

    g.BFS();
    g.DFS();

}
