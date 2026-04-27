class Solution {
public:
        // Let's use depth first search (dfs) to explore all possible
        // sequences of edges (source1, dest1), (sourc2, dest2), ...
        // where we always look for the next edge with a source/start
        // at the previous edge's destination.
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Remember how many tickets/edges there are. We must use them all.
        const int num_tickets = tickets.size();
        // Create the adjacency list: map: source -> [list of destinations]
        std::map<string, vector<string>> destinations = createAdjList(tickets);
        // Call helping dfs method: We're given the first airport is JFK.
        vector<string> result = {"JFK"};
        string src = "JFK";
        dfs(destinations, src, result, num_tickets);
        return result;
    }

private:
    bool dfs(map<string, vector<string>>& adj, const string& src, vector<string>& result, const int num_tickets) {
        // Base Case:
        // We used all the tickets. A path is found.
        // Since the possibilities were explored in lexicographic order, 
        // the first result found is also the lexicographically first.
        if (result.size() == num_tickets + 1)
            return true;

        // No outgoing flights
        if (adj[src].empty()) 
            return false;
        // Explore each destination
        auto& dsts = adj[src];
        for (auto it = dsts.begin(); it != dsts.end(); ++it) {
            // Choose next airport from list of destinations
            auto next = *it;
            it = dsts.erase(it);
            result.push_back(next);
            // Recursive exploration found a solution. Return.
            if (dfs(adj, next, result, num_tickets))
                return true;
            // This choice didn't work out. Backtrack.
            result.pop_back();
            it = dsts.insert(it, next);
        }
        // No destination led to a solution.
        return false;
    }

    map<string, vector<string>> createAdjList(const vector<vector<string>>& tickets) {
        // Add each destination to the list of destinations for each source
        std::map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            string src = ticket[0];
            string dst = ticket[1];
            adj[src].push_back(dst);
        }
        // Sort each list of destinations (for lexicographic ordering)
        for (auto& [src, dsts] : adj) {
            std::sort(dsts.begin(), dsts.end());
        }
        return adj;
    }

    void printAdjList(map<string, vector<string>>& adj) {
        for (const auto& [src, dsts] : adj) {
            std::cout << src << ": ";
            for (auto dst : dsts)
                std::cout << dst << " ";
            std::cout << '\n';
        }
    }
};
