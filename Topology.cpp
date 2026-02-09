#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class Graph {
    int V;               // number of vertices
    list<int>* l;        // adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        // Correct direction: u → v
        l[u].push_back(v);
    }


    void dfs(int curr, vector<bool>&vis, stack<int>& s) {
        vis[curr] = true;

        for (int v : l[curr]) {
            if (!vis[v]) {
                dfs(v, vis, s);
            }
        }

        s.push(curr); // push after visiting children
    }

    void toposort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, s);
            }
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort Order: ";
    g.toposort();

    return 0;
}
