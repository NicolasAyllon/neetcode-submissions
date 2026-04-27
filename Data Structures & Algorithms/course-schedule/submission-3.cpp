class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph with edges (course, prereq)
        std::vector<std::vector<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            graph[course].push_back(prereq);
        }
        return !containsCycle(graph);
    }

private:
    bool containsCycle(const std::vector<std::vector<int>>& graph) {
        // For each node, perform a depth first search.
        // If we come upon a node we've seen before, then there's a cycle.
        const int n = graph.size();
        for (int i = 0; i < n; ++i) {
            std::cout << "containsCycle: node " << i << '\n';
            std::vector<bool> visited(n, false);
            std::cout << "containsCycle: dfs(" << i << ")" << '\n';
            if (dfs(graph, i, visited)) {
                return true;
            }
        }
        // DFS was run from each node, but no cycles were detected.
        return false;
    }

    bool dfs(const std::vector<std::vector<int>>& graph, int i, std::vector<bool>& visited) {
        std::cout << "dfs(" << i << ")" << '\n';
        // Base Case: This node was already visited.
        if (visited[i]) return true;
        // Mark node visited
        visited[i] = true;
        // Recursive case: Visit all neighbors
        for (int prereq : graph[i]) {
            // If a cycle was detected, return true.
            if (dfs(graph, prereq, visited)) {
                return true;
            }
        }
        // Remove node from path
        visited[i] = false;
        // No cycle was detected
        return false;
    }
};
