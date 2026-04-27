class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # 0. Validation
        if any([s <= 0 for s in speed]):
            raise ValueError("All speeds must be positive")
        if any([(p < 0 or p > target) for p in position]):
            raise ValueError("All positions must be between 0 and target, inclusive")

        # 1. Create an array of (position, speed) pairs/tuples and sort by position
        positionAndSpeed = [(position[i], speed[i]) for i in range(len(position))]
        positionAndSpeed.sort()
        print(positionAndSpeed) # Debugging

        # 2. Iterate through the cars from highest position (closest to target) to lowest (furthest from target)
        #    Calculate the time it takes this car to reach target, and only if its > previous one (ahead) does it form
        #    a new fleet. If this car, unobstructed, would take less time than the car ahead of it, then it catches up and becomes part of a fleet
        #    Only if a car takes strictly longer (>) to reach the target than the car ahead, does it start a new fleet.
        numFleets = 0
        prevTime = -1 # An initial time of -1 always causes the closest car (1st iteration) to start a new fleet since its time >= 0
        for i in range(len(positionAndSpeed)-1, -1, -1):
            [carPosition, carSpeed] = positionAndSpeed[i]
            currentTime = (target - carPosition) / carSpeed

            if currentTime > prevTime:
                numFleets += 1
                prevTime = currentTime

        return numFleets