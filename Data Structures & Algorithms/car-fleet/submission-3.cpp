class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Let's first make (position, speed) pairs,
        const int n = position.size();
        std::vector<std::pair<float, float>> cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }

        // Then sort the cars by position,
        // and build a stack with cars nearest the end at the top.
        std::sort(cars.begin(), cars.end());
        std::stack<std::pair<float, float>> s;
        for (const auto& car : cars)
            s.push(car);


        int num_fleets = 0;
        // While the stack is not empty
        while (!s.empty()) {
            // Pop car off and look at its position and speed.
            const auto& [pos_ahead, speed_ahead] = s.top(); s.pop();
            std::cout << "\t p_a = " << pos_ahead << ", s_a = " << speed_ahead << '\n';
            // The 'ahead' car will reach the target in this time.
            float t_ahead = (target - pos_ahead) / speed_ahead;
            std::cout << "t_ahead = " << t_ahead << '\n';

            // While the previous car catches up to the one furthest ahead,
            // Pop from the stack.
            while (!s.empty()) {
                const auto& [pos_behind, speed_behind] = s.top();
                std::cout << "\t p_b = " << pos_behind << ", s_b = " << speed_behind << '\n';
                // The 'behind' car would reach the target in this time.
                float t_behind = (target - pos_behind) / speed_behind;
                std::cout << "\t t_behind = " << t_behind << '\n';
                // The 'behind' car would catch up to the 'ahead'
                // Pop it from the stack, otherwise stop.
                if (t_behind <= t_ahead)
                    s.pop();
                else
                    break;
                    
            }
            // A complete fleet of cars has reached the target
            num_fleets += 1;
        }

        return num_fleets;
    }
};
