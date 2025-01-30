#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;
            color[i] = 0;
            if (!isBipartite(graph, i, color)) return -1;
        }
        
        vector<int> maxDepth(n);
        for (int i = 0; i < n; i++) {
            maxDepth[i] = bfsMaxDepth(graph, i, n);
        }
        
        int totalGroups = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            totalGroups += maxGroupsHelper(graph, i, maxDepth, visited);
        }
        
        return totalGroups;
    }

private:
    bool isBipartite(vector<vector<int>> &graph, int node, vector<int> &color) {
        for (int neighbor : graph[node]) {
            if (color[neighbor] == color[node]) return false;
            if (color[neighbor] != -1) continue;
            color[neighbor] = 1 - color[node];
            if (!isBipartite(graph, neighbor, color)) return false;
        }
        return true;
    }

    int bfsMaxDepth(vector<vector<int>> &graph, int start, int n) {
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
            depth++;
        }
        return depth;
    }

    int maxGroupsHelper(vector<vector<int>> &graph, int node, vector<int> &maxDepth, vector<bool> &visited) {
        int maxCount = maxDepth[node];
        visited[node] = true;
        
        for (int neighbor : graph[node]) {
            if (visited[neighbor]) continue;
            maxCount = max(maxCount, maxGroupsHelper(graph, neighbor, maxDepth, visited));
        }
        return maxCount;
    }
};
