class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Put each (position, speed) pair in a vector and sort it, as a first step
        std::vector<std::pair<int, int>> positionAndSpeed;
        for (int i = 0; i < position.size(); ++i) {
            positionAndSpeed.push_back(std::make_pair(position[i], speed[i]));
        }
        std::sort(positionAndSpeed.begin(), positionAndSpeed.end());

        // Find the time for the car closest to the target to reach it
        double prevTime = static_cast<double>(target - positionAndSpeed.back().first) / positionAndSpeed.back().second;
        positionAndSpeed.pop_back();
        int fleets = 1;
        // Iterate through the position-sorted array from back to front
        while (!positionAndSpeed.empty()) {
            // If the next car would reach the target before this one, then they must meet and become part of a fleet
            // If the next car reaches the target after the current fleet, then it's the head of the next fleet
            double currentTime = static_cast<double>(target - positionAndSpeed.back().first) / positionAndSpeed.back().second;
            if (currentTime > prevTime) {
                fleets++;
                prevTime = currentTime;
            }
            positionAndSpeed.pop_back();
        }
        return fleets;
    }
};
