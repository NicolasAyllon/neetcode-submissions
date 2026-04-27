class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // First build a graph where each vertex = course, and each edge = (course, prereq)
        const int n = numCourses; // for brevity
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            graph[course].push_back(prereq);
        }

        std::vector<int> result;
        std::vector<bool> in_result(n, false); // 'result' contains this node
        // For each course, do DFS to see if we can create a path of length n
        for (int i = 0; i < n; ++i) {

            // Build a path where if (crs, pre) is an edge, then "pre" comes before "crs" in the result.
            // (This is a topological ordering of courses.)
            // - Returns true if the course is completable.
            std::vector<bool> visited(n, false); // A call to dfs has visited this node.
            std::cout << "findOrder iteration " << i << '\n';
            std::cout << "findOrder visited: "; for (auto val : visited) std::cout << val << " "; std::cout << '\n';
            if (!dfs(graph, i, visited, in_result, result))
                return {};
        }
        // We iterated over all nodes (courses) and 'dfs' never returned false.
        // This means we never found a cycle in the graph, so it's possible to complete all courses.
        return result;
    }

private:
    // Performs a depth first search starting from node i, visiting all neighbors before adding
    // this node (i) to the result. 
    bool dfs(const std::vector<std::vector<int>>& graph, int i, std::vector<bool>& visited, 
             std::vector<bool>& in_result, std::vector<int>& result) {
                std::cout << "  dfs(" << i << ")" << '\n';
                std::cout << "  visited: "; for (auto val : visited) std::cout << val << " "; std::cout << '\n';
                std::cout << "  in_result: "; for (auto val : in_result) std::cout << val << " "; std::cout << '\n';
                std::cout << "  result: "; for (auto val : result) std::cout << val << " "; std::cout << '\n';
                // Base cases:
                if (visited[i]) return false;   // Already visited: we found a cycle
                if (in_result[i]) return true;  // Already in result, no need to search from this node

                // Recursive case:
                visited[i] = true;
                // Visit all prerequisites
                for (int prereq : graph[i]) {
                    if (!dfs(graph, prereq, visited, in_result, result))
                        return false;
                }
                // Unmark as visited, since we've completed DFS from this node.
                visited[i] = false;
                // Add this course to result
                result.push_back(i);
                // Mark as in_result, since course i is now in the result.
                in_result[i] = true;
                return true;
             }
};
