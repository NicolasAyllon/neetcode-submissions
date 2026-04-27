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

        // Memoize whether a prerequisite is completable in case it shows up as a prerequisite later (avoid repeated work)
        std::vector<bool> completable(numCourses, false); 

        // If any class is not completable, return false
        for (int i = 0; i < numCourses; ++i) {
            std::vector<bool> visited(numCourses, false);
            if (!dfs(graph, i, visited, completable)) {
                return false;
            }
        }
        // No courses in the graph were found to be impossible to complete.
        return true;
    }

private:
    bool dfs(const std::vector<std::vector<int>>& graph, int i, std::vector<bool>& visited, std::vector<bool>& completable) {
        // Base Cases: 
        // This node was already visited, so the course can't be completed
        if (visited[i]) return false;
        // This node was already marked completable (memoized result)
        if (completable[i]) return true;

        // Mark node visited
        visited[i] = true;

        // Recursive case: Visit all neighbors
        for (int prereq : graph[i]) {
            // If a cycle was detected, return true.
            if (!dfs(graph, prereq, visited, completable)) {
                return false;
            }
        }
        // Remove node from path, and mark this node as completable.
        visited[i] = false;
        completable[i] = true;
        return true;
    }
};
