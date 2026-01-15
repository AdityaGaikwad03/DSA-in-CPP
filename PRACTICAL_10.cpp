// Experiment no.10 // Implement BFS for graph traversal.#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
int main() { // Adjacency list for the graph in the image map < char,
vector < char >> graph;
graph ['A'] = { 'B',
'E',
'D' };
graph ['B'] = { 'A',
'C' };
graph ['C'] = { 'B' };
graph ['D'] = { 'A' };
graph ['E'] = { 'A',
'F' };
graph ['F'] = { 'E',
'G',
'H' };
graph ['G'] = { 'F' };
graph ['H'] = { 'F' };
queue < char > q;
map < char,
bool > visited;
char start = 'A';
q.push(start);
visited [start] = true;
cout << "BFS Traversal starting from A: ";
while (! q.empty()) { char node = q.front();
q.pop();
cout << node << " ";
for (char neigh: graph [node]) { if (! visited [neigh]) { visited [neigh] = true;
q.push(neigh);
} } } cout << endl;
return 0;
} // BFS Traversal starting
from A: A B E D C F G H