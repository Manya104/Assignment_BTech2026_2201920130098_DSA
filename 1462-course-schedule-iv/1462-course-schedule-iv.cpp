class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<unordered_set<int>>& prerequisites, vector<int>& visit) {
        if (visit[node] == 1) return;
        visit[node] = 1;
        for (int neighbor : graph[node]) {
            dfs(neighbor, graph, prerequisites, visit);
            prerequisites[node].insert(neighbor);
            for (int prereq : prerequisites[neighbor]) {
                prerequisites[node].insert(prereq);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<unordered_set<int>> prereqSet(numCourses);
        for (const auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visit(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (visit[i] == 0) {
                dfs(i, graph, prereqSet, visit);
            }
        }

        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(prereqSet[query[1]].count(query[0]) > 0);
        }

        return result;
    }
};