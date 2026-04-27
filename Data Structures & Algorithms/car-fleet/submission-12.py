class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # 1. Create an array of (position, speed) pairs/tuples and sort by position
        positionAndSpeed = [(position[i], speed[i]) for i in range(len(position))]
        positionAndSpeed.sort()
        print(positionAndSpeed) # Debugging

        # 2. calculate the time that it takes for the furthest car to get to the target
        numFleets = 0
        prevTime = -1
        for i in range(len(positionAndSpeed)-1, -1, -1):
            [carPosition, carSpeed] = positionAndSpeed[i]
            currentTime = (target - carPosition) / carSpeed

            if currentTime > prevTime:
                numFleets += 1
                prevTime = currentTime

        return numFleets