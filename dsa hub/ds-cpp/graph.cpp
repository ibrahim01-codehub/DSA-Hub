// ============================================
// GRAPH - vertices (nodes) connected by edges
// Think of a map: cities are vertices, roads are edges.
// Stored here as an "adjacency list": each vertex keeps a list
// of the vertices it's directly connected to.
// ============================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int vertexCount;
    vector<vector<int>> adjacencyList;

public:
    Graph(int n) : vertexCount(n), adjacencyList(n) {}

    // ---- Add an undirected edge - O(1) ----
    // Undirected means the connection works both ways.
    void addEdge(int a, int b) {
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    // ---- Breadth-First Search (BFS) - O(V + E) ----
    // Explores the graph one "layer" at a time, like ripples
    // spreading out from a stone dropped in water.
    void bfs(int start) {
        vector<bool> visited(vertexCount, false);
        queue<int> toVisit;

        visited[start] = true;
        toVisit.push(start);

        cout << "BFS starting from vertex " << start << ": ";
        while (!toVisit.empty()) {
            int current = toVisit.front();
            toVisit.pop();
            cout << current << " ";

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    toVisit.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // ---- Show direct neighbors of a vertex - O(degree of vertex) ----
    void printNeighbors(int vertex) {
        cout << "Neighbors of vertex " << vertex << ": ";
        for (int neighbor : adjacencyList[vertex]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(5); // vertices numbered 0 to 4

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printNeighbors(0);
    g.bfs(0);

    return 0;
}
