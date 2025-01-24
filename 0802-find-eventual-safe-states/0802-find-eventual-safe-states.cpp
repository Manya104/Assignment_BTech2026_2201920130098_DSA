class Solution {
public:
    bool isTerminal(int source, vector<vector<int>>& graph,
                    vector<int>& outDegree, vector<bool>& visited) {
        if (visited[source]) 
            return outDegree[source] == 0;  // If already visited, return the result

        visited[source] = true;  // Mark as visited

        if (outDegree[source] == 0)  // Terminal node (no outgoing edges)
            return true;

        for (int adj : graph[source]) {
            if (!isTerminal(adj, graph, outDegree, visited))
                return false;  // If any adjacent node is not terminal, return false
        }

        outDegree[source] = 0;  // Mark node as terminal
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safeNodes;
        vector<bool> visited(n, false);
        vector<int> outDegree(n, 0);

        // Compute out-degree for each node
        for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();
        }

        for (int i = 0; i < n; i++) {
            if (isTerminal(i, graph, outDegree, visited)) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};