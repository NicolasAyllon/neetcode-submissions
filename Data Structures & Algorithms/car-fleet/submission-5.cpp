class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        // Make a vector containing pairs of (position, speed)
        // and then sort the cars by position.
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.begin(), cars.end());
        std::stack<std::pair<float, float>> s;
        for (const auto& car : cars)
            s.push(car);
        // Now iterate through the cars starting with the one
        int num_fleets = 0;
        while (!s.empty()) {
            const auto& [p_lead, s_lead] = s.top(); s.pop();
            float t_lead_to_target = (target - p_lead) / s_lead;

            // Pop any follower cars that catch up to this one.
            while (!s.empty()) {
                const auto& [p_follow, s_follow] = s.top();
                float t_follow_to_target = (target - p_follow) / s_follow;

                if (t_follow_to_target <= t_lead_to_target) {
                    // This car is part of the car fleet.
                    s.pop();
                } else {
                    // This car never catches up, so it's the leader of the next fleet.
                    break;
                }
            }
            num_fleets++;
        }
        return num_fleets;
    }
};
