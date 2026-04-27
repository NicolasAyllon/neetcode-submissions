class Solution {
public:
    // Kahn's Algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int n = numCourses; // brevity
        // Build graph representation of adjacency lists from (crs -> pre) edges
        std::vector<std::vector<int>> graph(n);
        std::vector<int> indegree(n); // count of dependencies remaining
        for (const auto& edge : prerequisites) {
            // Add directed edge (pre -> crs) from prerequisite to crs
            int crs = edge[0];
            int pre = edge[1];
            graph[pre].push_back(crs);
            indegree[crs]++;
        }
        // Create queue and add all nodes with no dependencies
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        std::vector<int> output;
        // While queue is not empty
        // Invariants: 
        // 1. all nodes 'crs' in the queue have all their prerequisites 'pre' already in output.
        //    Since 'output' is initially empty, the invariant holds.
        // 2. indegree[crs] is the number of prerequisites not yet in the output.
        while (!q.empty()) {
            // Remove node
            int pre = q.front(); q.pop();
            output.push_back(pre);

            // Now that this course is in the output, decrement prerequisite count (indegree)
            // for the courses that depended on it.
            for (int crs : graph[pre]) {
                indegree[crs]--;
                // All the prerequisites of 'crs' are already in the output, so we can add 'crs' to queue.
                if (indegree[crs] == 0) {
                    q.push(crs);
                }
            }
        }
        // The queue is empty.
        // If some nodes weren't added, the;
        if (output.size() == n) {
            return output;
        } else {
            return {};
        }
    }
};
