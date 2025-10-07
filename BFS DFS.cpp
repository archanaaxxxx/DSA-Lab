#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std;
class Graph {
int V; // number of vertices 
vector<vector<int> >adj; // adjacency list
public:
Graph(int v) { 
V = v;
adj.resize(v);
}
// Add edge to the graph 
void addEdge(int u, int v) {
adj[u].push_back(v);
adj[v].push_back(u); // for undirected graph
}
// BFS traversal
void BFS(int start) {
vector<bool> visited(V, false); 
queue<int> q;
visited[start] = true; 
q.push(start);
cout << "BFS Traversal starting from node " << start << ": "; 
while (!q.empty()) {
int node = q.front(); 
q.pop();
cout << node << " ";
for (int neighbor : adj[node] )
{ 
if (!visited[neighbor]) {
visited[neighbor] = true; 
q.push(neighbor);
}
}
}
cout << endl;
}
// DFS helper function
void DFSUtil(int node, vector<bool>& visited) { 
visited[node] = true;
cout << node << " ";
for (int neighbor : adj[node]) { 
if (!visited[neighbor]) {
DFSUtil(neighbor, visited);
}
}
}
// DFS traversal
void DFS(int start) {
vector<bool> visited(V, false);
cout << "DFS Traversal starting from node " << start << ": "; 
DFSUtil(start, visited);
cout << endl;
}
};
int main() { 
int V, E;
cout << "Enter number of vertices: "; 
cin >> V;
Graph g(V);
cout << "Enter number of edges: "; 
cin >> E;
cout << "Enter " << E << " edges (u v): " << endl; 
for (int i = 0; i < E; i++) {
int u, v;
cin >> u >> v; 
g.addEdge(u, v);
}
int start;
cout << "Enter starting vertex: "; 
cin >> start;
g.BFS(start);
g.DFS(start);
return 0;
}
