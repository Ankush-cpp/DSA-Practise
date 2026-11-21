#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1; // Currently in DFS path

        for (int neighbour : adj[node]) {

            if (visited[neighbour] == 1) {
                return false; // Cycle detected
            }

            if (visited[neighbour] == 0) {
                if (!dfs(neighbour, adj, visited)) {
                    return false;
                }
            }
        }

        visited[node] = 2; // Completely processed
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false");

    return 0;
}