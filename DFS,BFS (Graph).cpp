
#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    map<int, bool> visited;

public:
    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int s);
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFS(int v)
{

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator k;
    for (k = adj[v].begin(); k != adj[v].end(); ++k)
        if (!visited[*k])
            DFS(*k);
}

int main()
{

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(1, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "\nFollowing is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(3);

    return 0;
}
