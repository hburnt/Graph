/// You are given a graph of an airline network connecting cities as an adjacency list.
// Given any two cities (vertices) find the minimum number of hops needed to reach from the first city to the second.
// Note: If two cities are directly connected by an edge, the number of hops is 1
// https://www.cs.dartmouth.edu/~scot/cs10/lectures/19/19.html 

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int numHops(unordered_map<string, vector<string>>& adjList, string v1, string v2);

int main() {
	unordered_map<string, vector<string>> adjList{ {"A", {"C", "E"}},
												{"C", {"A", "I"}},
												{"I", {"C", "H", "B","D"}},
												{"H", {"I"}},
												{"D", {"I", "B", "G"}},
												{"B", {"E", "F", "G", "D", "I"}},
												{"G", {"B", "D"}},
												{"F", {"B"}},
												{"E", {"A", "B"}}
	};
	cout << "Number of hops between cities D and A is " << numHops(adjList, "D", "A") << endl; // Should be 3

	cout << "Number of hops between cities A and B is " << numHops(adjList, "A", "B") << endl; // Should be 2

	cout << "Number of hops between cities H and E is " << numHops(adjList, "H", "E") << endl; // Should be 3

	return 0;
}

// Returns the number of hops between vertices v1 and v2
int numHops(unordered_map<string, vector<string>>& aList, string v1, string v2) {
    queue<string> q;
    unordered_map<string, bool> visited;

    q.push(v1);
    visited[v1] = true;
	int hop_distance = 0;
    while (!q.empty()) {
		int levelSize = q.size();

		for (int i = 0; i < levelSize; i++) {
			string currentNode = q.front();
			q.pop();

			if (currentNode == v2) {
				return hop_distance;
			}

			for (const string& neighbor : aList[currentNode]) {
				if (!visited[neighbor]) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		hop_distance++;
    }
}
