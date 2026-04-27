class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0] * len(temperatures)
        prevDays = [] # Days waiting for a warmer day
        for i in range(len(temperatures)):
            # For any cooler days that were waiting for a warmer day, fill in the elapsed days that we waited
            while prevDays and temperatures[i] > temperatures[prevDays[-1]]:
                result[prevDays[-1]] = i - prevDays[-1]
                prevDays.pop()
            # Add this day index to the stack prevDays waiting for a warmer day
            prevDays.append(i)
        # Since we initialized the result to all zero (0) we don't need to manually fill in 0 as the result
        # for any days that are still waiting for a warmer day (that never came)
        return result